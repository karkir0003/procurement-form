# Procurement Form System - AI Assisted Design

Welcome to the **Procurement Form System** design round!

### Quick Start Instructions

1. **Choose your language** and change into its directory:
   ```bash
   cd python        # For Python (standard unittest)
   cd javascript    # For JavaScript (Node.js)
   cd java          # For Java (JUnit 5)
   cd c++           # For C++ (Google Test)
   ```

2. **Verify / install environment** (optional):
   ```bash
   make setup
   ```
   *(Checks compilers/runtimes and automatically installs any missing dependencies).*

3. **Run your tests**:
   ```bash
   make
   ```
   *(Runs the test suite).*

4. **Clean artifacts** (optional):
   ```bash
   make clean
   ```

---

## Directory & File Reference

| Language | Directory | Test Framework | Source Package | Test Suite |
| :--- | :--- | :--- | :--- | :--- |
| **Python** | `python/` | `unittest` (standard library, zero install) | [`python/procurement_system/procurement/`](python/procurement_system/procurement/) | [`python/procurement_system/tests/test_procurement.py`](python/procurement_system/tests/test_procurement.py) |
| **JavaScript** | `javascript/` | Built-in Node assertions (zero dependencies) | [`javascript/procurement/`](javascript/procurement/) | [`javascript/tests/test_procurement.js`](javascript/tests/test_procurement.js) |
| **Java** | `java/` | `JUnit 5` (bundled standalone runner, zero build tool setup) | [`java/src/procurement/`](java/src/procurement/) | [`java/tests/TestProcurement.java`](java/tests/TestProcurement.java) |
| **C++** | `c++/` | `Google Test` (auto-provisioned via setup.sh) | [`c++/include/procurement/`](c++/include/procurement/) | [`c++/tests/test_procurement.cpp`](c++/tests/test_procurement.cpp) |

Every language directory contains a standardized `Makefile` with identical targets (`make`, `make setup`, `make clean`) so your workflow is consistent regardless of which language you choose.
