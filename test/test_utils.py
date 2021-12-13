from ghidra_types import *


def dummy_program(*, functions=[], op_names=[], address_spaces=[], registers_blocks=[], memory=Memory([], '')):
    return Program(functions, op_names, address_spaces, registers_blocks, memory)
