from types import ModuleType
from dragonlifter import Dragonlifter
from ghidra_types import *
from lifters.core_helper import CoreHelper
from lifters.core_lifter import CoreLifter
from lifters.function_lifter import FunctionLifter
from lifters.instruction_lifter import InstructionLifter
from lifters.pcode_lifter import PcodeLifter
from lifters.program_lifter import ProgramLifter
from test.test_utils import dummy_program

TEST_FUNCTION = Function('test', 0, [])
PROGRAM_WITH_TEST_FUNCTION = dummy_program(functions=[TEST_FUNCTION])

class FunctionLifterNameA(FunctionLifter):
    def generate_function_name(self) -> str:
        return super().generate_function_name() + 'A'

class FunctionLifterNameB(FunctionLifter):
    def generate_function_name(self) -> str:
        return super().generate_function_name() + 'B'

def fake_module(classes):
    m = ModuleType('fake')
    for c in classes:
        setattr(m, c.__name__, c)
    return m


def test_single_plugin():
    lifter = Dragonlifter.with_plugins(PROGRAM_WITH_TEST_FUNCTION, [FunctionLifterNameA])
    function_lifter = lifter.FunctionLifter(lifter, TEST_FUNCTION)
    assert function_lifter.generate_function_name() == 'testA'

def test_multiple_plugins():
    lifter = Dragonlifter.with_plugins(PROGRAM_WITH_TEST_FUNCTION, [FunctionLifterNameA, FunctionLifterNameB])
    assert lifter.FunctionLifter(lifter, TEST_FUNCTION).generate_function_name() == 'testAB'
    lifter = Dragonlifter.with_plugins(PROGRAM_WITH_TEST_FUNCTION, [FunctionLifterNameB, FunctionLifterNameA])
    assert lifter.FunctionLifter(lifter, TEST_FUNCTION).generate_function_name() == 'testBA'

def test_module_plugin():
    m = fake_module([FunctionLifterNameB])
    lifter = Dragonlifter.with_plugins(PROGRAM_WITH_TEST_FUNCTION, [m])
    assert lifter.FunctionLifter(lifter, TEST_FUNCTION).generate_function_name() == 'testB'

def test_module_and_function_plugin():
    m = fake_module([FunctionLifterNameB])
    lifter = Dragonlifter.with_plugins(PROGRAM_WITH_TEST_FUNCTION, [m, FunctionLifterNameA])
    assert lifter.FunctionLifter(lifter, TEST_FUNCTION).generate_function_name() == 'testBA'

def test_core_helper_plugin():
    class CoreHelperPlugin(CoreHelper):
        def temp_variable(self, id):
            return 'test'
    lifter = Dragonlifter.with_plugins(dummy_program(), [CoreHelperPlugin])
    assert lifter.CoreHelper(lifter.program).temp_variable(0) == 'test'

def test_core_lifter_plugin():
    class CoreLifterPlugin(CoreLifter):
        def lift_c(self) -> str:
            return 'test'
    lifter = Dragonlifter.with_plugins(dummy_program(), [CoreLifterPlugin])
    assert lifter.CoreLifter(lifter).lift_c() == 'test'

def test_function_lifter_plugin():
    class FunctionLifterPlugin(FunctionLifter):
        def lift(self) -> str:
            return 'test'
    lifter = Dragonlifter.with_plugins(dummy_program(), [FunctionLifterPlugin])
    assert lifter.FunctionLifter(lifter, Function('', 0, [])).lift() == 'test'

def test_instruction_lifter_plugin():
    class InstructionLifterPlugin(InstructionLifter):
        def lift(self) -> str:
            return 'test'
    lifter = Dragonlifter.with_plugins(dummy_program(), [InstructionLifterPlugin])
    assert lifter.InstructionLifter(lifter, Instruction(0, '', [])).lift() == 'test'

def test_pcode_lifter_plugin():
    class PcodeLifterPlugin(PcodeLifter):
        def lift(self) -> str:
            return 'test'
    lifter = Dragonlifter.with_plugins(dummy_program(), [PcodeLifterPlugin])
    assert lifter.PcodeLifter(lifter, Pcode(Op.COPY, Varnode(VarnodeType.RAM, 0, 0), []), 0, 0).lift() == 'test'

def test_program_lifter_plugin():
    class ProgramLifterPlugin(ProgramLifter):
        def generate_imports(self) -> str:
            return 'test'
    lifter = Dragonlifter.with_plugins(dummy_program(), [ProgramLifterPlugin])
    assert lifter.ProgramLifter(lifter, lifter.program).generate_imports() == 'test'
