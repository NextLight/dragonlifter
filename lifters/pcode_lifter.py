import typing
from enum import Enum, auto
from typing import Callable, Optional

if typing.TYPE_CHECKING:
    from dragonlifter import Dragonlifter

from ghidra_types import *
from .core_helper import VarKind


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

class PcodeLifter:
    def __init__(self, lifter: "Dragonlifter", pcode: Pcode, instruction_address: int, pcode_index: int):
        self.lifter = lifter
        self.core = lifter.core
        self.pcode = pcode
        self.instruction_address = instruction_address
        self.pcode_index = pcode_index

        self.referenced_pcode_labels: set[int] = set()

    def lift(self) -> str:
        f = self.find_pcode_lifter_function()
        args = self.arguments_to_lifter_function(f)
        return f(*args)

    def find_pcode_lifter_function(self) -> Callable[..., str]:
        try:
            return getattr(self, f'_{self.pcode.op.name.lower()}')
        except:
            raise NotImplementedError(f'Opcode {self.pcode.op.name} is not implemented yet. {self.pcode}')

    def arguments_to_lifter_function(self, f: Callable) -> list[Var]:
        args = []
        inputs_count = 0
        output_count = 0
        for name in f.__code__.co_varnames[1:f.__code__.co_argcount]:
            t = f.__annotations__[name]
            if issubclass(t, Output):
                arg = t(**self.pcode.output.__dict__)
                output_count += 1
            elif issubclass(t, Input):
                arg = t(**self.pcode.input[inputs_count].__dict__)
                inputs_count += 1
            else:
                assert False
            if arg.constraint_size is not None:
                assert arg.size == arg.constraint_size, f"The size of the varnode was {arg.size} but should have been {arg.constraint_size}."
            args.append(arg)
        if output_count == 0:
            assert self.pcode.output is None
        elif output_count == 1:
            assert self.pcode.output is not None
        else:
            assert False, "OPs cannot have multiple outputs"
        assert len(self.pcode.input) == inputs_count
        return args


    def size_and_kind_to_type(self, size: int, kind: VarKind) -> str:
        return self.core.size_and_kind_to_type(size, kind)

    def field(self, var: Var) -> str:
        return self.core.field_name(var.size, var.kind)

    def instruction_label(self, address: int):
        return self.core.instruction_label(address)

    def relative_pcode_label(self, delta: int):
        idx = self.pcode_index + delta
        self.referenced_pcode_labels.add(idx)
        return self.core.pcode_label(self.instruction_address, idx)

    def address_memory(self, space: Var, pointer_to_address: Var, size: int, kind: VarKind):
        assert space.type == VarnodeType.CONSTANT
        # TODO: handle the space ID
        # TODO: multiply the address by the space ID wordsize
        # TODO: assert that pointer_to_address.size == ptr size of the address space
        return f'RAM({self.var(pointer_to_address)}).{self.core.field_name(size, kind)}'
    
    def constant(self, var: Var) -> str:
        n = hex(var.value) if var.value >= 256 else str(var.value)
        t = self.size_and_kind_to_type(var.size, var.kind)
        if var.kind == VarKind.FLOATING:
            return f'((varnode_t){{.{self.core.field_name(var.size, VarKind.UNSIGNED)}={n}}}).{self.field(var)}'
        return f'(({t}){n})'

    def temp_var(self, var: Var) -> str:
        name = self.core.temp_variable(var.value)
        return f'{name}.{self.field(var)}'

    def register(self, var: Var) -> str:
        return self.lifter.core.register_name(var.value, var.size, var.kind)

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

    def _load(self, out: Output, in0: Input, in1: Input):
        assert in0.type == VarnodeType.CONSTANT
        return f'{self.var(out)} = {self.address_memory(in0, in1, out.size, out.kind)};'

    def _store(self, in0: Input, in1: Input, in2: Input):
        assert in0.type == VarnodeType.CONSTANT
        return f'{self.address_memory(in0, in1, in2.size, in2.kind)} = {self.var(in2)};'

    def _branch(self, in0: Input):
        if in0.type == VarnodeType.RAM:
            return f'goto {self.instruction_label(in0.value)};'
        elif in0.type == VarnodeType.CONSTANT:
            return f'goto {self.relative_pcode_label(in0.value)};'

    def _cbranch(self, in0: Input, in1: Input):
        return f'if ({self.var(in1)}) {self._branch(in0)}'

    #def _branchind(self): raise NotImplementedError("P-code BRANCHIND is not implemented yet.")
    #def _call(self): raise NotImplementedError("P-code CALL is not implemented yet.")
    #def _callind(self): raise NotImplementedError("P-code CALLIND is not implemented yet.")
    #def _callother(self): raise NotImplementedError("P-code CALLOTHER is not implemented yet.")
    #def _return(self): raise NotImplementedError("P-code RETURN is not implemented yet.")

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
        return f'{self.var(out)} = ({self.size_and_kind_to_type(in0.size, VarKind.UNSIGNED)})({self.var(in0)} + {self.var(in1)}) < {self.var(in0)};'

    def _int_scarry(self, out: OutputBool, in0: InputSigned, in1: InputSigned):
        assert in0.size == in1.size
        # TODO: improve this
        return (
            f'{self.var(out)} = '
            f'SIGN({in0.size}, {self.var(in0)}) == SIGN({in1.size}, {self.var(in1)}) && '
            f'SIGN({in0.size}, ({self.size_and_kind_to_type(in0.size, VarKind.SIGNED)})({self.var(in0)} + {self.var(in1)})) != SIGN({in1.size}, {self.var(in1)});'
        )

    def _int_sborrow(self, out: OutputBool, in0: InputSigned, in1: InputSigned):
        assert in0.size == in1.size
        # TODO: improve this
        return (
            f'{self.var(out)} = '
            f'SIGN({in0.size}, {self.var(in0)}) != SIGN({in1.size}, {self.var(in1)}) && '
            f'SIGN({in0.size}, ({self.size_and_kind_to_type(in0.size, VarKind.SIGNED)})({self.var(in0)} - {self.var(in1)})) == SIGN({in1.size}, {self.var(in1)});'
        )

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
        return f'{self.var(out)} = ISNAN({in0.size}, {self.var(in0)});'

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

    #def _multiequal(self): raise NotImplementedError("P-code MULTIEQUAL is not implemented yet.")
    #def _indirect(self): raise NotImplementedError("P-code INDIRECT is not implemented yet.")

    def _piece(self, out: Output, in0: Input, in1: Input):
        assert in0.size + in1.size == out.size
        return f'{self.var(out)} = {self.var(in0)} * {hex(2 ** (in1.size * self.core.byte_size))} | {self.var(in1)};'

    def _subpiece(self, out: Output, in0: Input, in1: Input):
        assert in1.type == VarnodeType.CONSTANT
        return f'{self.var(out)} = ({self.var(in0)} / {hex(2 ** (in1.value * self.core.byte_size))});'

    #def _cast(self): raise NotImplementedError("P-code CAST is not implemented yet.")
    #def _ptradd(self): raise NotImplementedError("P-code PTRADD is not implemented yet.")
    #def _ptrsub(self): raise NotImplementedError("P-code PTRSUB is not implemented yet.")
    #def _segmentop(self): raise NotImplementedError("P-code SEGMENTOP is not implemented yet.")
    #def _cpoolref(self): raise NotImplementedError("P-code CPOOLREF is not implemented yet.")
    #def _new(self): raise NotImplementedError("P-code NEW is not implemented yet.")
    #def _insert(self): raise NotImplementedError("P-code INSERT is not implemented yet.")
    #def _extract(self): raise NotImplementedError("P-code EXTRACT is not implemented yet.")

    def _popcount(self, out: Output, in0: Input):
        return f'{self.var(out)} = POPCOUNT({in0.size}, {self.var(in0)});'
