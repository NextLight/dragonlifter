mypy --check-untyped-defs --exclude ^ghidra/ %~dp0..
pytest %~dp0