import inspect
import os
import sys
import pathlib
from types import ModuleType
from typing import Iterator

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
            CoreHelper: type[CoreHelper],
            CoreLifter: type[CoreLifter],
            ProgramLifter: type[ProgramLifter],
            FunctionLifter: type[FunctionLifter],
            InstructionLifter: type[InstructionLifter],
            PcodeLifter: type[PcodeLifter],
        ):
        self.CoreHelper = CoreHelper
        self.CoreLifter = CoreLifter
        self.ProgramLifter = ProgramLifter
        self.FunctionLifter = FunctionLifter
        self.InstructionLifter = InstructionLifter
        self.PcodeLifter = PcodeLifter

        self.program = program
        self.core = self.CoreHelper(program)

    @staticmethod
    def with_plugins(program: Program, plugins: list[type|ModuleType]) -> "Dragonlifter":
        plugins_by_type: dict[type, list[type]] = {
            CoreHelper: [CoreHelper],
            CoreLifter: [CoreLifter],
            FunctionLifter: [FunctionLifter],
            FunctionLifter: [FunctionLifter],
            InstructionLifter: [InstructionLifter],
            PcodeLifter: [PcodeLifter],
            ProgramLifter: [ProgramLifter],
        }
        for plugin in plugins:
            for p, t in Dragonlifter._plugins_from_class_or_module(plugin):
                plugins_by_type[t].append(p)
        return Dragonlifter(program, **{t.__name__: type(f'{t.__name__}_with_plugins', tuple(plugins[::-1]), {}) for t, plugins in plugins_by_type.items()})
        
    @staticmethod
    def _plugins_from_class_or_module(class_or_module: type|ModuleType) -> Iterator[tuple[type, type]]:
        if isinstance(class_or_module, ModuleType):
            for name, c in inspect.getmembers(class_or_module, inspect.isclass):
                yield from Dragonlifter._plugins_from_class_or_module(c)
        else:
            for t in [CoreHelper, CoreLifter, FunctionLifter, InstructionLifter, PcodeLifter, ProgramLifter]:
                if issubclass(class_or_module, t):
                    yield class_or_module, t

    def lift(self, directory: str):
        self.ProgramLifter(self, self.program).emit(directory)


if __name__ == '__main__':
    file_path = pathlib.Path(sys.argv[1])
    with open(file_path) as f:
        lifter = Dragonlifter.with_plugins(Program.load(f), [])
        directory = file_path.with_suffix('')
        directory.mkdir(exist_ok=True)
        print('Lifting into:', directory)
        lifter.lift(str(directory.absolute()))
