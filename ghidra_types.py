import json
from dataclasses import Field, dataclass, is_dataclass
from enum import Enum, IntEnum, auto
from typing import get_args, get_origin

class VarnodeType(Enum):
    @staticmethod
    def _generate_next_value_(name, start, count, last_values):
        return name.lower()

    TEMP = auto()
    REGISTER = auto()
    CONSTANT = auto()
    RAM = auto()

    def __repr__(self):
        return self.name

class Op(IntEnum):
    UNIMPLEMENTED = 0
    COPY = 1
    LOAD = 2
    STORE = 3

    BRANCH = 4
    CBRANCH = 5
    BRANCHIND = 6

    CALL = 7
    CALLIND = 8
    CALLOTHER = 9
    RETURN = 10

    INT_EQUAL = 11
    INT_NOTEQUAL = 12
    INT_SLESS = 13
    INT_SLESSEQUAL = 14
    INT_LESS = 15

    INT_LESSEQUAL = 16
    INT_ZEXT = 17
    INT_SEXT = 18
    INT_ADD = 19
    INT_SUB = 20
    INT_CARRY = 21
    INT_SCARRY = 22
    INT_SBORROW = 23
    INT_2COMP = 24
    INT_NEGATE = 25
    INT_XOR = 26
    INT_AND = 27
    INT_OR = 28
    INT_LEFT = 29
    INT_RIGHT = 30
    INT_SRIGHT = 31
    INT_MULT = 32
    INT_DIV = 33
    INT_SDIV = 34
    INT_REM = 35
    INT_SREM = 36

    BOOL_NEGATE = 37
    BOOL_XOR = 38
    BOOL_AND = 39
    BOOL_OR = 40

    FLOAT_EQUAL = 41
    FLOAT_NOTEQUAL = 42
    FLOAT_LESS = 43
    FLOAT_LESSEQUAL = 44

    FLOAT_NAN = 46

    FLOAT_ADD = 47
    FLOAT_DIV = 48
    FLOAT_MULT = 49
    FLOAT_SUB = 50
    FLOAT_NEG = 51
    FLOAT_ABS = 52
    FLOAT_SQRT = 53

    FLOAT_INT2FLOAT = 54
    FLOAT_FLOAT2FLOAT = 55
    FLOAT_TRUNC = 56
    FLOAT_CEIL = 57
    FLOAT_FLOOR = 58
    FLOAT_ROUND = 59

    MULTIEQUAL = 60
    INDIRECT = 61
    PIECE = 62
    SUBPIECE = 63

    CAST = 64
    PTRADD = 65
    PTRSUB = 66
    SEGMENTOP = 67
    CPOOLREF = 68
    NEW = 69
    INSERT = 70
    EXTRACT = 71
    POPCOUNT = 72

@dataclass(frozen=True)
class Varnode:
    type: VarnodeType
    value: int
    size: int

@dataclass(frozen=True)
class Pcode:
    op: Op
    output: Varnode
    input: list[Varnode]

@dataclass(frozen=True)
class Instruction:
    address: int
    asm: str
    pcodes: list[Pcode]

@dataclass(frozen=True)
class Function:
    name: str
    address: int
    instructions: list[Instruction]

@dataclass(frozen=True)
class BlockInfo:
    name: str
    address_space_id: int
    start: int
    end: int
    @property
    def size(self): return self.end - self.start

@dataclass(frozen=True)
class Memory:
    blocks_info: list[BlockInfo]
    compressed_buffer: str

@dataclass(frozen=True)
class Register:
    name: str
    size: int

@dataclass(frozen=True)
class RegistersBlock:
    offset: int
    registers: list[Register]

@dataclass(frozen=True)
class AddressSpace:
    name: str
    id: int

@dataclass(frozen=True)
class Program:
    functions: list[Function]
    op_names: list[str]
    address_spaces: list[tuple]
    registers_blocks: list[RegistersBlock]
    memory: Memory

    @staticmethod
    def load(f) -> "Program":
        return _map_object_to_dataclass(json.load(f), Program)

def _map_object_to_dataclass(o, cls_type: type):
    if o is None:
        return None
    elif is_dataclass(cls_type):
        cls_fields: dict[str, Field] = getattr(cls_type, '__dataclass_fields__')
        if isinstance(o, list):
            return cls_type(*(_map_object_to_dataclass(v, f.type) for v, f in zip(o, cls_fields.values())))
        elif isinstance(o, dict):
            return cls_type(**{n: _map_object_to_dataclass(v, cls_fields[n].type) for n, v in o.items()})
        else:
            assert False, o
    elif issubclass(cls_type, Enum):
        return cls_type(o)
    elif get_origin(cls_type) == list:
        arg_type: type = get_args(cls_type)[0]
        out = [_map_object_to_dataclass(x, arg_type) for x in o]
        return out
    else:
        return o
