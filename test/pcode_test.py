import pytest

pytest.main(['-x', '--ff', __file__])

import io
import struct
import subprocess
import sys
from typing import Type

from code_emitter import CodeEmitter
from dragonlifter import Dragonlifter
from ghidra_types import *
from lifters.core_lifter import CoreLifter
from lifters.pcode_lifter import Output, OutputSigned, PcodeLifter, Var, VarKind

from .test_utils import dummy_program


def setup_module():
    try:
        subprocess.check_call(['tcc', '-v'])
    except FileNotFoundError:
        assert False, "Please install TCC and/or add it to your path.\nThe windows binaries can be found at https://download.savannah.gnu.org/releases/tinycc, use you package manager on linux."
    
NaN = float('NaN')
INF = float('inf')
PRINTF_INT_STRING_FORMAT = {1: 'hh', 2: 'h', 4: '', 8: 'll'}
PRINTF_FLOAT_STRING_FORMAT = {4: '', 8: '', 12: 'L'}

def printf_string_format(kind: VarKind, size: int) -> str:
    if kind == VarKind.SIGNED:
        return f'{PRINTF_INT_STRING_FORMAT[size]}d'
    if kind == VarKind.UNSIGNED:
        return f'{PRINTF_INT_STRING_FORMAT[size]}u'
    if kind == VarKind.FLOATING:
        return f'{PRINTF_FLOAT_STRING_FORMAT[size]}f'
    assert False

def run_c_code(code: bytes) -> str:
    try:
        return subprocess.check_output(['tcc', '-O0', '-run', '-'], input=code).decode('utf-8')
    except Exception as e:
        print(code.decode('utf-8'), file=sys.stderr)
        raise e

def run_pcodes(pcodes: list[Pcode], out_var: Var):
    dragonlifter = Dragonlifter.with_plugins(dummy_program(), [])
    core_lifter = CoreLifter(dragonlifter)
    core_lifter.setup_default_types()
    core_lifter.setup_math()
    core_lifter.setup_popcount()

    with io.StringIO() as out_c:
        p = CodeEmitter(out_c)
        p.emit(core_lifter.lift_header())
        p.emit('')
        p.emit('int main() {')
        c_code_lines = [PcodeLifter(dragonlifter, pcode, 0, i).lift() for i, pcode in enumerate(pcodes)]
        p.emit(f'varnode_t {",".join(map(dragonlifter.core.temp_variable, dragonlifter.core.used_temp_variables))};')
        for i, c_code in enumerate(c_code_lines):
            p.emit(f'{dragonlifter.core.pcode_label(0, i)}: {c_code}')
        tmp_pcode_lifter = PcodeLifter(dragonlifter, pcodes[0], 0, 0)
        p.emit(f'printf("%{printf_string_format(out_var.kind, out_var.size)}", {tmp_pcode_lifter.var(out_var)});')
        p.emit(f'return 0;')
        p.emit('}')

        return run_c_code(out_c.getvalue().encode('utf-8')), c_code_lines

def assert_caller_is_op_test(op: Op):
    caller = sys._getframe().f_back
    while caller and not caller.f_code.co_name.startswith('test_'):
        caller = caller.f_back
    assert caller is not None
    caller_name = caller.f_code.co_name
    assert caller_name.startswith('test_')
    assert caller_name[5:] == op.name.lower()

def size_to_float_int_format(size: int) -> tuple[str, str]:
    if size == 4:
        return 'f', 'I'
    elif size == 8:
        return 'd', 'Q'
    else:
        assert False

def float_to_raw_int(f: float, size: int) -> int:
    float_fmt, int_fmt = size_to_float_int_format(size)
    return struct.unpack(int_fmt, struct.pack(float_fmt, f))[0]

def raw_int_to_float(i: int, size: int) -> float:
    float_fmt, int_fmt = size_to_float_int_format(size)
    return struct.unpack(float_fmt, struct.pack(int_fmt, i))[0]

def floating_arithmetic_test(op: Op, inputs: list[float], output, input_size=4, output_size=4):
    return arithmetic_test(op, inputs, output, input_size, 1 if isinstance(output, bool) else output_size, Output)

def signed_arithmetic_test(op: Op, inputs: list, output: int, input_size=1, output_size=1):
    return arithmetic_test(op, inputs, output, input_size, output_size, OutputSigned)

