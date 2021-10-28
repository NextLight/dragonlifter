from typing import TextIO

class CodeEmitter:
    def __init__(self, out: TextIO, *, indentation = '\t'):
        self.out = out
        self.indentation = indentation
        self.indentation_level = 0

    def emit(self, code: str) -> None:
        for l in code.splitlines():
            l = l.strip()
            if l.startswith('}'):
                self.out.write(self.indentation * (self.indentation_level - 1))
            else:
                self.out.write(self.indentation * self.indentation_level)
            self.out.write(l)
            self.out.write('\n')
            for c in l:
                if c == '{':
                    self.indentation_level += 1
                elif c == '}':
                    self.indentation_level -= 1
            assert self.indentation_level >= 0
