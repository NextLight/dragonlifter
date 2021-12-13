from lifters.instruction_lifter import InstructionLifter
from lifters.core_lifter import CoreLifter

class InstructionLifterInstructionCount(InstructionLifter):
    def generate_body(self) -> str:
        return '\n'.join((
            '++__instruction_count;',
            super().generate_body(),
        ))

class CoreLifterInstructionCount(CoreLifter):
    def setup(self):
        super().setup()
        self.c_fields.append('u64 __instruction_count = 0;')
        self.h_fields.append('extern u64 __instruction_count;')