def arithmetic_test(op: Op, inputs: list, output, input_size=1, output_size=1, output_var_type: Type[Var]=Output, output_transform=int):
    assert_caller_is_op_test(op)
    out_var = output_var_type(VarnodeType.TEMP, 0, output_size)
    inputs_with_size = [(float_to_raw_int(i, size) if isinstance(i, float) else int(i), size) for i, size in zip(inputs, input_size if isinstance(input_size, list) else [input_size] * len(inputs))]
    output = float_to_raw_int(output, output_size) if isinstance(output, float) else int(output)
    pcode = Pcode(op, out_var, [Varnode(VarnodeType.CONSTANT, i, size) for i, size in inputs_with_size])
    c_out, c_code_lines = run_pcodes([pcode], out_var)
    print(c_out)
    assert output_transform(c_out) == output, f'{op.name}({", ".join(map(str, inputs))}) should be {output} but was {c_out} --> `{c_code_lines[0]}`'

def test_copy():
    arithmetic_test(Op.COPY, [0], 0)
    arithmetic_test(Op.COPY, [1], 1)
    arithmetic_test(Op.COPY, [42], 42)
    arithmetic_test(Op.COPY, [12345], 12345, input_size=2, output_size=2)
    arithmetic_test(Op.COPY, [123456], 123456, input_size=4, output_size=4)
    arithmetic_test(Op.COPY, [12345678901], 12345678901, input_size=8, output_size=8)

def test_load(): Op.LOAD
def test_store(): Op.STORE
def test_branch(): Op.BRANCH
def test_cbranch(): Op.CBRANCH
def test_branchind(): Op.BRANCHIND
def test_call(): Op.CALL
def test_callind(): Op.CALLIND
def test_callother(): Op.CALLOTHER
def test_return(): Op.RETURN

def test_int_equal():
    arithmetic_test(Op.INT_EQUAL, [0, 0], True)
    arithmetic_test(Op.INT_EQUAL, [0, 1], False)
    arithmetic_test(Op.INT_EQUAL, [-1, 255], True)

def test_int_notequal():
    arithmetic_test(Op.INT_NOTEQUAL, [0, 0], False)
    arithmetic_test(Op.INT_NOTEQUAL, [0, 1], True)
    arithmetic_test(Op.INT_NOTEQUAL, [-1, 255], False)

def test_int_sless():
    arithmetic_test(Op.INT_SLESS, [1, 2], True)
    arithmetic_test(Op.INT_SLESS, [2, 1], False)
    arithmetic_test(Op.INT_SLESS, [-1, 2], True)
    arithmetic_test(Op.INT_SLESS, [2, -1], False)
    arithmetic_test(Op.INT_SLESS, [-2, -1], True)
    arithmetic_test(Op.INT_SLESS, [-1, -2], False)
    arithmetic_test(Op.INT_SLESS, [1, 1], False)
    arithmetic_test(Op.INT_SLESS, [-1, -1], False)

def test_int_slessequal():
    arithmetic_test(Op.INT_SLESSEQUAL, [1, 2], True)
    arithmetic_test(Op.INT_SLESSEQUAL, [2, 1], False)
    arithmetic_test(Op.INT_SLESSEQUAL, [-1, 2], True)
    arithmetic_test(Op.INT_SLESSEQUAL, [2, -1], False)
    arithmetic_test(Op.INT_SLESSEQUAL, [-2, -1], True)
    arithmetic_test(Op.INT_SLESSEQUAL, [-1, -2], False)
    arithmetic_test(Op.INT_SLESSEQUAL, [1, 1], True)
    arithmetic_test(Op.INT_SLESSEQUAL, [-1, -1], True)

def test_int_less():
    arithmetic_test(Op.INT_LESS, [1, 2], True)
    arithmetic_test(Op.INT_LESS, [2, 1], False)
    arithmetic_test(Op.INT_LESS, [-1, 2], False)
    arithmetic_test(Op.INT_LESS, [2, -1], True)
    arithmetic_test(Op.INT_LESS, [1, 1], False)

def test_int_lessequal():
    arithmetic_test(Op.INT_LESSEQUAL, [1, 2], True)
    arithmetic_test(Op.INT_LESSEQUAL, [2, 1], False)
    arithmetic_test(Op.INT_LESSEQUAL, [-1, 2], False)
    arithmetic_test(Op.INT_LESSEQUAL, [2, -1], True)
    arithmetic_test(Op.INT_LESSEQUAL, [1, 1], True)

def test_int_zext():
    arithmetic_test(Op.INT_ZEXT, [255], 255, output_size=2)
    arithmetic_test(Op.INT_ZEXT, [-1], 255, output_size=2)
    arithmetic_test(Op.INT_ZEXT, [255], 255, output_size=8)
    arithmetic_test(Op.INT_ZEXT, [1], 1, output_size=2)

def test_int_sext():
    arithmetic_test(Op.INT_SEXT, [255], 2**16-1, output_size=2)
    arithmetic_test(Op.INT_SEXT, [-1], 2**16-1, output_size=2)
    arithmetic_test(Op.INT_SEXT, [255], 2**64-1, output_size=8)
    arithmetic_test(Op.INT_SEXT, [1], 1, output_size=2)

