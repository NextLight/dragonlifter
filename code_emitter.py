from typing import TextIO

class CodeEmitter:
    def __init__(self, out: TextIO, *, indentation = '\t', newline = '\n'):
        self.out = out
        self.indentation = indentation
        self.newline = newline
        self.indentation_level = 0

    def emit(self, code: str) -> None:
        lines = code.strip().splitlines()
        if not lines:
            self.out.write(self.newline)
            return
        for l in lines:
            l = l.strip()
            if l.startswith('}'):
                self.out.write(self.indentation * (self.indentation_level - 1))
            else:
                self.out.write(self.indentation * self.indentation_level)
            self.out.write(l)
            self.out.write(self.newline)
            for c in l:
                if c == '{':
                    self.indentation_level += 1
                elif c == '}':
                    self.indentation_level -= 1
            assert self.indentation_level >= 0
