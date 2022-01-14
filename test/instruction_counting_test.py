import os
import sys

import pytest
from lifters.function_lifter import FunctionLifter
from plugins import instruction_counting, int128, syscall_linux64

from .test_utils import TEST_BINARIES_DIR, compile_extract_and_lift, execute_binary


def lift_count_nostdlib() -> None:
    class PrintInstructionCountOnExit(FunctionLifter):
        def generate_header(self) -> str:
            header = super().generate_header()
            if self.function.name == 'exit':
                header += '\n__print_instruction_count();'
            return header

    compile_extract_and_lift(
        os.path.join(TEST_BINARIES_DIR, 'count_nostdlib.c'),
        ['-nostdlib'], ['-Wno-builtin-declaration-mismatch', '-nostartfiles'],
        [int128, syscall_linux64, instruction_counting, PrintInstructionCountOnExit])

def execute_count_nostdlib(input: str) -> int:
    lifted_bin = os.path.join(TEST_BINARIES_DIR, 'count_nostdlib_dragonlifter', 'lifted')
    _, _, stderr = execute_binary(lifted_bin, input)
    assert stderr.startswith('count: ')
    return int(stderr.removeprefix('count: ').strip())

@pytest.mark.skipif(sys.platform != 'linux', reason="Requires linux syscalls.")
def test_instruction_count():
    lift_count_nostdlib()
    one_letter_right = execute_count_nostdlib('s\n')
    one_letter_wrong1 = execute_count_nostdlib('a\n')
    one_letter_wrong2 = execute_count_nostdlib('b\n')
    assert one_letter_wrong1 == one_letter_wrong2
    assert one_letter_right > one_letter_wrong1
    all_right = execute_count_nostdlib('sup3rs3cr3tfl4g\n')
    first_letter_wrong1 = execute_count_nostdlib('aup3rs3cr3tfl4g\n')
    first_letter_wrong2 = execute_count_nostdlib('bup3rs3cr3tfl4g\n')
    assert first_letter_wrong1 == first_letter_wrong2
    assert all_right > first_letter_wrong2