def test_int_add():
    arithmetic_test(Op.INT_ADD, [11, 7], 18)
    arithmetic_test(Op.INT_ADD, [7, 11], 18)
    arithmetic_test(Op.INT_ADD, [255, 1], 0)
    arithmetic_test(Op.INT_ADD, [-1, 0], 255)

def test_int_sub():
    arithmetic_test(Op.INT_SUB, [11, 7], 4)
    arithmetic_test(Op.INT_SUB, [0, 1], 255)
    arithmetic_test(Op.INT_SUB, [0, -1], 1)

def test_int_carry():
    arithmetic_test(Op.INT_CARRY, [1, 2], False)
    arithmetic_test(Op.INT_CARRY, [255, 1], True)
    arithmetic_test(Op.INT_CARRY, [254, 1], False)
    arithmetic_test(Op.INT_CARRY, [0, -1], False)

def test_int_scarry():
    arithmetic_test(Op.INT_SCARRY, [1, 2], False)
    arithmetic_test(Op.INT_SCARRY, [-1, 1], False)
    arithmetic_test(Op.INT_SCARRY, [255, 1], False)
    arithmetic_test(Op.INT_SCARRY, [-2, -3], False)
    arithmetic_test(Op.INT_SCARRY, [127, 1], True)
    arithmetic_test(Op.INT_SCARRY, [-128, -1], True)
    arithmetic_test(Op.INT_SCARRY, [-127, -10], True)
    arithmetic_test(Op.INT_SCARRY, [-127, -1], False)

def test_int_sborrow():
    arithmetic_test(Op.INT_SBORROW, [1, 2], False)
    arithmetic_test(Op.INT_SBORROW, [-1, 1], False)
    arithmetic_test(Op.INT_SBORROW, [255, 1], False)
    arithmetic_test(Op.INT_SBORROW, [-2, -3], False)
    arithmetic_test(Op.INT_SBORROW, [127, 1], False)
    arithmetic_test(Op.INT_SBORROW, [127, -1], True)
    arithmetic_test(Op.INT_SBORROW, [-128, 1], True)
    arithmetic_test(Op.INT_SBORROW, [-127, 10], True)
    arithmetic_test(Op.INT_SBORROW, [-127, 1], False)

def test_int_2comp():
    signed_arithmetic_test(Op.INT_2COMP, [1], -1)
    signed_arithmetic_test(Op.INT_2COMP, [-1], 1)
    signed_arithmetic_test(Op.INT_2COMP, [42], -42)
    signed_arithmetic_test(Op.INT_2COMP, [-128], -128)
    signed_arithmetic_test(Op.INT_2COMP, [0], 0)

def test_int_negate():
    arithmetic_test(Op.INT_NEGATE, [1], 254)
    arithmetic_test(Op.INT_NEGATE, [254], 1)
    arithmetic_test(Op.INT_NEGATE, [0], 255)
    arithmetic_test(Op.INT_NEGATE, [128], 127)

def test_int_xor():
    arithmetic_test(Op.INT_XOR, [0, 0], 0)
    arithmetic_test(Op.INT_XOR, [10, 0], 10)
    arithmetic_test(Op.INT_XOR, [0, 10], 10)
    arithmetic_test(Op.INT_XOR, [2, 3], 1)
    arithmetic_test(Op.INT_XOR, [255, 1], 254)

def test_int_and():
    arithmetic_test(Op.INT_AND, [0, 0], 0)
    arithmetic_test(Op.INT_AND, [10, 0], 0)
    arithmetic_test(Op.INT_AND, [0, 10], 0)
    arithmetic_test(Op.INT_AND, [2, 3], 2)
    arithmetic_test(Op.INT_AND, [7, 255], 7)

def test_int_or():
    arithmetic_test(Op.INT_OR, [0, 0], 0)
    arithmetic_test(Op.INT_OR, [10, 0], 10)
    arithmetic_test(Op.INT_OR, [0, 10], 10)
    arithmetic_test(Op.INT_OR, [1, 1], 1)
    arithmetic_test(Op.INT_OR, [2, 3], 3)
    arithmetic_test(Op.INT_OR, [7, 255], 255)

def test_int_left():
    arithmetic_test(Op.INT_LEFT, [7, 0], 7)
    arithmetic_test(Op.INT_LEFT, [1, 1], 2)
    arithmetic_test(Op.INT_LEFT, [3, 1], 6)
    arithmetic_test(Op.INT_LEFT, [128, 1], 0)
    arithmetic_test(Op.INT_LEFT, [255, 2], 252)
    arithmetic_test(Op.INT_LEFT, [6, 20], 0)

