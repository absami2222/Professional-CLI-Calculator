# Professional CLI Calculator (C)

A polished command-line calculator implemented in C to demonstrate structured programming, robust input validation, and a professional CLI experience. Suitable as a portfolio project to showcase practical C skills and algorithmic problem solving.

## Features

- Basic operations: addition, subtraction, multiplication, division (supports continuous input)
- Scientific operations: power (x^y), square root, log10, sin, cos, tan (angles in degrees)
- Factorial for non-negative integers
- 2×2 matrix addition
- Smart type-sensitive output (prints integers when results are whole numbers)
- Comprehensive math error handling:
  - Division-by-zero protection
  - Undefined tangent detection (tan(90 + k×180))
  - Invalid sqrt/log inputs
  - Clear "Math Error" messages
- Navigation: clean CLI menus with back-to-main-menu support

## Design Goals

- Pure C (standard library + math.h)
- Clear, user-friendly CLI interaction
- Robust validation and domain checks for scientific functions
- Demonstrates control structures, functions, loops, and modular code

## Requirements

- C compiler (GCC recommended)
- Standard C library and math.h (link with -lm)

## Build & Run

This project now uses a traditional `src/`/`include/` layout and a `Makefile` for convenience. From the workspace root:

```sh
# compile the program using make
make

# build and execute in one step
make run

# clean build artifacts
make clean
```

Run the unit tests (requires gcc):

```sh
gcc -Iinclude tests/test_factorial.c src/factorial.c -o tests/test_factorial
./tests/test_factorial
```

If you prefer to compile manually (without make):

```sh
gcc -Iinclude src/*.c -o calculator -lm
```

Then run with `./calculator` (Unix) or `calculator.exe` (Windows).

## Usage Overview

1. Run the program.
2. Select an operation from the main menu.
3. For basic operations, input numbers continuously; type `=` to compute the result.
4. For scientific trig functions, input angles in degrees.
5. Enter `0` at supported prompts to return to the main menu.
6. Results are shown in integer form when whole numbers and as floating-point when needed.

## Validation & Error Handling

- Rejects invalid domains (e.g., sqrt of negative numbers, log10 of non-positive values).
- Detects and reports undefined tangent inputs.
- Prevents division by zero and reports math errors similar to real calculators.

## Suggested File Structure

- `src/`               — C source files
  - `main.c`           — entry point and menu logic
  - `operations.c`     — basic & scientific operations
  - `factorial.c`      — factorial logic and menu
  - `matrix.c`         — matrix addition
  - `utils.c`          — platform utilities
- `include/`           — headers
  - `calculator.h`     — common declarations and macros
- `Makefile`           — build automation
- `tests/`             — basic unit tests (uses assertions)
- `README.md`          — project README
- `LICENSE`            — project license (optional)

## Contribution

Contributions, bug reports, and enhancements are welcome. Open issues or pull requests on the repository.

## License

Suggested: MIT License — add LICENSE file if you want to publish this repository.

## Author

Abu Bakar Sami  
GitHub: https://github.com/absami2222  
LinkedIn: https://www.linkedin.com/in/absami2222