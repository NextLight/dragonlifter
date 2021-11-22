@echo off
mypy --check-untyped-defs --exclude ^ghidra/ %~dp0.. || goto error
pytest %~dp0 || goto error

:error
exit /b %errorlevel%