def test_int_right():
    arithmetic_test(Op.INT_RIGHT, [7, 0], 7)
    arithmetic_test(Op.INT_RIGHT, [2, 1], 1)
    arithmetic_test(Op.INT_RIGHT, [4, 2], 1)
    arithmetic_test(Op.INT_RIGHT, [1, 1], 0)
    arithmetic_test(Op.INT_RIGHT, [128, 1], 64)
    arithmetic_test(Op.INT_RIGHT, [255, 1], 127)
    arithmetic_test(Op.INT_RIGHT, [6, 20], 0)

def test_int_sright():
    arithmetic_test(Op.INT_SRIGHT, [7, 0], 7)
    arithmetic_test(Op.INT_SRIGHT, [2, 1], 1)
    arithmetic_test(Op.INT_SRIGHT, [4, 2], 1)
    arithmetic_test(Op.INT_SRIGHT, [1, 1], 0)
    arithmetic_test(Op.INT_SRIGHT, [128, 1], 192)
    arithmetic_test(Op.INT_SRIGHT, [255, 1], 255)
    arithmetic_test(Op.INT_SRIGHT, [128, 20], 255)
    arithmetic_test(Op.INT_SRIGHT, [64, 20], 0)

def test_int_mult():
    arithmetic_test(Op.INT_MULT, [2, 3], 6)
    arithmetic_test(Op.INT_MULT, [3, 2], 6)
    arithmetic_test(Op.INT_MULT, [2, 1], 2)
    arithmetic_test(Op.INT_MULT, [2, 0], 0)
    arithmetic_test(Op.INT_MULT, [42, 10], (42 * 10) % 256)
    arithmetic_test(Op.INT_MULT, [5, -1], 256 - 5)

def test_int_div():
    arithmetic_test(Op.INT_DIV, [2, 1], 2)
    arithmetic_test(Op.INT_DIV, [6, 2], 3)
    arithmetic_test(Op.INT_DIV, [5, 2], 2)
    arithmetic_test(Op.INT_DIV, [5, 17], 0)

def test_int_sdiv():
    signed_arithmetic_test(Op.INT_SDIV, [2, 1], 2)
    signed_arithmetic_test(Op.INT_SDIV, [6, 2], 3)
    signed_arithmetic_test(Op.INT_SDIV, [5, 2], 2)
    signed_arithmetic_test(Op.INT_SDIV, [5, 17], 0)
    signed_arithmetic_test(Op.INT_SDIV, [4, -2], -2)
    signed_arithmetic_test(Op.INT_SDIV, [5, -2], -2)
    signed_arithmetic_test(Op.INT_SDIV, [8, -3], -2)
    signed_arithmetic_test(Op.INT_SDIV, [-8, 3], -2)
    signed_arithmetic_test(Op.INT_SDIV, [-8, -3], 2)

def test_int_rem():
    arithmetic_test(Op.INT_REM, [2, 1], 0)
    arithmetic_test(Op.INT_REM, [6, 2], 0)
    arithmetic_test(Op.INT_REM, [5, 2], 1)
    arithmetic_test(Op.INT_REM, [5, 17], 5)

def test_int_srem():
    signed_arithmetic_test(Op.INT_SREM, [2, 1], 0)
    signed_arithmetic_test(Op.INT_SREM, [6, 2], 0)
    signed_arithmetic_test(Op.INT_SREM, [5, 2], 1)
    signed_arithmetic_test(Op.INT_SREM, [5, 17], 5)
    signed_arithmetic_test(Op.INT_SREM, [4, -2], 0)
    signed_arithmetic_test(Op.INT_SREM, [5, -2], 1)
    signed_arithmetic_test(Op.INT_SREM, [8, -3], 2)
    signed_arithmetic_test(Op.INT_SREM, [-8, 3], -2)
    signed_arithmetic_test(Op.INT_SREM, [-8, -3], -2)

def test_bool_negate():
    arithmetic_test(Op.BOOL_NEGATE, [False], True)
    arithmetic_test(Op.BOOL_NEGATE, [True], False)
    arithmetic_test(Op.BOOL_NEGATE, [11], False)
    arithmetic_test(Op.BOOL_NEGATE, [0], True)

def test_bool_xor():
    arithmetic_test(Op.BOOL_XOR, [False, True], True)
    arithmetic_test(Op.BOOL_XOR, [True, False], True)
    arithmetic_test(Op.BOOL_XOR, [True, True], False)
    arithmetic_test(Op.BOOL_XOR, [False, False], False)
    arithmetic_test(Op.BOOL_XOR, [3, 4], False)
    arithmetic_test(Op.BOOL_XOR, [2, 4], False)
    arithmetic_test(Op.BOOL_XOR, [2, 2], False)
    arithmetic_test(Op.BOOL_XOR, [5, 0], True)

