<div align="center">

# 📝 C++ Language Notes & Architecture Reference

### Language Concepts · Compiler Mechanics · OOP Principles · Memory Representations

![C++](https://img.shields.io/badge/C%2B%2B-Notes-00599C?style=for-the-badge&logo=c%2B%2B&logoColor=white)
![Status](https://img.shields.io/badge/Status-Reference%20Archive-success?style=for-the-badge)

*Quick-reference notes, concept summaries, syntax rules, and memory layout diagrams.*

</div>

---

## 📖 Directory Contents

```text
notes/
├── 00_intro.md                   # C++ history, applications, standards, and I/O comparison (C vs C++)
├── 01_whitespaces.md             # Compiler treatment of whitespace and formatting rules
├── 02_namespaces.md              # Namespace scoping, std namespace, and preventing name collisions
├── 03_namingconvention copy.md  # Naming conventions (camelCase, PascalCase, snake_case)
├── 04_class.md                   # Class vs Struct mechanics & ADT encapsulation principles
├── decimals.png                  # Floating point precision and IEEE-754 memory diagram
├── ints.png                      # Integer signed/unsigned bit layout and range diagrams
└── unibyte.png                   # Single-byte (8-bit) binary representation diagram
```

---

## 📚 Topics Summary

### 1. Introduction & Overview ([`00_intro.md`](./00_intro.md))
- Core language capabilities: high performance, direct hardware control, systems programming.
- Comparison of standard I/O between C (`printf`/`scanf`) and C++ (`std::cout`/`std::cin`).

### 2. Whitespaces & Formatting ([`01_whitespaces.md`](./01_whitespaces.md))
- How the compiler lexer handles spaces, tabs, and newlines.

### 3. Namespaces ([`02_namespaces.md`](./02_namespaces.md))
- The purpose of `namespace` in managing global scope and avoiding naming conflicts across large libraries.
- The standard library `std` namespace and when to use `using namespace std;` vs explicit `std::` scoping.

### 4. Naming Conventions ([`03_namingconvention copy.md`](./03_namingconvention%20copy.md))
- Consistency in code style across variables (`snake_case` or `camelCase`), classes (`PascalCase`), constants (`UPPER_SNAKE_CASE`), and member fields.

### 5. Classes, Structs & ADTs ([`04_class.md`](./04_class.md))
- Fundamental difference between `class` (default `private`) and `struct` (default `public`).
- The philosophy of Abstract Data Types (ADTs): bundling data representation with legal operations while hiding internal implementation details behind an access barrier.

### 6. Memory & Data Types Diagrams
- **Integers (`ints.png`)**: Memory sizes, signed two's complement representation, unsigned maximums.
- **Floating Points (`decimals.png`)**: `float` (32-bit single precision), `double` (64-bit double precision), sign, exponent, and mantissa layout.
- **Byte Mechanics (`unibyte.png`)**: 8-bit byte representation and bitwise positional weights ($2^0$ to $2^7$).

---

## 🔗 Related Sections

- 🔙 [Root Repository README](../README.md)
- 🧱 [C++ Syntax Fundamentals](../0_syntax_codes/README.md)
- 🧮 [Data Structures & Algorithms](../1_data_structures_code/README.md)
- 🧰 [Standard Template Library (STL)](../2_STL/README.md)
