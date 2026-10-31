#!/usr/bin/env bash
set -e

echo "=== Setting up Python environment ==="
if ! command -v python3 >/dev/null 2>&1; then
    echo "Error: python3 is not installed." >&2
    exit 1
fi

python3 --version
echo "Running test execution..."
PYTHONPATH=procurement_system python3 -m unittest discover -s procurement_system/tests
echo "Python setup complete and verified!"
