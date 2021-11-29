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
        return f'{self.generate_signature()} {{'

    def generate_footer(self) -> str:
        return '}'

    def generate_variables_declaration(self) -> str:
        return ''
    
    def generate_body(self) -> str:
        return '\n'.join(map(self.lift_instruction, self.function.instructions))

    def generate_signature(self) -> str:
        return f'void {self.function.name}()'
    
    def lift_instruction(self, instr: Instruction) -> str:
        return self.lifter.InstructionLifter(self.lifter, instr).lift()
