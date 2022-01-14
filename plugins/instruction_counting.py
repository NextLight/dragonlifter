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
        self.typedefs.append('extern void * stderr;')
        self.typedefs.append('extern void fprintf(void * file, const char * format, ...);')
        self.functions.append('static void __print_instruction_count() { fprintf(stderr, "count: %llu\\n", __instruction_count); }')
