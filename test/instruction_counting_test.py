import os
import subprocess
import sys
import tempfile

import pytest
from dragonlifter import Dragonlifter
from ghidra_types import Program
from lifters.function_lifter import FunctionLifter
from plugins import instruction_counting, int128, syscall_linux64
from test.test_utils import compile_files_with_gcc, run_dragonlifter_extractor_ghidra_headless


def lift_count_nostdlib(dir) -> None:
    class PrintInstructionCountOnExit(FunctionLifter):
        def generate_header(self) -> str:
            header = super().generate_header()
            if self.function.name == 'exit':
                header += '\n__print_instruction_count();'
            return header

    binaries_path = os.path.join(os.path.dirname(__file__), 'binaries')
    c_path = os.path.join(binaries_path, 'count_nostdlib.c')
    bin_path = os.path.join(binaries_path, 'count_nostdlib')
    json_path = os.path.join(binaries_path, 'count_nostdlib_dragonlifter.json')

    if not os.path.isfile(json_path) or os.path.getmtime(c_path) > os.path.getmtime(json_path):
        if not os.path.isfile(bin_path) or os.path.getmtime(c_path) > os.path.getmtime(bin_path):
            compile_files_with_gcc([c_path], bin_path, ['-nostdlib'])
        run_dragonlifter_extractor_ghidra_headless(bin_path)

    with open(json_path) as f:
        lifter = Dragonlifter.with_plugins(Program.load(f), [int128, syscall_linux64, instruction_counting, PrintInstructionCountOnExit])

    lifter.lift(dir)
    c_files = [os.path.join(dir, f) for f in os.listdir(dir) if f.endswith('.c')]
    out_file = os.path.join(dir, 'lifted')
    compile_files_with_gcc(c_files, out_file, ['-Wno-builtin-declaration-mismatch', '-nostartfiles'])

def execute_count_nostdlib(dir, input: str):
    p = subprocess.Popen([os.path.join(dir, 'lifted')], stdin=subprocess.PIPE, stderr=subprocess.PIPE)
    _, stderr_b = p.communicate(input.encode())
    stderr = stderr_b.decode()
    assert stderr.startswith('count: ')
    return int(stderr.removeprefix('count: ').strip())

@pytest.mark.skipif(sys.platform != 'linux', reason="Requires linux syscalls.")
def test_instruction_count():
    with tempfile.TemporaryDirectory() as d:
        lift_count_nostdlib(d)
        one_letter_right = execute_count_nostdlib(d, 's\n')
        one_letter_wrong1 = execute_count_nostdlib(d, 'a\n')
        one_letter_wrong2 = execute_count_nostdlib(d, 'b\n')
        assert one_letter_wrong1 == one_letter_wrong2
        assert one_letter_right > one_letter_wrong1
        all_right = execute_count_nostdlib(d, 'sup3rs3cr3tfl4g\n')
        first_letter_wrong1 = execute_count_nostdlib(d, 'aup3rs3cr3tfl4g\n')
        first_letter_wrong2 = execute_count_nostdlib(d, 'bup3rs3cr3tfl4g\n')
        assert first_letter_wrong1 == first_letter_wrong2
        assert all_right > first_letter_wrong2
