import os
import typing

from code_emitter import CodeEmitter
from ghidra_types import *

if typing.TYPE_CHECKING:
    from dragonlifter import Dragonlifter


class ProgramLifter:
    def __init__(self, lifter: "Dragonlifter", program: Program):
        self.lifter = lifter
        self.program = program

    DRAGONLIFTER_H = "dragonlifter.h"
    DRAGONLIFTER_C = "dragonlifter.c"

    def emit(self, directory: str) -> None:
        for fun in self.program.functions:
            with open(os.path.join(directory, f'{fun.name}.c'), 'w') as f:
                self.emit_function(fun, CodeEmitter(f))
        core_lifter = self.lifter.CoreLifter(self.lifter)
        with open(os.path.join(directory, self.DRAGONLIFTER_H), 'w') as f:
            CodeEmitter(f).emit(core_lifter.lift_header())
        with open(os.path.join(directory, self.DRAGONLIFTER_C), 'w') as f:
            CodeEmitter(f).emit(core_lifter.lift_c())

    def emit_function(self, fun: Function, writer: CodeEmitter) -> None:
        writer.emit(self.generate_imports())
        writer.emit('')
        writer.emit(self.lift_function(fun))

    def lift_function(self, fun: Function) -> str:
        return self.lifter.FunctionLifter(self.lifter, fun).lift()

    def generate_imports(self) -> str:
        return f'#include "{self.DRAGONLIFTER_H}"'
