import typing

if typing.TYPE_CHECKING:
    from dragonlifter import Dragonlifter

from ghidra_types import *
from .pcode_lifter import PcodeLifter


class InstructionLifter:
    def __init__(self, lifter: "Dragonlifter", instruction: Instruction, *, pcode_lifter: PcodeLifter):
        self.lifter = lifter
        self.instruction = instruction
        self.pcode_lifter = pcode_lifter
    
    def lift(self) -> str:
        return '\n'.join((
            self.generate_label(),
            self.generate_body(),
        ))

    def generate_label(self) -> str:
        return f'{self.lifter.core.address_label(self.instruction.address)}:; // {self.instruction.asm}'

    def generate_body(self) -> str:
        return '\n'.join(map(self.lift_pcode, self.instruction.pcodes))

    def lift_pcode(self, pcode: Pcode) -> str:
        try:
            return self.pcode_lifter.dispatch(pcode)
        except NotImplementedError:
            return f'//NOT-IMPL: {pcode}'
