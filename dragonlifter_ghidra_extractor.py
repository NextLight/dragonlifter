# Extract the p-code of all the functions of the binary into a json.
#@author Sen
#@category Dragonlifter
#@keybinding 
#@menupath 
#@toolbar 
import json
import zlib
from base64 import b64encode
from collections import defaultdict

from ghidra.framework import OperatingSystem

PRETTY_PRINT = False

# keep this in sync with the one inside datatypes.py
class VarnodeType:
    TEMP = 'temp'
    REGISTER = 'register'
    CONSTANT = 'constant'
    RAM = 'ram'
try:
    # this won't be executed, it's just a trick to get code completion using the 'ghidra-stubs' module.
    from ghidra.ghidra_builtins import *
    import ghidra
    from typing import Union
    xrange = range
    VarnodeTuple = tuple[Union[VarnodeType.TEMP, VarnodeType.REGISTER, VarnodeType.CONSTANT, VarnodeType.RAM], int, int]
    PcodeTuple = tuple[int, VarnodeTuple, list[VarnodeTuple]]
    InstructionTuple = tuple[int, str, list[PcodeTuple]]
    FunctionTuple = tuple[str, int, list[InstructionTuple]]
    BlockInfoTuple = tuple[str, int, int, int]
    MemoryTuple = tuple[list[BlockInfoTuple], str]
    RegisterTuple = tuple[str, int]
    RegistersBlockTuple = tuple[int, list[RegisterTuple]]
    AddressSpaceTuple = tuple[str, int]
    ProgramTuple = tuple[list[FunctionTuple], list[str], list[tuple], list[RegistersBlockTuple], MemoryTuple]
except:
    pass

curr = currentProgram

def list_functions():
    # type: () -> list[ghidra.program.model.listing.Function]
    return curr.functionManager.getFunctions(True)

def list_instructions(f):
    # type: (ghidra.program.model.listing.Function) -> list[ghidra.program.model.listing.Instruction]
    return curr.listing.getInstructions(f.body, True)

def list_registers():
    # type: () -> list[ghidra.program.model.lang.Register]
    return curr.language.registers

def list_memory_blocks():
    # type: () -> list[ghidra.program.model.mem.MemoryBlock]
    return sorted(curr.memory.blocks, key=lambda b: b.start.offset)

def list_defined_op_names():
    # type: () -> list[str]
    lang = curr.language
    return map(lang.getUserDefinedOpName, xrange(lang.numberOfUserDefinedOpNames))

def list_address_spaces():
    # type: () -> list[ghidra.program.model.address.AddressSpace]
    return curr.addressFactory.addressSpaces


def parse_function(f, instructions):
    # type: (ghidra.program.model.listing.Function, list[ghidra.program.model.listing.Instruction]) -> FunctionTuple
    return f.name, f.entryPoint.offset, [parse_instruction(inst) for inst in instructions]

def parse_instruction(inst):
    # type: (ghidra.program.model.listing.Instruction) -> InstructionTuple
    pcodes = [parse_pcode(pcode) for pcode in inst.pcode]
    return inst.address.offset, str(inst), pcodes

def parse_pcode(pcode):
    # type: (ghidra.program.model.pcode.PcodeOp) -> PcodeTuple
    out_var = parse_varnode(pcode.output)
    in_vars = [parse_varnode(i) for i in pcode.inputs]
    return pcode.opcode, out_var, in_vars

def parse_varnode(varnode):
    # type: (ghidra.program.model.pcode.Varnode) -> VarnodeTuple
    if varnode is None:
        return None
    if varnode.unique:
        return VarnodeType.TEMP, varnode.offset, varnode.size
    elif varnode.register:
        return VarnodeType.REGISTER, varnode.offset, varnode.size
    elif varnode.constant:
        return VarnodeType.CONSTANT, varnode.offset, varnode.size
    elif varnode.isAddress() and varnode.getAddress().isMemoryAddress():
        addr = varnode.getAddress()
        space = addr.addressSpace.name
        if space == 'ram':
            return VarnodeType.RAM, varnode.offset, varnode.size
        else:
            assert False, 'Address spaces other than RAM are currently not supported. %r' % varnode
    else:
        assert False, 'Unknown varnode type. %r' % varnode

def parse_registers(registers):
    # type: (list[ghidra.program.model.lang.Register]) -> list[RegisterTuple]
    reg_groups = defaultdict(list) # type: dict[int, list[RegisterTuple]]
    for r in registers:
        reg_groups[r.offset].append((r.name, r.minimumByteSize))
    return reg_groups.items()

def parse_memory(memory_blocks):
    # type: (list[ghidra.program.model.mem.MemoryBlock]) -> MemoryTuple
    blocks_info = [] # type: list[BlockInfoTuple]
    buff = bytearray()
    for b in memory_blocks:
        if b.initialized:
            content = b.data.readAllBytes() # type: bytearray
        else:
            content = bytearray(b.size)
        assert len(content) == b.size, (len(content), b.size, b.start)
        assert b.end.offset + 1 - b.start.offset == b.size, (b.end.offset - b.start.offset, b.size)
        buff.extend(content)
        blocks_info.append((b.name, b.start.addressSpace.spaceID, b.start.offset, b.end.offset + 1))
    buff_bytes = bytes(buff)
    assert len(buff) == len(buff_bytes)
    return blocks_info, b64encode(zlib.compress(buff_bytes))

def parse_address_space(address_space):
    # type: (ghidra.program.model.address.AddressSpace) -> AddressSpaceTuple
    return address_space.name, address_space.spaceID


def extract_program_dict():
    return {
        'op_names': list_defined_op_names(),
        'address_spaces': [parse_address_space(a) for a in list_address_spaces()],
        'registers_blocks': parse_registers(list_registers()),
        'memory': parse_memory(list_memory_blocks()),
        'functions': [parse_function(f, list_instructions(f)) for f in list_functions()],
    }

exe_path = curr.executablePath
# workaround ghidra putting a slash in front of Windows paths
if OperatingSystem.CURRENT_OPERATING_SYSTEM == OperatingSystem.WINDOWS and exe_path[0] == "/":
    exe_path = exe_path[1:]
json_path = exe_path + '_dragonlifter.json'
with open(json_path, 'w') as f:
    json.dump(extract_program_dict(), f, check_circular=False, separators=(',', ': ') if PRETTY_PRINT else (',', ':'), indent=2 if PRETTY_PRINT else None)
print('p-code successfully extracted: %s' % json_path)
