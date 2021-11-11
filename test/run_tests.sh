TEST_DIR=`dirname "$0"`
mypy --check-untyped-defs --exclude "^ghidra/" $TEST_DIR/..
pytest $TEST_DIR