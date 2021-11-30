from enum import Enum, auto

from ghidra_types import *


class VarKind(Enum):
    UNSIGNED = auto()
    SIGNED = auto()
    FLOATING = auto()

class CoreHelper:
    def __init__(self, program: Program):
        self.program = program
        self.register_offset_and_size_to_name = {
            (rb.offset, r.size): r.name 
            for rb in program.registers_blocks
            for r in rb.registers
        }
        self.registers_from_offset = {b.offset: b.registers for b in program.registers_blocks}
        self.address_space_name_to_id = {name: id for name, id in program.address_spaces}
        self.address_to_function = {f.address: f for f in program.functions}

        self.used_registers_offset: set[int] = set()
        self.used_temp_variables: set[int] = set()

    varnode_type_name = 'varnode_t'
    address_type_name = 'address_t'
    funcptr_type_name = 'funcptr_t'
    byte_size = 8
    stack_size = 8 * 1024**2
    var_kind_to_field_suffix = {VarKind.UNSIGNED: '', VarKind.SIGNED: 's', VarKind.FLOATING: 'f'}
    available_types = {
        (VarKind.SIGNED, 1): 'i8',
        (VarKind.SIGNED, 2): 'i16',
        (VarKind.SIGNED, 4): 'i32',
        (VarKind.SIGNED, 8): 'i64',

        (VarKind.UNSIGNED, 1): 'u8',
        (VarKind.UNSIGNED, 2): 'u16',
        (VarKind.UNSIGNED, 4): 'u32',
        (VarKind.UNSIGNED, 8): 'u64',

        (VarKind.FLOATING, 4): 'f32',
        (VarKind.FLOATING, 8): 'f64',
        (VarKind.FLOATING, 10): 'f80',
    }

    @property
    def ram_address_space(self) -> int: return self.address_space_name_to_id['ram']
    
    def field_name(self, size: int, kind: VarKind) -> str:
        return f'_{size}{self.var_kind_to_field_suffix[kind]}'
    
    def register_name(self, offset: int, size: int, kind: VarKind) -> str:
        self.used_registers_offset.add(offset)
        return f'{self.register_offset_and_size_to_name[(offset, size)]}{self.var_kind_to_field_suffix[kind]}'

    def function(self, address: int) -> Function:
        return self.address_to_function[address]

    def size_and_kind_to_type(self, size: int, kind: VarKind) -> str:
        return self.available_types[(kind, size)]

    def instruction_label(self, address: int) -> str:
        return f'ADDR_{address:X}'

    def pcode_label(self, address: int, pcode_index: int) -> str:
        return f'PCODE_{address:X}_{pcode_index}'

    def temp_variable(self, id: int) -> str:
        self.used_temp_variables.add(id)
        return f'temp_{id}'
