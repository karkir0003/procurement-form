.PHONY: all run test setup clean

all: run

run:
	@PYTHONPATH=procurement_system python3 -m unittest discover -s procurement_system/tests

test: run

setup:
	@./setup.sh

clean:
	@find . -type d -name "__pycache__" -exec rm -rf {} + 2>/dev/null || true
	@find . -type f -name "*.pyc" -delete 2>/dev/null || true