def test_bool_and():
    arithmetic_test(Op.BOOL_AND, [True, True], True)
    arithmetic_test(Op.BOOL_AND, [True, False], False)
    arithmetic_test(Op.BOOL_AND, [False, True], False)
    arithmetic_test(Op.BOOL_AND, [False, False], False)
    arithmetic_test(Op.BOOL_AND, [3, 4], True)
    arithmetic_test(Op.BOOL_AND, [2, 4], True)
    arithmetic_test(Op.BOOL_AND, [2, 2], True)
    arithmetic_test(Op.BOOL_AND, [5, 0], False)

def test_bool_or():
    arithmetic_test(Op.BOOL_OR, [True, True], True)
    arithmetic_test(Op.BOOL_OR, [True, False], True)
    arithmetic_test(Op.BOOL_OR, [False, True], True)
    arithmetic_test(Op.BOOL_OR, [False, False], False)
    arithmetic_test(Op.BOOL_OR, [3, 4], True)
    arithmetic_test(Op.BOOL_OR, [2, 4], True)
    arithmetic_test(Op.BOOL_OR, [2, 2], True)
    arithmetic_test(Op.BOOL_OR, [5, 0], True)
    arithmetic_test(Op.BOOL_OR, [0, 0], False)

def test_float_equal():
    floating_arithmetic_test(Op.FLOAT_EQUAL, [1.1, 1.1], True)
    floating_arithmetic_test(Op.FLOAT_EQUAL, [1.1, 1.2], False)
    floating_arithmetic_test(Op.FLOAT_EQUAL, [1.0, 1.7], False)
    floating_arithmetic_test(Op.FLOAT_EQUAL, [NaN, 0.0], False)
    floating_arithmetic_test(Op.FLOAT_EQUAL, [NaN, NaN], False)

def test_float_notequal():
    floating_arithmetic_test(Op.FLOAT_NOTEQUAL, [1.1, 1.1], False)
    floating_arithmetic_test(Op.FLOAT_NOTEQUAL, [1.1, 1.2], True)
    floating_arithmetic_test(Op.FLOAT_NOTEQUAL, [1.0, 1.7], True)
    floating_arithmetic_test(Op.FLOAT_NOTEQUAL, [NaN, 0.0], True)
    floating_arithmetic_test(Op.FLOAT_NOTEQUAL, [NaN, NaN], True)

def test_float_less():
    floating_arithmetic_test(Op.FLOAT_LESS, [1.1, 1.2], True)
    floating_arithmetic_test(Op.FLOAT_LESS, [1.1, 1.1], False)
    floating_arithmetic_test(Op.FLOAT_LESS, [1.2, 1.1], False)
    floating_arithmetic_test(Op.FLOAT_LESS, [NaN, 1.0], False)
    floating_arithmetic_test(Op.FLOAT_LESS, [1.0, NaN], False)
    floating_arithmetic_test(Op.FLOAT_LESS, [NaN, NaN], False)

def test_float_lessequal():
    floating_arithmetic_test(Op.FLOAT_LESSEQUAL, [1.1, 1.2], True)
    floating_arithmetic_test(Op.FLOAT_LESSEQUAL, [1.1, 1.1], True)
    floating_arithmetic_test(Op.FLOAT_LESSEQUAL, [1.2, 1.1], False)
    floating_arithmetic_test(Op.FLOAT_LESSEQUAL, [NaN, 1.0], False)
    floating_arithmetic_test(Op.FLOAT_LESSEQUAL, [1.0, NaN], False)
    floating_arithmetic_test(Op.FLOAT_LESSEQUAL, [NaN, NaN], False)

def test_float_nan():
    floating_arithmetic_test(Op.FLOAT_NAN, [1.2], False)
    floating_arithmetic_test(Op.FLOAT_NAN, [0], False)
    floating_arithmetic_test(Op.FLOAT_NAN, [NaN], True)
    floating_arithmetic_test(Op.FLOAT_NAN, [-NaN], True)
    floating_arithmetic_test(Op.FLOAT_NAN, [NaN], True, input_size=8)

