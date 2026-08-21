<div align="center">

# 🧱 C++ Fundamentals & Syntax Experiments

### Language Syntax · Core Mechanics · OOP · Dynamic Memory

![C++](https://img.shields.io/badge/C%2B%2B-17%2F20-00599C?style=for-the-badge&logo=c%2B%2B&logoColor=white)
![Status](https://img.shields.io/badge/Status-Completed-success?style=for-the-badge)

*A structured laboratory of C++ syntax examples, modular programming paradigms, OOP concepts, pointer mechanics, and standard I/O.*

</div>

---

## 📖 Overview

The `0_syntax_codes` directory contains hands-on programs designed to master C++ language fundamentals before tackling complex Data Structures and Algorithms. The exercises transition from foundational input/output and data types to modular software design, object-oriented programming (OOP), templates, and manual heap memory management with pointers.

---

## 🗂️ Directory Structure

```text
0_syntax_codes/
├── 00_projects/
│   ├── modular/
│   │   ├── rect1.cpp             # Monolithic programming paradigm
│   │   ├── rect2.cpp             # Procedural / modular programming with structs
│   │   └── rect3.cpp             # Object-oriented paradigm (Rectangle class)
│   └── random/
│       ├── old_rand_num.cpp      # C-style rand() & srand()
│       ├── new_rand_num.cpp      # Modern C++ <random> library (mt19937)
│       ├── two_die_rolls.cpp     # Dice rolling simulation
│       ├── guessing_game.cpp     # User number guessing game
│       └── comp_guessing_game.cpp# Computer binary-search guessing game
│
├── 01_helloworld/
│   ├── main.cpp                  # Standard Hello World & console output
│   └── shape.cpp                 # Terminal ASCII shape rendering
│
├── 02_variables/
│   ├── introduction.cpp          # Variable declaration & assignment
│   ├── datatypes.cpp             # Primitive types (int, double, char, bool)
│   ├── const.cpp                 # const qualifiers & immutability
│   ├── operator.cpp              # Arithmetic, relational, and logical operators
│   ├── op_order.cpp              # Operator precedence & associativity rules
│   ├── swap.cpp                  # Value swapping (with temp variable)
│   ├── tax.cpp                   # Tax calculation practice
│   └── format.cpp                # Stream formatting & manipulation
│
├── 03_input/
│   ├── value.cpp                 # Standard cin input
│   ├── string_inp.cpp            # Reading strings with std::getline()
│   ├── temp_cnvrt.cpp            # Fahrenheit to Celsius temperature converter
│   └── mad_libs.cpp              # Interactive Mad Libs game
│
├── 04_strings/
│   └── main.cpp                  # std::string manipulation, concatenation & indexing
│
├── 05_numbers/
│   ├── circ_area.cpp             # Circle area calculation using constants
│   ├── math_func.cpp             # Mathematical functions from <cmath>
│   ├── narrowing.cpp             # Narrowing conversion analysis & prevention
│   └── other_bases.cpp           # Hexadecimal (0x), Octal (0), and Binary (0b) literals
│
├── 06_initializing_vars/
│   └── main.cpp                  # Initialization styles (direct, copy, uniform brace {})
│
├── 07_arrays/
│   └── array.cpp                 # Basic fixed-size 1D arrays & iteration
│
├── 08_class/
│   ├── main.cpp                  # Basic class definition, access specifiers & objects
│   ├── arithmetic.cpp            # Arithmetic class with member methods
│   ├── bank_ac.cpp               # Bank Account class with balance management
│   ├── bookClass.cpp             # Book catalog class
│   ├── fun.cpp                   # Friend functions & class helper methods
│   └── template.cpp              # Generic template class Template<T> with type overflow analysis
│
└── 09_pointers/
    └── dynamic.cpp               # Pointers, heap memory allocation (new/delete), dangling pointers
```

---

## 📚 Module Breakdown

### 1. `00_projects` · Programming Paradigms & Games
- **Modular Evolution**: Demonstrates the architectural evolution of software design using a rectangle calculation example:
  1. [`rect1.cpp`](./00_projects/modular/rect1.cpp): Monolithic code with all logic inside `main()`.
  2. [`rect2.cpp`](./00_projects/modular/rect2.cpp): Procedural programming using `struct Rectangle` and helper functions.
  3. [`rect3.cpp`](./00_projects/modular/rect3.cpp): Object-Oriented design encapsulating data members and member functions into `class Rectangle`.
- **Random Generators & Games**:
  - Compares legacy `rand()`/`srand(time(0))` with modern C++11 `<random>` engines (`std::mt19937`, `std::uniform_int_distribution`).
  - Interactive CLI guessing games implementing linear and binary search gameplay.

### 2. `01_helloworld` to `06_initializing_vars` · Fundamentals
- **I/O & Formatting**: Mastered `std::cout`, `std::cin`, `std::getline()`, and stream manipulators.
- **Type System & Operators**: Explored integer types, floating points, characters, operator precedence, narrowing conversions (e.g., assigning `double` to `int`), and modern uniform initialization `{}`.
- **Number Representations**: Binary (`0b1111`), Octal (`017`), Hexadecimal (`0xFF`), and mathematical operations via `<cmath>`.

### 3. `07_arrays` & `09_pointers` · Memory Mechanics
- **Stack Arrays**: Fixed-size contiguous stack allocation and bounds.
- **Dynamic Memory**: Allocating heap memory using `new` and releasing it via `delete` / `delete[]`, preventing memory leaks and avoiding dangling pointer hazards.

### 4. `08_class` · Object-Oriented Programming & Templates
- **Classes & Encapsulation**: Private/public access specifiers, constructors, destructors, getter/setter methods.
- **Class Templates (`template <class T>`)**: Generic programming in C++ allowing classes (like `Arithmetic<T>`) to work seamlessly with `int`, `double`, `float`, and `char`.
- **ASCII & Char Overflow**: Deep dive into signed `char` overflow boundaries ($-128$ to $127$) when adding character values.

---

## ⚙️ Compilation & Execution

Compile any source file in this folder using `clang++` or `g++`:

```bash
# Standard compilation
clang++ -std=c++17 <filename>.cpp -o output
./output

# Example: Run class template demo
clang++ -std=c++17 08_class/template.cpp -o template_demo
./template_demo
```

---

## 🔗 Related Sections

- 🔙 [Root Repository README](../README.md)
- ➡️ [Data Structures Implementations](../1_data_structures_code/README.md)
- 📝 [C++ Language Notes](../notes/README.md)
