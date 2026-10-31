#!/usr/bin/env bash
set -e

echo "=== Setting up JavaScript environment ==="
if ! command -v node >/dev/null 2>&1; then
    echo "Error: node is not installed." >&2
    exit 1
fi

node --version
echo "Running test execution..."
node tests/test_procurement.js
echo "JavaScript setup complete and verified!"