def test_float_add():
    floating_arithmetic_test(Op.FLOAT_ADD, [1.0, 1.1], 2.1)
    floating_arithmetic_test(Op.FLOAT_ADD, [1.0, 1.1], 2.1)
    floating_arithmetic_test(Op.FLOAT_ADD, [1.1, -1.1], 0.0)
    floating_arithmetic_test(Op.FLOAT_ADD, [INF, 42], INF)
    floating_arithmetic_test(Op.FLOAT_ADD, [-INF, 42], -INF)
    floating_arithmetic_test(Op.FLOAT_ADD, [1.1, NaN], NaN)
    floating_arithmetic_test(Op.FLOAT_ADD, [NaN, 1.1], NaN)
    floating_arithmetic_test(Op.FLOAT_ADD, [NaN, NaN], NaN)

def test_float_div():
    floating_arithmetic_test(Op.FLOAT_DIV, [1.0, 2.0], 0.5)
    floating_arithmetic_test(Op.FLOAT_DIV, [1.1, 1.0], 1.1)
    floating_arithmetic_test(Op.FLOAT_DIV, [1.1, 0.0], INF)
    floating_arithmetic_test(Op.FLOAT_DIV, [1000.1, INF], 0.0)
    floating_arithmetic_test(Op.FLOAT_DIV, [0.0, INF], 0.0)
    floating_arithmetic_test(Op.FLOAT_DIV, [INF, 1000.1], INF)
    floating_arithmetic_test(Op.FLOAT_DIV, [INF, INF], -NaN)
    floating_arithmetic_test(Op.FLOAT_DIV, [0.0, 0.0], -NaN)

def test_float_mult():
    floating_arithmetic_test(Op.FLOAT_MULT, [2.1, 1.0], 2.1)
    floating_arithmetic_test(Op.FLOAT_MULT, [2.1, -1.0], -2.1)
    floating_arithmetic_test(Op.FLOAT_MULT, [2.1, 2.0], 4.2)
    floating_arithmetic_test(Op.FLOAT_MULT, [1.0, 0.5], 0.5)
    floating_arithmetic_test(Op.FLOAT_MULT, [2.1, 0.0], 0.0)
    floating_arithmetic_test(Op.FLOAT_MULT, [0.0, 0.0], 0.0)
    floating_arithmetic_test(Op.FLOAT_MULT, [INF, 0.1], INF)
    floating_arithmetic_test(Op.FLOAT_MULT, [INF, -0.1], -INF)
    floating_arithmetic_test(Op.FLOAT_MULT, [INF, 0.0], -NaN)
    floating_arithmetic_test(Op.FLOAT_MULT, [INF, INF], INF)
    floating_arithmetic_test(Op.FLOAT_MULT, [NaN, 1.1], NaN)
    floating_arithmetic_test(Op.FLOAT_MULT, [1.1, NaN], NaN)
    floating_arithmetic_test(Op.FLOAT_MULT, [NaN, NaN], NaN)


def test_float_sub():
    floating_arithmetic_test(Op.FLOAT_SUB, [1.1, 1.1], 0.0)
    floating_arithmetic_test(Op.FLOAT_SUB, [1.0, 2.0], -1.0)
    floating_arithmetic_test(Op.FLOAT_SUB, [1.1, -1.1], 2.2)
    floating_arithmetic_test(Op.FLOAT_SUB, [INF, 42], INF)
    floating_arithmetic_test(Op.FLOAT_SUB, [42, INF], -INF)
    floating_arithmetic_test(Op.FLOAT_SUB, [1.1, NaN], NaN)
    floating_arithmetic_test(Op.FLOAT_SUB, [NaN, 1.1], NaN)
    floating_arithmetic_test(Op.FLOAT_SUB, [NaN, NaN], NaN)

def test_float_neg():
    floating_arithmetic_test(Op.FLOAT_NEG, [1.1], -1.1)
    floating_arithmetic_test(Op.FLOAT_NEG, [-1.1], 1.1)
    floating_arithmetic_test(Op.FLOAT_NEG, [0.0], -0.0)
    floating_arithmetic_test(Op.FLOAT_NEG, [-0.0], 0.0)
    floating_arithmetic_test(Op.FLOAT_NEG, [INF], -INF)
    floating_arithmetic_test(Op.FLOAT_NEG, [-INF], INF)
    # floating point negation is bugged in the latest TCC release,
    # https://github.com/TinyCC/tinycc/commit/29d8871d6196819caff83b4359e22cc3655bc234 fixes it but there are no publicly available builds with it yet.
    # floating_arithmetic_test(Op.FLOAT_NEG, [NaN], -NaN)
    # floating_arithmetic_test(Op.FLOAT_NEG, [-NaN], NaN)

def test_float_abs():
    floating_arithmetic_test(Op.FLOAT_ABS, [1.1], 1.1)
    floating_arithmetic_test(Op.FLOAT_ABS, [-1.1], 1.1)
    floating_arithmetic_test(Op.FLOAT_ABS, [-0.0], 0.0)
    floating_arithmetic_test(Op.FLOAT_ABS, [-INF], INF)
    # floating_arithmetic_test(Op.FLOAT_ABS, [-NaN], NaN) # doesn't work on windows using TCC ¯\_(ツ)_/¯
    floating_arithmetic_test(Op.FLOAT_ABS, [NaN], NaN)

