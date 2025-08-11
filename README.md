# BigInt Implementation

This project provides an implementation of a `BigInt` class in C++ for handling arbitrarily large integers. It includes various constructors, arithmetic operations, comparison operators, and utility functions like factorial, Fibonacci, and Catalan number calculations.

---

## Project Structure
bigint/
    include/
        BigInt.hpp       # Public header (class declaration)
    src/
        BigInt.cpp       # Implementation (method definitions)
    examples/
        main.cpp         # Example binary and usage
    tests/               # (optional) unit tests (e.g. GoogleTest)
        CMakeLists.txt       # (optional) CMake build file
        .gitignore
    README.md
    LICENSE

---

## Features

- **Constructors**:
  - Create a `BigInt` from an integer, string, or another `BigInt`.
- **Arithmetic Operations**:
  - Addition (`+`), Subtraction (`-`), Multiplication (`*`), Division (`/`).
- **Comparison Operators**:
  - Equality (`==`), Inequality (`!=`), Greater/Less Than (`>`, `<`), etc.
- **Utility Functions**:
  - Factorial of a number.
  - Nth Fibonacci number.
  - Nth Catalan number.

---

## How to Compile and Run

### Prerequisites
- A C++ compiler (e.g., `g++` from GCC).
- Ensure the compiler is added to your system's PATH.

### Steps to Compile
1. Open a terminal and navigate to the `src` directory:
   ```bash
   cd c:\Users\Admin\BIG-INT-implementation\src
   g++ -I../include BigInt.cpp examples/main.cpp -o BigIntExample
   ./BigIntExample.exe
   ```