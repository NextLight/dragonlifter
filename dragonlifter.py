import os
import sys
import pathlib

from ghidra_types import *
from lifters.core_helper import CoreHelper
from lifters.core_lifter import CoreLifter
from lifters.function_lifter import FunctionLifter
from lifters.instruction_lifter import InstructionLifter
from lifters.pcode_lifter import PcodeLifter
from lifters.program_lifter import ProgramLifter


class Dragonlifter:
    _EMPTY: "Dragonlifter"

    def __init__(
            self,
            program: Program,
            *, 
            CoreHelper: type[CoreHelper] = CoreHelper,
            CoreLifter: type[CoreLifter] = CoreLifter,
            ProgramLifter: type[ProgramLifter] = ProgramLifter,
            FunctionLifter: type[FunctionLifter] = FunctionLifter,
            InstructionLifter: type[InstructionLifter] = InstructionLifter,
            PcodeLifter: type[PcodeLifter] = PcodeLifter,
        ):
        self.CoreHelper = CoreHelper
        self.CoreLifter = CoreLifter
        self.ProgramLifter = ProgramLifter
        self.FunctionLifter = FunctionLifter
        self.InstructionLifter = InstructionLifter
        self.PcodeLifter = PcodeLifter

        self.program = program
        self.core = self.CoreHelper(program)

    def lift(self, directory: str):
        self.ProgramLifter(self, self.program).emit(directory)

Dragonlifter._EMPTY = Dragonlifter(Program([], [], [], [], Memory([], '')))

if __name__ == '__main__':
    file_path = pathlib.Path(sys.argv[1])
    with open(file_path) as f:
        lifter = Dragonlifter(Program.load(f))
        directory = file_path.with_suffix('')
        directory.mkdir(exist_ok=True)
        print('Lifting into:', directory)
        lifter.lift(str(directory.absolute()))