def test_float_sqrt():
    floating_arithmetic_test(Op.FLOAT_SQRT, [4.0], 2.0)
    floating_arithmetic_test(Op.FLOAT_SQRT, [0.0], 0.0)
    floating_arithmetic_test(Op.FLOAT_SQRT, [INF], INF)
    floating_arithmetic_test(Op.FLOAT_SQRT, [-4.0], -NaN)
    floating_arithmetic_test(Op.FLOAT_SQRT, [NaN], NaN)

def test_float_int2float():
    floating_arithmetic_test(Op.FLOAT_INT2FLOAT, [2], 2.0, input_size=1, output_size=4)
    floating_arithmetic_test(Op.FLOAT_INT2FLOAT, [2], 2.0, input_size=4, output_size=4)
    floating_arithmetic_test(Op.FLOAT_INT2FLOAT, [2147483600], 2147483600.0, input_size=4, output_size=4)
    floating_arithmetic_test(Op.FLOAT_INT2FLOAT, [2147483601], 2147483600.0, input_size=4, output_size=4)
    with pytest.raises(AssertionError):
        floating_arithmetic_test(Op.FLOAT_INT2FLOAT, [2147483601], 2147483600.0, input_size=4, output_size=8)
    floating_arithmetic_test(Op.FLOAT_INT2FLOAT, [10000000001], 10000000000.0, input_size=8, output_size=4)
    with pytest.raises(AssertionError):
        floating_arithmetic_test(Op.FLOAT_INT2FLOAT, [10000000001], 10000000000.0, input_size=8, output_size=8)

def test_float_float2float():
    floating_arithmetic_test(Op.FLOAT_FLOAT2FLOAT, [1.1], 1.100000023841858, input_size=4, output_size=8)
    floating_arithmetic_test(Op.FLOAT_FLOAT2FLOAT, [1.1], 1.1, input_size=8, output_size=4)
    floating_arithmetic_test(Op.FLOAT_FLOAT2FLOAT, [NaN], NaN, input_size=8, output_size=4)
    floating_arithmetic_test(Op.FLOAT_FLOAT2FLOAT, [NaN], NaN, input_size=4, output_size=8)

def test_float_trunc():
    signed_arithmetic_test(Op.FLOAT_TRUNC, [1.0], 1, input_size=4, output_size=4)
    signed_arithmetic_test(Op.FLOAT_TRUNC, [1.1], 1, input_size=4, output_size=4)
    signed_arithmetic_test(Op.FLOAT_TRUNC, [1.9], 1, input_size=4, output_size=4)
    signed_arithmetic_test(Op.FLOAT_TRUNC, [0.0], 0, input_size=4, output_size=4)
    signed_arithmetic_test(Op.FLOAT_TRUNC, [-0.0], 0, input_size=4, output_size=4)
    signed_arithmetic_test(Op.FLOAT_TRUNC, [-1.0], -1, input_size=4, output_size=4)
    signed_arithmetic_test(Op.FLOAT_TRUNC, [-1.1], -1, input_size=4, output_size=4)
    signed_arithmetic_test(Op.FLOAT_TRUNC, [-1.9], -1, input_size=4, output_size=4)
    signed_arithmetic_test(Op.FLOAT_TRUNC, [-NaN], -2**31, input_size=4, output_size=4)
    signed_arithmetic_test(Op.FLOAT_TRUNC, [NaN], -2**31, input_size=4, output_size=4) # ¯\_(ツ)_/¯
    signed_arithmetic_test(Op.FLOAT_TRUNC, [-INF], -2**31, input_size=4, output_size=4)
    signed_arithmetic_test(Op.FLOAT_TRUNC, [INF], -2**31, input_size=4, output_size=4)

def test_float_ceil():
    floating_arithmetic_test(Op.FLOAT_CEIL, [1.0], 1.0)
    floating_arithmetic_test(Op.FLOAT_CEIL, [1.1], 2.0)
    floating_arithmetic_test(Op.FLOAT_CEIL, [1.0001], 2.0)
    floating_arithmetic_test(Op.FLOAT_CEIL, [1.9], 2.0)
    floating_arithmetic_test(Op.FLOAT_CEIL, [-1.0], -1.0)
    floating_arithmetic_test(Op.FLOAT_CEIL, [-1.1], -1.0)
    floating_arithmetic_test(Op.FLOAT_CEIL, [-1.9], -1.0)
    floating_arithmetic_test(Op.FLOAT_CEIL, [NaN], NaN)

