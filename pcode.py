from enum import Enum, auto
from typing import Callable, Optional

from datatypes import *


BYTE_SIZE = 8
MAP_INT_SIZE_TO_TYPE = {1: 'char', 2: 'short', 4: 'int', 8: 'long long'}
MAP_FLOAT_SIZE_TO_TYPE = {4: 'float', 8: 'double', 10: 'long double'}

class VarKind(Enum):
    UNSIGNED = auto()
    SIGNED = auto()
    FLOATING = auto()

VAR_KIND_TO_FIELD_PREFIX = {VarKind.UNSIGNED: '', VarKind.SIGNED: 's', VarKind.FLOATING: 'f'}

class Var(Varnode):
    kind: VarKind
    constraint_size: Optional[int] = None
class Output(Var): kind = VarKind.UNSIGNED
class Input(Var): kind = VarKind.UNSIGNED
class OutputSigned(Output): kind = VarKind.SIGNED
class InputSigned(Input): kind = VarKind.SIGNED
class OutputFloating(Output): kind = VarKind.FLOATING
class InputFloating(Input): kind = VarKind.FLOATING
class OutputBool(Output): constraint_size = 1
class InputBool(Input): constraint_size = 1

class Pcode2c:
    def __init__(self, register_offset_and_size_to_name: dict[tuple[int, int], str]):
        self.register_offset_and_size_to_name = register_offset_and_size_to_name
        self.used_temps: set[str] = set()

    def dispatch(self, pcode: Pcode) -> str:
        f: Callable[..., str] = getattr(self, f'_{pcode.op.name.lower()}', None)
        if not f:
            raise Exception(f'Opcode {pcode.op.name} not implemented. {pcode=}')
        args = []
        inputs_count = 0
        output_count = 0
        for name in f.__code__.co_varnames[1:f.__code__.co_argcount]:
            t = f.__annotations__[name]
            if issubclass(t, Output):
                arg = t(**pcode.output.__dict__)
                output_count += 1
            elif issubclass(t, Input):
                arg = t(**pcode.input[inputs_count].__dict__)
                inputs_count += 1
            else:
                assert False
            if arg.constraint_size is not None:
                assert arg.size == arg.constraint_size, f"The size of the varnode was {arg.size} but should have been {arg.constraint_size}."
            args.append(arg)
        if output_count == 0:
            assert pcode.output is None
        elif output_count == 1:
            assert pcode.output is not None
        else:
            assert False, "OPs cannot have multiple outputs"
        assert len(pcode.input) == inputs_count
        return f(*args)


    def size_kind_to_type(self, size: int, kind: VarKind) -> str:
        if kind == VarKind.FLOATING:
            return MAP_FLOAT_SIZE_TO_TYPE[size]
        t = MAP_INT_SIZE_TO_TYPE[size]
        if kind == VarKind.UNSIGNED:
            t = 'unsigned ' + t
        return t
    
    def field_name(self, size: int, kind: VarKind) -> str:
        return f'_{size}{VAR_KIND_TO_FIELD_PREFIX[kind]}'

    def field(self, var: Var) -> str:
        return self.field_name(var.size, var.kind)
    
    def constant(self, var: Var) -> str:
        n = hex(var.value) if var.value >= 256 else str(var.value)
        t = self.size_kind_to_type(var.size, var.kind)
        if var.kind == VarKind.FLOATING:
            return f'((varnode_t){{.{self.field_name(var.size, VarKind.UNSIGNED)}={n}}}).{self.field(var)}'
        return f'(({t}){n})'

    def temp_var(self, var: Var) -> str:
        name = f'temp_{var.value}'
        self.used_temps.add(name)
        return f'{name}.{self.field(var)}'

    def register(self, var: Var) -> str:
        return self.register_offset_and_size_to_name[(var.value, var.size)]

    def var(self, var: Var) -> str:
        t = var.type
        if t == VarnodeType.CONSTANT:
            return self.constant(var)
        elif t == VarnodeType.TEMP:
            return self.temp_var(var)
        elif t == VarnodeType.REGISTER:
            return self.register(var)
        elif t == VarnodeType.RAM:
            return f'RAM({var.value}).{self.field(var)}'
        assert False, f'Varnode of type {t} not implemented. {var}'
    

    def _copy(self, out: Output, in0: Input):
        assert out.size == in0.size
        return f'{self.var(out)} = {self.var(in0)};'

    def _load(self):
        raise NotImplementedError("P-code LOAD is not implemented yet.")
    def _store(self):
        raise NotImplementedError("P-code STORE is not implemented yet.")
    def _branch(self):
        raise NotImplementedError("P-code BRANCH is not implemented yet.")
    def _cbranch(self):
        raise NotImplementedError("P-code CBRANCH is not implemented yet.")
    def _branchind(self):
        raise NotImplementedError("P-code BRANCHIND is not implemented yet.")
    def _call(self):
        raise NotImplementedError("P-code CALL is not implemented yet.")
    def _callind(self):
        raise NotImplementedError("P-code CALLIND is not implemented yet.")
    def _callother(self):
        raise NotImplementedError("P-code CALLOTHER is not implemented yet.")
    def _return(self):
        raise NotImplementedError("P-code RETURN is not implemented yet.")

    def _int_equal(self, out: OutputBool, in0: Input, in1: Input):
        assert in0.size == in1.size
        return f'{self.var(out)} = {self.var(in0)} == {self.var(in1)};'

    def _int_notequal(self, out: OutputBool, in0: Input, in1: Input):
        assert in0.size == in1.size
        return f'{self.var(out)} = {self.var(in0)} != {self.var(in1)};'

    def _int_sless(self, out: OutputBool, in0: InputSigned, in1: InputSigned):
        assert in0.size == in1.size
        return f'{self.var(out)} = {self.var(in0)} < {self.var(in1)};'

    def _int_slessequal(self, out: OutputBool, in0: InputSigned, in1: InputSigned):
        assert in0.size == in1.size
        return f'{self.var(out)} = {self.var(in0)} <= {self.var(in1)};'

    def _int_less(self, out: OutputBool, in0: Input, in1: Input):
        assert in0.size == in1.size
        return f'{self.var(out)} = {self.var(in0)} < {self.var(in1)};'

    def _int_lessequal(self, out: OutputBool, in0: Input, in1: Input):
        assert in0.size == in1.size
        return f'{self.var(out)} = {self.var(in0)} <= {self.var(in1)};'

    def _int_zext(self, out: Output, in0: Input):
        assert out.size > in0.size
        return f'{self.var(out)} = {self.var(in0)};'

    def _int_sext(self, out: OutputSigned, in0: InputSigned):
        assert out.size > in0.size
        return f'{self.var(out)} = {self.var(in0)};'

    def _int_add(self, out: Output, in0: Input, in1: Input):
        assert out.size == in0.size == in1.size
        return f'{self.var(out)} = {self.var(in0)} + {self.var(in1)};'

    def _int_sub(self, out: Output, in0: Input, in1: Input):
        assert out.size == in0.size == in1.size
        return f'{self.var(out)} = {self.var(in0)} - {self.var(in1)};'

    def _int_carry(self, out: OutputBool, in0: Input, in1: Input):
        assert in0.size == in1.size
        return f'{self.var(out)} = ({self.size_kind_to_type(in0.size, VarKind.UNSIGNED)})({self.var(in0)} + {self.var(in1)}) < {self.var(in0)};'

    def _int_scarry(self, out: OutputBool, in0: InputSigned, in1: InputSigned):
        assert in0.size == in1.size
        # TODO: improve this
        return f'{self.var(out)} = SIGN({self.var(in0)}) == SIGN({self.var(in1)}) && SIGN(({self.size_kind_to_type(in0.size, VarKind.SIGNED)})({self.var(in0)} + {self.var(in1)})) != SIGN({self.var(in1)});'

    def _int_sborrow(self, out: OutputBool, in0: InputSigned, in1: InputSigned):
        assert in0.size == in1.size
        # TODO: improve this
        return f'{self.var(out)} = SIGN({self.var(in0)}) != SIGN({self.var(in1)}) && SIGN(({self.size_kind_to_type(in0.size, VarKind.SIGNED)})({self.var(in0)} - {self.var(in1)})) == SIGN({self.var(in1)});'

    def _int_2comp(self, out: OutputSigned, in0: InputSigned):
        assert in0.size == out.size
        return f'{self.var(out)} = -{self.var(in0)};'

    def _int_negate(self, out: Output, in0: Input):
        assert in0.size == out.size
        return f'{self.var(out)} = ~{self.var(in0)};'

    def _int_xor(self, out: Output, in0: Input, in1: Input):
        assert out.size == in0.size == in1.size
        return f'{self.var(out)} = {self.var(in0)} ^ {self.var(in1)};'

    def _int_and(self, out: Output, in0: Input, in1: Input):
        assert out.size == in0.size == in1.size
        return f'{self.var(out)} = {self.var(in0)} & {self.var(in1)};'

    def _int_or(self, out: Output, in0: Input, in1: Input):
        assert out.size == in0.size == in1.size
        return f'{self.var(out)} = {self.var(in0)} | {self.var(in1)};'

    def _int_left(self, out: Output, in0: Input, in1: Input):
        assert out.size == in0.size
        return f'{self.var(out)} = {self.var(in0)} << {self.var(in1)};'

    def _int_right(self, out: Output, in0: Input, in1: Input):
        assert out.size == in0.size
        return f'{self.var(out)} = {self.var(in0)} >> {self.var(in1)};'

    def _int_sright(self, out: OutputSigned, in0: InputSigned, in1: Input):
        assert out.size == in0.size
        return f'{self.var(out)} = {self.var(in0)} >> {self.var(in1)};'

    def _int_mult(self, out: Output, in0: Input, in1: Input):
        assert out.size == in0.size == in1.size
        return f'{self.var(out)} = {self.var(in0)} * {self.var(in1)};'

    def _int_div(self, out: Output, in0: Input, in1: Input):
        assert out.size == in0.size == in1.size
        return f'{self.var(out)} = {self.var(in0)} / {self.var(in1)};'

    def _int_sdiv(self, out: OutputSigned, in0: InputSigned, in1: InputSigned):
        assert out.size == in0.size == in1.size
        return f'{self.var(out)} = {self.var(in0)} / {self.var(in1)};'

    def _int_rem(self, out: Output, in0: Input, in1: Input):
        assert out.size == in0.size == in1.size
        return f'{self.var(out)} = {self.var(in0)} % {self.var(in1)};'

    def _int_srem(self, out: OutputSigned, in0: InputSigned, in1: InputSigned):
        assert out.size == in0.size == in1.size
        return f'{self.var(out)} = {self.var(in0)} % {self.var(in1)};'

    def _bool_negate(self, out: OutputBool, in0: InputBool):
        return f'{self.var(out)} = !{self.var(in0)};'

    def _bool_xor(self, out: OutputBool, in0: InputBool, in1: InputBool):
        return f'{self.var(out)} = !{self.var(in0)} != !{self.var(in1)};'

    def _bool_and(self, out: OutputBool, in0: InputBool, in1: InputBool):
        return f'{self.var(out)} = {self.var(in0)} && {self.var(in1)};'

    def _bool_or(self, out: OutputBool, in0: InputBool, in1: InputBool):
        return f'{self.var(out)} = {self.var(in0)} || {self.var(in1)};'

    def _float_equal(self, out: OutputBool, in0: InputFloating, in1: InputFloating):
        assert in0.size == in1.size
        return f'{self.var(out)} = {self.var(in0)} == {self.var(in1)};'

    def _float_notequal(self, out: OutputBool, in0: InputFloating, in1: InputFloating):
        assert in0.size == in1.size
        return f'{self.var(out)} = {self.var(in0)} != {self.var(in1)};'

    def _float_less(self, out: OutputBool, in0: InputFloating, in1: InputFloating):
        assert in0.size == in1.size
        return f'{self.var(out)} = {self.var(in0)} < {self.var(in1)};'

    def _float_lessequal(self, out: OutputBool, in0: InputFloating, in1: InputFloating):
        assert in0.size == in1.size
        return f'{self.var(out)} = {self.var(in0)} <= {self.var(in1)};'

    def _float_nan(self, out: OutputBool, in0: InputFloating):
        return f'{self.var(out)} = ISNAN({self.var(in0)});'

    def _float_add(self, out: OutputFloating, in0: InputFloating, in1: InputFloating):
        assert in0.size == in1.size == out.size
        return f'{self.var(out)} = {self.var(in0)} + {self.var(in1)};'

    def _float_div(self, out: OutputFloating, in0: InputFloating, in1: InputFloating):
        assert in0.size == in1.size == out.size
        return f'{self.var(out)} = {self.var(in0)} / {self.var(in1)};'

    def _float_mult(self, out: OutputFloating, in0: InputFloating, in1: InputFloating):
        assert in0.size == in1.size == out.size
        return f'{self.var(out)} = {self.var(in0)} * {self.var(in1)};'

    def _float_sub(self, out: OutputFloating, in0: InputFloating, in1: InputFloating):
        assert in0.size == in1.size == out.size
        return f'{self.var(out)} = {self.var(in0)} - {self.var(in1)};'

    def _float_neg(self, out: OutputFloating, in0: InputFloating):
        assert in0.size == out.size
        return f'{self.var(out)} = -{self.var(in0)};'

    def _float_abs(self, out: OutputFloating, in0: InputFloating):
        assert in0.size == out.size
        return f'{self.var(out)} = FABS({in0.size}, {self.var(in0)});'

    def _float_sqrt(self, out: OutputFloating, in0: InputFloating):
        assert in0.size == out.size
        return f'{self.var(out)} = SQRT({in0.size}, {self.var(in0)});'

    def _float_int2float(self, out: OutputFloating, in0: InputSigned):
        return f'{self.var(out)} = {self.var(in0)};'

    def _float_float2float(self, out: OutputFloating, in0: InputFloating):
        assert in0.size != out.size
        return f'{self.var(out)} = {self.var(in0)};'

    def _float_trunc(self, out: OutputSigned, in0: InputFloating):
        return f'{self.var(out)} = {self.var(in0)};'

    def _float_ceil(self, out: OutputFloating, in0: InputFloating):
        assert in0.size == out.size
        return f'{self.var(out)} = CEIL({in0.size}, {self.var(in0)});'

    def _float_floor(self, out: OutputFloating, in0: InputFloating):
        assert in0.size == out.size
        return f'{self.var(out)} = FLOOR({in0.size}, {self.var(in0)});'

    def _float_round(self, out: OutputFloating, in0: InputFloating):
        assert in0.size == out.size
        return f'{self.var(out)} = ROUND({in0.size}, {self.var(in0)});'

    def _multiequal(self):
        raise NotImplementedError("P-code MULTIEQUAL is not implemented yet.")
    def _indirect(self):
        raise NotImplementedError("P-code INDIRECT is not implemented yet.")

    def _piece(self, out: Output, in0: Input, in1: Input):
        assert in0.size + in1.size == out.size
        return f'{self.var(out)} = {self.var(in0)} * {hex(2 ** (in1.size * BYTE_SIZE))} | {self.var(in1)};'

    def _subpiece(self, out: Output, in0: Input, in1: Input):
        assert in1.type == VarnodeType.CONSTANT
        return f'{self.var(out)} = ({self.var(in0)} / {hex(2 ** (in1.value * BYTE_SIZE))});'

    def _cast(self):
        raise NotImplementedError("P-code CAST is not implemented yet.")
    def _ptradd(self):
        raise NotImplementedError("P-code PTRADD is not implemented yet.")
    def _ptrsub(self):
        raise NotImplementedError("P-code PTRSUB is not implemented yet.")
    def _segmentop(self):
        raise NotImplementedError("P-code SEGMENTOP is not implemented yet.")
    def _cpoolref(self):
        raise NotImplementedError("P-code CPOOLREF is not implemented yet.")
    def _new(self):
        raise NotImplementedError("P-code NEW is not implemented yet.")
    def _insert(self):
        raise NotImplementedError("P-code INSERT is not implemented yet.")
    def _extract(self):
        raise NotImplementedError("P-code EXTRACT is not implemented yet.")

    def _popcount(self, out: Output, in0: Input):
        return f'{self.var(out)} = POPCOUNT({in0.size}, {self.var(in0)});'
