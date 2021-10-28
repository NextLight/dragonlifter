TEST_DIR=`dirname "$0"`
mypy --check-untyped-defs $TEST_DIR/..
pytest $TEST_DIR