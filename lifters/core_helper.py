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
        self.address_space_name_to_id = {name: id for name, id in program.address_spaces}

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

    def size_and_kind_to_type(self, size: int, kind: VarKind) -> str:
        return self.available_types[(kind, size)]

    def register_from_offset_and_size(self, offset: int, size: int) -> str:
        return self.register_offset_and_size_to_name[(offset, size)]

    def address_label(self, address: int) -> str:
        return f'ADDR_{address:X}'

    def temp_variable(self, id: int) -> str:
        return f'temp_{id}'