def test_float_floor():
    floating_arithmetic_test(Op.FLOAT_FLOOR, [1.0], 1.0)
    floating_arithmetic_test(Op.FLOAT_FLOOR, [1.1], 1.0)
    floating_arithmetic_test(Op.FLOAT_FLOOR, [1.9], 1.0)
    floating_arithmetic_test(Op.FLOAT_FLOOR, [-1.0], -1.0)
    floating_arithmetic_test(Op.FLOAT_FLOOR, [-1.1], -2.0)
    floating_arithmetic_test(Op.FLOAT_FLOOR, [-1.9], -2.0)
    floating_arithmetic_test(Op.FLOAT_FLOOR, [NaN], NaN)

def test_float_round():
    floating_arithmetic_test(Op.FLOAT_ROUND, [1.0], 1.0)
    floating_arithmetic_test(Op.FLOAT_ROUND, [1.1], 1.0)
    floating_arithmetic_test(Op.FLOAT_ROUND, [1.9], 2.0)
    floating_arithmetic_test(Op.FLOAT_ROUND, [-1.0], -1.0)
    floating_arithmetic_test(Op.FLOAT_ROUND, [-1.1], -1.0)
    floating_arithmetic_test(Op.FLOAT_ROUND, [-1.9], -2.0)
    floating_arithmetic_test(Op.FLOAT_ROUND, [NaN], NaN)

def test_multiequal():
    # Op.MULTIEQUAL is an "additional" p-code and should not be generated from raw translation.
    pass

def test_indirect():
    # Op.INDIRECT is an "additional" p-code and should not be generated from raw translation.
    pass

def test_piece():
    arithmetic_test(Op.PIECE, [0xab, 0xcd], 0xabcd, input_size=1, output_size=2)
    arithmetic_test(Op.PIECE, [0xabcd, 0x0123], 0xabcd0123, input_size=2, output_size=4)
    arithmetic_test(Op.PIECE, [0xabcdef01, 0x23456789], 0xabcdef0123456789, input_size=4, output_size=8)
    arithmetic_test(Op.PIECE, [0, 0xcd], 0xcd, input_size=1, output_size=2)
    arithmetic_test(Op.PIECE, [0xab, 0], 0xab00, input_size=1, output_size=2)
    arithmetic_test(Op.PIECE, [0, 0], 0, input_size=1, output_size=2)

def test_subpiece():
    arithmetic_test(Op.SUBPIECE, [0xabcd, 0], 0xabcd, input_size=8, output_size=8)
    arithmetic_test(Op.SUBPIECE, [0xabcd, 1], 0xab, input_size=8, output_size=8)
    arithmetic_test(Op.SUBPIECE, [0xabcd, 2], 0, input_size=8, output_size=8)
    arithmetic_test(Op.SUBPIECE, [0xabcd, 5], 0, input_size=8, output_size=8)
    arithmetic_test(Op.SUBPIECE, [0xabcdef0123456789, 5], 0xabcdef, input_size=8, output_size=8)
    arithmetic_test(Op.SUBPIECE, [0xabcdef, 2], 0xab, input_size=8, output_size=8)
    arithmetic_test(Op.SUBPIECE, [0xabcdef, 1], 0xcd, input_size=8, output_size=1)

def test_cast():
    # Op.CAST is an "additional" p-code and should not be generated from raw translation.
    pass

def test_ptradd():
    # Op.PTRADD is an "additional" p-code and should not be generated from raw translation.
    pass

def test_ptrsub():
    # Op.PTRSUB is an "additional" p-code and should not be generated from raw translation.
    pass

def test_segmentop(): Op.SEGMENTOP
def test_cpoolref(): Op.CPOOLREF
def test_new(): Op.NEW
def test_insert(): Op.INSERT
def test_extract(): Op.EXTRACT

def test_popcount():
    arithmetic_test(Op.POPCOUNT, [0], 0)
    arithmetic_test(Op.POPCOUNT, [1], 1)
    arithmetic_test(Op.POPCOUNT, [2], 1)
    arithmetic_test(Op.POPCOUNT, [5], 2)
    arithmetic_test(Op.POPCOUNT, [0b10101010], 4)
    arithmetic_test(Op.POPCOUNT, [1 << 7], 1)
    arithmetic_test(Op.POPCOUNT, [2**8-1], 8)
    arithmetic_test(Op.POPCOUNT, [2**16-1], 16, input_size=2)
    arithmetic_test(Op.POPCOUNT, [2**32-1], 32, input_size=4)
    arithmetic_test(Op.POPCOUNT, [2**64-1], 64, input_size=8)
