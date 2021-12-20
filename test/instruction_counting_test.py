import os
import subprocess
import sys
import tempfile

import pytest
from dragonlifter import Dragonlifter
from ghidra_types import Program
from lifters.function_lifter import FunctionLifter
from plugins import instruction_counting, int_128, syscall_linux64


def compile_files_with_gcc(files: list[str], output: str) -> None:
    subprocess.check_call(['gcc', *files, '-o', output, '-mincoming-stack-boundary=3', '-Wno-builtin-declaration-mismatch', '-nostartfiles'])

def lift_count_no_stdlib(dir) -> None:
    class PrintInstructionCountOnExit(FunctionLifter):
        def generate_header(self) -> str:
            header = super().generate_header()
            if self.function.name == 'exit':
                header += '\n__print_instruction_count();'
            return header

    with open(os.path.join(os.path.dirname(__file__), 'binaries/count_no_stdlib_dragonlifter.json')) as f:
        lifter = Dragonlifter.with_plugins(Program.load(f), [int_128, syscall_linux64, instruction_counting, PrintInstructionCountOnExit])

    lifter.lift(dir)
    compile_files_with_gcc([os.path.join(dir, f) for f in os.listdir(dir) if f.endswith('.c')], os.path.join(dir, 'lifted'))

def execute_count_no_stdlib(dir, input: str):
    p = subprocess.Popen([os.path.join(dir, 'lifted')], stdin=subprocess.PIPE, stderr=subprocess.PIPE)
    _, stderr_b = p.communicate(input.encode())
    stderr = stderr_b.decode()
    assert stderr.startswith('count: ')
    return int(stderr.removeprefix('count: ').strip())

@pytest.mark.skipif(sys.platform != 'linux', reason="Requires linux.")
def test_instruction_count():
    with tempfile.TemporaryDirectory() as d:
        lift_count_no_stdlib(d)
        assert execute_count_no_stdlib(d, 's\n') == 606
        assert execute_count_no_stdlib(d, 'a\n') == 590
        assert execute_count_no_stdlib(d, 'b\n') == 590
        assert execute_count_no_stdlib(d, 'sup3rs3cr3tfl4g\n') == 1336
        assert execute_count_no_stdlib(d, 'aup3rs3cr3tfl4g\n') == 1108
        assert execute_count_no_stdlib(d, 'bup3rs3cr3tfl4g\n') == 1108
