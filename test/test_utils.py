import os
import subprocess
import tempfile

from ghidra_types import *


def dummy_program(*, functions=[], op_names=[], address_spaces=[], registers_blocks=[], memory=Memory([], '')):
    return Program(functions, op_names, address_spaces, registers_blocks, memory)

def run_dragonlifter_extractor_ghidra_headless(binary):
    ghidra_install_dir = os.getenv('GHIDRA_INSTALL_DIR')
    assert ghidra_install_dir is not None, 'The GHIDRA_INSTALL_DIR must be set.'
    ghidra_headless = os.path.join(ghidra_install_dir, 'support', 'analyzeHeadless')
    with tempfile.TemporaryDirectory(prefix='temp_dragonlifter_') as temp_dir:
        script_directory = os.path.join(os.path.dirname(__file__), '..', 'ghidra')
        cmd = [
            ghidra_headless, temp_dir, 'test', '-deleteProject', '-import', binary,
            '-scriptPath', script_directory, '-postScript', 'dragonlifter_extractor.py'
        ]
        p = subprocess.run(cmd, check=True, stderr=subprocess.PIPE)
        exception = b'Traceback' in p.stderr
        assert not exception, p.stderr.decode()

def compile_files_with_gcc(files: list[str], output: str, extra_args: list[str] = []) -> None:
    subprocess.check_call(['gcc', *files, '-o', output, '-mincoming-stack-boundary=3', *extra_args])
