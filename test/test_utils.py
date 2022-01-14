import os
import subprocess
import tempfile

from dragonlifter import Dragonlifter
from ghidra_types import *

TEST_DIR = os.path.dirname(__file__)
TEST_BINARIES_DIR = os.path.join(TEST_DIR, 'binaries')


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

def compile_extract_and_lift(c_path: str, gcc_bin_params: list[str], gcc_lifted_params: list[str], plugins: list) -> None:
    bin_path, _= os.path.splitext(c_path)
    json_path = f'{bin_path}_dragonlifter.json'

    if not os.path.isfile(json_path) or os.path.getmtime(c_path) > os.path.getmtime(json_path):
        if not os.path.isfile(bin_path) or os.path.getmtime(c_path) > os.path.getmtime(bin_path):
            compile_files_with_gcc([c_path], bin_path, gcc_bin_params)
        run_dragonlifter_extractor_ghidra_headless(bin_path)

    with open(json_path) as f:
        lifter = Dragonlifter.with_plugins(Program.load(f), plugins)

    lifted_dir = f'{bin_path}_dragonlifter'
    os.makedirs(lifted_dir, exist_ok=True)
    lifter.lift(lifted_dir)
    c_files = [os.path.join(lifted_dir, f) for f in os.listdir(lifted_dir) if f.endswith('.c')]
    out_file = os.path.join(lifted_dir, 'lifted')
    compile_files_with_gcc(c_files, out_file, gcc_lifted_params)

def execute_binary(binary: str, input: str):
    p = subprocess.Popen([binary], stdin=subprocess.PIPE, stdout=subprocess.PIPE, stderr=subprocess.PIPE)
    stdout_b, stderr_b = p.communicate(input.encode())
    stdout = stdout_b.decode()
    stderr = stderr_b.decode()
    return p.returncode, stdout, stderr
