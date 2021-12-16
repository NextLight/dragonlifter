import typing

if typing.TYPE_CHECKING:
    from dragonlifter import Dragonlifter

from ghidra_types import *
from .pcode_lifter import PcodeLifter


class FunctionLifter:
    def __init__(self, lifter: "Dragonlifter", function: Function, *, pcode_lifter: PcodeLifter = None):
        self.lifter = lifter
        self.function = function
    
    def lift(self) -> str:
        return '\n'.join((
            self.generate_header(),
            self.generate_body(),
            self.generate_variables_declaration(),
            self.generate_footer(),
        ))

    def generate_header(self) -> str:
        return '\n'.join((
            f'{self.generate_signature()} {{',
            self.generate_labels_jumptable(),
        ))

    def generate_footer(self) -> str:
        return '}'

    def generate_variables_declaration(self) -> str:
        return ''
    
    def generate_body(self) -> str:
        return '\n'.join(map(self.lift_instruction, self.function.instructions))

    def generate_signature(self) -> str:
        return f'void {self.function.name}()'
    
    def generate_labels_jumptable(self) -> str:
        addresses = {i.address for i in self.function.instructions}
        min_addr = min(addresses)
        max_addr = max(addresses)
        return '\n'.join((
            f'static const void* labels[] = {{ {",".join("&&" + self.lifter.core.instruction_label(i) if i in addresses else "NULL" for i in range(min_addr, max_addr+1))} }};',
            f'static const size_t labels_base_address = {min_addr};'
        ))
    
    def lift_instruction(self, instr: Instruction) -> str:
        return self.lifter.InstructionLifter(self.lifter, instr).lift()
