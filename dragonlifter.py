import argparse
import importlib.util
import inspect
import pathlib
import sys
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
        return Dragonlifter(program, **{t.__name__: Dragonlifter._type_with_plugins(t.__name__, plugins) for t, plugins in plugins_by_type.items()})

    @staticmethod
    def _type_with_plugins(original_name: str, plugins: list[type]) -> type:
        return type(f'{original_name}_with_plugins', tuple(plugins[::-1]), {})
        
    @staticmethod
    def _plugins_from_class_or_module(class_or_module: type|ModuleType) -> Iterator[tuple[type, type]]:
        if isinstance(class_or_module, ModuleType):
            for name, c in inspect.getmembers(class_or_module, inspect.isclass):
                if inspect.getmodule(c) == class_or_module:
                    yield from Dragonlifter._plugins_from_class_or_module(c)
        else:
            for t in [CoreHelper, CoreLifter, FunctionLifter, InstructionLifter, PcodeLifter, ProgramLifter]:
                if issubclass(class_or_module, t):
                    yield class_or_module, t

    def lift(self, directory: str):
        self.ProgramLifter(self, self.program).emit(directory)

def _import_module_by_path(path: str):
    spec = importlib.util.spec_from_file_location(path, path)
    m = importlib.util.module_from_spec(spec)
    sys.modules[spec.name] = m
    spec.loader.exec_module(m)
    return m

if __name__ == '__main__':
    parser = argparse.ArgumentParser(description='Dragonlifter.')
    parser.add_argument('file', help='The path to the json file generated in ghidra by dragonlifter_extractor.py.')
    parser.add_argument('-p', '--plugin', dest='plugins', default=[], required=False, action='append', help='Path to a plugin file.')
    args = parser.parse_args()

    file_path = pathlib.Path(args.file)
    plugins = [_import_module_by_path(p) for p in args.plugins]
    with open(file_path) as f:
        lifter = Dragonlifter.with_plugins(Program.load(f), plugins)
        directory = file_path.with_suffix('')
        directory.mkdir(exist_ok=True)
        print('Lifting into:', directory)
        lifter.lift(str(directory.absolute()))
