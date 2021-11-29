import typing

if typing.TYPE_CHECKING:
    from dragonlifter import Dragonlifter

from ghidra_types import *


class InstructionLifter:
    def __init__(self, lifter: "Dragonlifter", instruction: Instruction):
        self.lifter = lifter
        self.instruction = instruction
    
    def lift(self) -> str:
        return '\n'.join((
            self.generate_instruction_label(),
            self.generate_body(),
        ))

    def generate_instruction_label(self) -> str:
        return f'{self.lifter.core.instruction_label(self.instruction.address)}:; // {self.instruction.asm}'

    def generate_body(self) -> str:
        return '\n'.join(self.pcode_lines())


    def pcode_label(self, pcode_index: int) -> str:
        return self.lifter.core.pcode_label(self.instruction.address, pcode_index)

    def pcode_lines(self) -> typing.Iterable[str]:
        lines: list[str] = []
        pcode_labels: set[int] = set()
        for i, pcode in enumerate(self.instruction.pcodes):
            try:
                pcode_lifter = self.lifter.PcodeLifter(self.lifter, pcode, self.instruction.address, i)
                lines.append(pcode_lifter.lift())
                pcode_labels.update(pcode_lifter.referenced_pcode_labels)
            except NotImplementedError:
                print(f'WARNING: {pcode} not implemented.')
                lines.append(f'//NOT-IMPL: {pcode}')
        
        for i, l in enumerate(lines):
            if i in pcode_labels:
                yield f'{self.pcode_label(i)}: {l}'
            else:
                yield l