import sys

from ghidra_types import *

with open(sys.argv[1]) as dump_f:
    program = Program.load(dump_f)

for f in program.functions:
    print(f.name)
    for ins in f.instructions:
        print(' ', ins.asm)
        for pcode in ins.pcodes:
            print('   ', pcode.op, pcode.output, pcode.input)
    print()
