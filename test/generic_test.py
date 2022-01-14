import os
import sys
from test.test_utils import TEST_BINARIES_DIR, compile_extract_and_lift, execute_binary

import pytest
from plugins import int128, syscall_linux64


@pytest.mark.skipif(sys.platform != 'linux', reason="Requires linux syscalls.")
def test_generic_output():
    compile_extract_and_lift(
        os.path.join(TEST_BINARIES_DIR, 'generic_nostdlib.c'),
        ['-nostdlib'], ['-Wno-builtin-declaration-mismatch', '-nostartfiles'],
        [int128, syscall_linux64])

    input = '''7\n-3\n*\n11\n7\n^\n10\n7\n'''
    orig_code, orig_stdout, orig_stderr = execute_binary(
        os.path.join(TEST_BINARIES_DIR, 'generic_nostdlib'), input)
    lifted_code, lifted_stdout, lifted_stderr = execute_binary(
        os.path.join(TEST_BINARIES_DIR, 'generic_nostdlib_dragonlifter', 'lifted'), input)
    assert orig_code == lifted_code
    assert orig_stdout == lifted_stdout
    assert orig_stderr == lifted_stderr
