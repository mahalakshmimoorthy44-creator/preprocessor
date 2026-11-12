# preprocessor
c programming preprocessor project
# PREPROCESSOR - mypreprocessor

## Objective
Develop a preprocessor tool named `mypreprocessor` that processes a C source file by performing comment removal, file inclusion, and macro substitution. It generates an extended source file with `.i` extension.

## Features
1. **Comment Removal**
   - Removes single-line comments `//`
   - Removes multi-line comments `/* ... */`
   - Preserves structure and readability of remaining code.

2. **File Inclusion**
   - When `#include <filename>` is found, opens that file.
   - Replaces the `#include` line with contents of included file in output.

3. **Macro Substitution**
   - When `#define` is found, stores the macro definition.
   - Replaces all subsequent usages with defined value.
   - Supports simple macros e.g. `#define PI 3.14`
   - Supports macros with arguments e.g. `#define SQUARE(x) ((x)*(x))`

## Project Structure - Modular Programming
- `main.c` - Main program, takes input filename from command-line
- `comment_handler.c / .h` - Comment removal logic
- `file_inclusion.c / .h` - File inclusion logic
- `macro_handler.c / .h` - Macro substitution logic
- `final.c` - Final output generation
- `myheader.h` - Common headers
- `Makefile` - Build file

## Circuit Details
Not Applicable. This is a pure software project. No hardware / circuit required. Implemented and tested on Linux (Ubuntu) using GCC.

## How to Build and Run

1. Build:
   make

2. Run:
   ./mypreprocessor inputfile.c

3. Output:
   After processing, a new file `inputfile.i` will be created.

## Example
Input: `inputfile.c`
Command: `./mypreprocessor inputfile.c`
Output: `inputfile.i`

## Tools Used
- Language: C
- OS: Linux (Ubuntu 18.04 in VirtualBox)
- Compiler: GCC
- Build Tool: Make


