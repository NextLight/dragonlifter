import typing
import zlib
from base64 import b64decode

if typing.TYPE_CHECKING:
    from dragonlifter import Dragonlifter

from ghidra_types import *
from .core_helper import VarKind


class CoreLifter:
    def __init__(self, lifter: "Dragonlifter"):
        self.lifter = lifter
        self.core = lifter.core

        self.h_includes: list[str] = []
        self.c_includes: list[str] = []
        self.typedefs: list[str] = []
        self.h_fields: list[str] = []
        self.c_fields: list[str] = []
        self.defines: list[str] = []
        self.functions: list[str] = []
        self.h_body: list[str] = []
        self.c_body: list[str] = []


    def lift_header(self) -> str:
        return '\n\n\n'.join(filter(None, (
            '\n'.join(self.h_includes),
            '\n'.join(self.typedefs),
            '\n'.join(self.h_fields),
            '\n'.join(self.defines),
            '\n'.join(self.functions),
            '\n'.join(self.h_body),
        )))

    def lift_c(self) -> str:
        return '\n\n\n'.join(filter(None, (
            '\n'.join(self.c_includes),
            '\n'.join(self.c_fields),
            '\n'.join(self.c_body),
        )))


    def setup(self):
        self.setup_default_types()
        self.setup_math()
        self.setup_popcount()
        self.setup_memory()
        self.setup_temp_variables()
        self.setup_registers()
        self.setup_function_declarations()
        self.setup_function_pointers()
        self.setup_callother()

    def setup_default_types(self):
        self.h_includes.append('#include <stddef.h>')
        self.h_includes.append('#include <stdint.h>')
        self.h_includes.append('#include <assert.h>')
        self.typedefs.extend((
            self.generate_generic_typedefs(),
            '',
            self.generate_address_type_typedef(),
            self.generate_function_pointer_type_typedef(),
            '',
            self.generate_varnode_type_typedef(),
        ))

    def setup_math(self):
        self.h_includes.append('#include <math.h>')
        self.defines.append(self.generate_math_defines())

    def setup_memory(self):
        mem, ram_blocks = self.parse_ram_blocks(self.core.program.memory)
        memory_blocks = [(hex(ram_blocks[i].start), f'memory + {sum(b.size for b in ram_blocks[:i])}') for i in range(len(ram_blocks))]
        memory_blocks.append((f'(address_t)-{self.core.stack_size}', 'stack'))

        self.typedefs.append('typedef struct { address_t addr; byte * ptr; } memory_block_t;')

        self.h_fields.extend((
            'extern byte memory[];',
            'extern byte stack[];',
            'extern const memory_block_t memory_blocks[];',
            'extern const size_t memory_blocks_count;',
        ))
        self.c_fields.extend((
            f'byte memory[] = {{ {",".join(str(b) for b in mem)} }};',
            f'byte stack[{self.core.stack_size}];',
            f'const memory_block_t memory_blocks[] = {{ {", ".join(f"{{{l}, {r}}}" for l, r in memory_blocks)} }};',
            'const size_t memory_blocks_count = sizeof(memory_blocks) / sizeof(memory_blocks[0]);',
        ))
        self.functions.append('''
            static inline byte * find_memory_pos(address_t addr) {
                for (size_t i = memory_blocks_count - 1; i >= 0; i--) {
                    if (memory_blocks[i].addr <= addr)
                        return (byte *)memory_blocks[i].ptr + addr - memory_blocks[i].addr;
                }
                assert(0);
            }'''
        )
        self.defines.extend((
            '#define RAM_ADDR(addr) ((varnode_t*)find_memory_pos(addr))',
            '#define RAM(addr) (*RAM_ADDR(addr))',
        ))

    def setup_popcount(self):
        self.defines.append('#define POPCOUNT(sz, v) _popcount8(v)')
        # TODO: implement for different sizes to make it more efficent
        self.functions.append('''
            static inline u8 _popcount8(u64 v) {
                u8 o = 0;
                for (; v; o++)
                    v &= v - 1;
                return o;
            }'''
        )

    def setup_temp_variables(self):
        fields = ', '.join(map(self.core.temp_variable, self.core.used_temp_variables))
        self.h_fields.append(f'extern varnode_t {fields};')
        self.c_fields.append(f'varnode_t {fields};')

    def setup_registers(self):
        max_register_off, registers_with_max_off = max(self.core.registers_from_offset.items())
        max_register_address = max_register_off + max(r.size for r in registers_with_max_off)
        self.h_fields.append(f'extern byte registers[];')
        self.c_fields.append(f'byte registers[{max_register_address}];')
        self.defines.append('')
        for off in self.core.used_registers_offset:
            for r in self.core.registers_from_offset[off]:
                for kind in VarKind:
                    self.defines.append(f'#define {self.core.register_name(off, r.size, kind)} ((varnode_t*)&registers[{off}])->{self.core.field_name(r.size, kind)}')
        self.defines.append('')

    def setup_function_declarations(self):
        self.functions.append('')
        for f in self.core.functions_to_export:
            self.functions.append(f'extern void {f.name}();')

    def setup_function_pointers(self):
        self.typedefs.append('typedef struct { address_t addr; funcptr_t func; } addr_to_func_t;')
        funs = ",".join(f"{{{f.address},{f.name}}}" for f in self.core.functions_to_export)
        self.c_fields.append(f'const addr_to_func_t functions[] = {{ {funs} }};')
        self.c_fields.append(f'const size_t functions_count = sizeof(functions) / sizeof(functions[0]);')
        self.h_fields.append(f'extern const addr_to_func_t functions[];')
        self.h_fields.append(f'extern const size_t functions_count;')
        self.functions.append('''
        static inline funcptr_t function_binary_search(const addr_to_func_t * arr, size_t size, address_t addr) {
            size_t l = 0, r = size;
            while (l < r) {
                size_t m = (l + r) / 2;
                if (arr[m].addr == addr)
                    return arr[m].func;
                else if (arr[m].addr > addr)
                    r = m;
                else
                    l = m + 1;
            }
            // assert(0);
        }''')
        self.defines.append('#define CALL_FUNCTION_AT(addr) function_binary_search(functions, functions_count, addr)()')        

    def setup_callother(self):
        self.defines.append('#define CALLOTHER(f, ...) CALLOTHER_##f(__VA_ARGS__)')


    def generate_math_defines(self) -> str:
        return '\n'.join((
            '#define SIGN(sz, v) ((v) >= 0)',
            '#define ISNAN(sz, v) isnan(v)',
            '#define FABS(sz, v) fabs(v)',
            '#define SQRT(sz, v) sqrt(v)',
            '#define CEIL(sz, v) ceil(v)',
            '#define FLOOR(sz, v) floor(v)',
            '#define ROUND(sz, v) round(v)',
        ))

    def generate_generic_typedefs(self) -> str:
        return '\n'.join((
            'typedef int8_t i8;',
            'typedef int16_t i16;',
            'typedef int32_t i32;',
            'typedef int64_t i64;',
            'typedef uint8_t u8;',
            'typedef uint16_t u16;',
            'typedef uint32_t u32;',
            'typedef uint64_t u64;',
            'typedef float f32;',
            'typedef double f64;',
            'typedef long double f80;',
            'typedef uint8_t byte;',
            'typedef __int128_t i128;',
            'typedef __uint128_t u128;',
        ))
    
    def generate_address_type_typedef(self) -> str:
        # TODO: get type size from ghidra
        return f'typedef {self.core.size_and_kind_to_type(8, VarKind.UNSIGNED)} {self.core.address_type_name};'
    
    def generate_function_pointer_type_typedef(self) -> str:
        return f'typedef void (*{self.core.funcptr_type_name})();'

    def generate_varnode_type_fields(self) -> str:
        return '\n'.join(f'{t} {self.core.field_name(size, kind)};' for (kind, size), t in self.core.available_types.items())

    def generate_varnode_type_typedef(self) -> str:
        return f'typedef union {{\n{self.generate_varnode_type_fields()}\n}} {self.core.varnode_type_name};'


    def decompress_memory(self, compressed: str) -> bytes:
        return zlib.decompress(b64decode(compressed))

    def parse_ram_blocks(self, memory: Memory, *, max_blocks_join_distance = 64) -> tuple[bytearray, list["MemoryBlock"]]:
        dec = self.decompress_memory(memory.compressed_buffer)

        blocks: list[CoreLifter.MemoryBlock] = []
        mem = bytearray()
        pos = 0
        for b in memory.blocks_info:
            if b.address_space_id == self.core.ram_address_space:
                # check if this block can be joined with the previus one
                if blocks and b.start - blocks[-1].end <= max_blocks_join_distance:
                    diff = b.start - blocks[-1].end
                    assert diff >= 0
                    mem.extend([0] * diff)
                    blocks[-1].end = b.end
                else:
                    blocks.append(self.MemoryBlock(b.start, b.end))
                mem.extend(dec[pos:pos+b.size])
            pos += b.size

        return mem, blocks

    @dataclass
    class MemoryBlock:
        start: int
        end: int
        @property
        def size(self): return self.end - self.start
