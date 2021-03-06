import typing

if typing.TYPE_CHECKING:
    from dragonlifter import Dragonlifter

from ghidra_types import *


class FunctionLifter:
    def __init__(self, lifter: "Dragonlifter", function: Function):
        self.lifter = lifter
        self.function = function
    
    def lift(self) -> str:
        return '\n'.join(filter(None, (
            self.generate_header(),
            self.generate_call_to_initializer_if_needed(),
            self.generate_body(),
            self.generate_variables_declaration(),
            self.generate_footer(),
        )))

    def generate_header(self) -> str:
        return f'{self.generate_signature()} {{'

    def generate_footer(self) -> str:
        return '}'

    def generate_variables_declaration(self) -> str:
        return ''
    
    def generate_body(self) -> str:
        return '\n\n'.join((
            self.generate_labels_jumptable(),
            '\n'.join(map(self.lift_instruction, self.function.instructions)),
        ))

    def generate_signature(self) -> str:
        return f'void {self.generate_function_name()}()'

    def generate_function_name(self) -> str:
        return self.function.name

    def generate_call_to_initializer_if_needed(self) -> typing.Optional[str]:
        if self.function.name in self.lifter.core.possible_entry_points:
            return '__dragonlifter_init();'
        return None

    def generate_labels_jumptable(self) -> str:
        addresses = {i.address for i in self.function.instructions}
        min_addr = min(addresses)
        max_addr = max(addresses)
        return '\n'.join((
            f'static const void* labels[] = {{ {",".join("&&" + self.lifter.core.instruction_label(i) if i in addresses else "NULL" for i in range(min_addr, max_addr+1))} }};',
            f'static const size_t labels_base_address = {min_addr};',
        ))
    
    def lift_instruction(self, instr: Instruction) -> str:
        return self.lifter.InstructionLifter(self.lifter, instr).lift()
