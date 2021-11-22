from ghidra_types import Program


class CoreLifter:
    def __init__(self, program: Program):
        self.program = program
        self._register_offset_and_size_to_name = {
            (rb.offset, r.size): r.name 
            for rb in program.registers_blocks
            for r in rb.registers}

    @property
    def varnode_type_name(self) -> str:
        return 'varnode_t'

    def register_from_offset_and_size(self, offset: int, size: int) -> str:
        return self._register_offset_and_size_to_name[(offset, size)]

    def address_label(self, address: int) -> str:
        return f'ADDR_{address:X}'

    def temp_variable(self, id: int) -> str:
        return f'temp_{id}'
