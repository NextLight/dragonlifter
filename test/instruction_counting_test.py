import os
import subprocess
import tempfile
from dragonlifter import Dragonlifter
from ghidra_types import Program

from lifters.function_lifter import FunctionLifter
from plugins import int_128, instruction_counting, syscall_linux64


def compile_files_with_gcc(files: list[str], output: str) -> None:
    subprocess.check_call(['gcc', *files, '-o', output, '-mincoming-stack-boundary=3', '-Wno-builtin-declaration-mismatch', '-nostartfiles'])

def lift_and_execute_count_no_stdlib(input: str):
    class PrintInstructionCountOnExit(FunctionLifter):
        def generate_header(self) -> str:
            header = super().generate_header()
            if self.function.name == 'exit':
                header += '\n__print_instruction_count();'
            return header

    with open(os.path.join(os.path.dirname(__file__), 'binaries/count_no_stdlib_dragonlifter.json')) as f:
        lifter = Dragonlifter.with_plugins(Program.load(f), [int_128, syscall_linux64, instruction_counting, PrintInstructionCountOnExit])

    with tempfile.TemporaryDirectory() as d:
        lifter.lift(d)
        compile_files_with_gcc([f'{d}/*.c'], f'{d}/lifted')
        p = subprocess.Popen([f'{d}/lifted'], stdin=subprocess.PIPE, stderr=subprocess.PIPE)
        _, stderr_b = p.communicate(input.encode())
        stderr = stderr_b.decode()
        assert stderr.startswith('count: ')
        return int(stderr.removeprefix('count: ').strip())

def test_instruction_count():
    assert lift_and_execute_count_no_stdlib('test') == 123
