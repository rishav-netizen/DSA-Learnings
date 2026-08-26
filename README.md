<div align="center">

# ⚙️ C++ · Data Structures & Algorithms

### C++ Fundamentals · DSA from Scratch · STL · Notes

![C++](https://img.shields.io/badge/C%2B%2B-00599C?style=for-the-badge&logo=c%2B%2B&logoColor=white)
![DSA](https://img.shields.io/badge/Data_Structures_%26_Algorithms-2F74C0?style=for-the-badge)
![STL](https://img.shields.io/badge/STL-Standard_Template_Library-00599C?style=for-the-badge)
![Git](https://img.shields.io/badge/Git-F05032?style=for-the-badge&logo=git&logoColor=white)
![GitHub](https://img.shields.io/badge/GitHub-181717?style=for-the-badge&logo=github&logoColor=white)

*A structured collection of my C++ fundamentals, data structure implementations, algorithms, STL practice, and study notes.*

</div>

---

## 📖 About This Repository

This repository documents my journey through **C++ and Data Structures & Algorithms**. I am using it to build a strong foundation in C++, understand how common data structures work internally, implement them from scratch, and eventually compare those implementations with the containers and algorithms provided by the **C++ Standard Template Library (STL)**.

A major part of the DSA material follows **Abdul Bari's _Mastering Data Structures & Algorithms using C and C++_** course on Udemy.

### 🎓 Primary Course

**Mastering Data Structures & Algorithms using C and C++ — Abdul Bari**  
[View Course on Udemy](https://www.udemy.com/course/datastructurescncpp/)

> The repository is my own learning workspace and contains my implementations, experiments, exercises, and notes while studying the concepts.

---

## 🗂️ Repository Structure

```text
c++/
├── 0_syntax_codes/               # C++ Fundamentals, I/O, OOP, Memory & Templates
│   ├── 00_projects/              # Modular evolution (monolithic -> procedural -> OOP) & games
│   ├── 01_helloworld/            # Console outputs & ASCII shapes
│   ├── 02_variables/             # Datatypes, operators, precedence, swap, formatting
│   ├── 03_input/                 # cin, getline, conversions & games
│   ├── 04_strings/               # std::string manipulation
│   ├── 05_numbers/               # Number bases, math functions & narrowing conversions
│   ├── 06_initializing_vars/     # Direct, copy, and uniform {} initialization
│   ├── 07_arrays/                # 1D fixed-size arrays
│   ├── 08_class/                 # Classes, methods, banking, and template class Arithmetic<T>
│   ├── 09_pointers/              # Heap dynamic memory allocation (new/delete)
│   └── README.md                 # Detailed guide to C++ fundamentals
│
├── 1_data_structures_code/       # Low-Level DSA Implementations from Scratch
│   ├── 00_recursion/             # Recursion types, call stack trees, 7 classical problems & quiz
│   │   ├── 01_TailHead/          # Ascending vs descending execution phases
│   │   ├── 02_StaticGlobal/      # Static & global variables in recursion
│   │   ├── 03_Tail/              # Pure tail recursion
│   │   ├── 04_Head/              # Pure head recursion
│   │   ├── 05_Tree/              # Tree recursion (multiple recursive calls)
│   │   ├── 06_IndirectRecursion/ # Indirect circular recursion
│   │   ├── 07_NestedRecursion/   # Nested recursive calls
│   │   ├── Examples/             # Naturals sum, Factorial, Fast Power, Taylor, Fibonacci, nCr, Hanoi
│   │   ├── Quiz 1/               # Recursion tracing quiz
│   │   └── README.md             # Deep dive into recursion
│   │
│   ├── 01_arraysRepresentation/  # Memory layouts, 2D arrays (3 methods), n-D formulas & Horner's rule
│   │   ├── 00_declaration/       # Declaration & initialization
│   │   ├── 01_staticDynamic/     # Stack vs Heap memory arrays
│   │   ├── 02_arraySizeIncrement/# Dynamic array resizing mechanics
│   │   ├── 03_2DimensionalArray/ # 3 methods for 2D array representation in memory
│   │   ├── 04_1DarrayIndexFormula/# 1D array index-to-address calculation
│   │   ├── 05_2DarrayIndexFormula/# Row-Major & Column-Major address calculations
│   │   ├── 06_nDarrayIndexFormula/# n-D addressing & Horner's Rule optimization
│   │   ├── 07_3DarrayIndexFormula/# 3D addressing formulas
│   │   ├── Quiz 2/               # Memory and addressing quiz
│   │   └── README.md             # Deep dive into array memory models & math
│   │
│   ├── 02_arrayADT/              # Complete Array Abstract Data Type & Challenges
│   │   ├── Functions/            # 17 core operations (Insert, Delete, Search, Merge, Set Ops, OOP Class)
│   │   ├── StudentChallenge/     # 5 challenges (Missing elements, Duplicates, Two-Sum, Min/Max Once)
│   │   ├── Quiz/                 # Array ADT interactive quiz
│   │   ├── notes.txt             # Core ADT definitions
│   │   └── README.md             # Complete Array ADT operations & complexity guide
│   │
│   ├── 03_string/                # Strings, character arrays, ASCII encoding & algorithms
│   │   ├── 00_introduction/      # ASCII table (0-127), control characters, and encoding notes
│   │   ├── 01_charDeclaration/   # Character declaration, 1-byte storage, valid/invalid assignments
│   │   ├── 02_charArrayDeclaration/# Character array initializations & partial zero-filling
│   │   ├── 03_strDeclaration/    # Null terminator '\0', string literals, capacity vs length
│   │   ├── 04_strlen/            # Length calculation via sentinel loop: O(n)
│   │   ├── 05_changeCase/        # Uppercase, Lowercase, and Toggle case conversions (+-32)
│   │   ├── 06_countVowelandWords/# Vowel, consonant, and multi-space word counting
│   │   ├── 07_validation/        # Alphanumeric string validation
│   │   ├── 08_reversing/         # Reversal (00_auxillary & 01_inplace swap)
│   │   ├── 09_comparing/         # Comparison (00_compare & 01_palindrome check)
│   │   ├── 10_duplicates/        # Finding duplicates using bitwise operations (masking & merging)
│   │   ├── 11_anagram/           # Anagram checking via hash table frequency counting
│   │   └── README.md             # Complete Strings guide & complexity matrix
│   │
│   └── README.md                 # Overview of all DSA implementations
│
├── 2_STL/                        # C++ Standard Template Library
│   └── README.md                 # STL containers, iterators, algorithms & comparison guide
│
├── notes/                        # C++ Language Notes & Architecture
│   ├── 00_intro.md to 04_class.md# Notes on namespaces, whitespaces, OOP, syntax
│   ├── *.png                     # Memory layout & binary diagrams
│   └── README.md                 # Notes catalog and language guide
│
└── README.md                     # Root repository overview (this file)
```

---

## 🧱 C++ Fundamentals

The [`0_syntax_codes`](./0_syntax_codes/README.md) directory contains small programs and experiments used to learn and revise the language itself before applying it to larger DSA implementations.

| # | Topic | Folder | Status | Key Highlights |
| :---: | --- | --- | :---: | --- |
| **00** | Projects | [`00_projects`](./0_syntax_codes/00_projects/) | ✅ Done | Monolithic $\to$ Procedural $\to$ OOP (`rect3.cpp`), CLI guessing games |
| **01** | Hello World | [`01_helloworld`](./0_syntax_codes/01_helloworld/) | ✅ Done | Basic console output & ASCII art shapes |
| **02** | Variables | [`02_variables`](./0_syntax_codes/02_variables/) | ✅ Done | Datatypes, constants, operators, precedence, swap |
| **03** | Input | [`03_input`](./0_syntax_codes/03_input/) | ✅ Done | `cin`, `getline()`, temperature converter, Mad Libs |
| **04** | Strings | [`04_strings`](./0_syntax_codes/04_strings/) | ✅ Done | `std::string` indexing, concatenation |
| **05** | Numbers | [`05_numbers`](./0_syntax_codes/05_numbers/) | ✅ Done | Number bases (hex, octal, binary), `<cmath>`, narrowing conversions |
| **06** | Variable Initialization | [`06_initializing_vars`](./0_syntax_codes/06_initializing_vars/) | ✅ Done | Direct, copy, and uniform `{}` initialization |
| **07** | Arrays | [`07_arrays`](./0_syntax_codes/07_arrays/) | ✅ Done | Basic fixed-size stack arrays |
| **08** | Classes & Templates | [`08_class`](./0_syntax_codes/08_class/) | ✅ Done | OOP encapsulation, `Arithmetic<T>` generic template, char overflow |
| **09** | Pointers | [`09_pointers`](./0_syntax_codes/09_pointers/) | ✅ Done | Dynamic heap allocation (`new` / `delete[]`) |

👉 **Read the full guide:** [`0_syntax_codes/README.md`](./0_syntax_codes/README.md)

---

## 🧮 Data Structures & Algorithms

The [`1_data_structures_code`](./1_data_structures_code/README.md) directory contains implementations and exercises focused on understanding DSA concepts from the ground up.

### 00 · Recursion

👉 **Read the module guide:** [`00_recursion/README.md`](./1_data_structures_code/00_recursion/README.md)

- **Mechanics**: Calling phase (ascending) vs returning phase (descending), call stack activation records, static & global variables.
- **Classification**: Tail Recursion, Head Recursion, Tree Recursion, Indirect Recursion, and Nested Recursion.
- **Classical Problems**:
  1. Sum of first $N$ natural numbers ($O(n)$)
  2. Factorial ($O(n)$)
  3. Fast Exponentiation ($O(\log n)$)
  4. Taylor Series for $e^x$ (Standard, Static vars, and Horner's Rule in $O(n)$)
  5. Fibonacci Series (Iterative, Naive Recursive $O(2^n)$, and Memoized $O(n)$)
  6. Combinations $nCr$ (Factorial formula vs Pascal's Identity)
  7. Tower of Hanoi ($2^n - 1$ steps in $O(2^n)$)
- **Quiz 1**: Call stack tracing exercises and output analysis.

---

### 01 · Array Representation & Addressing Formulas

👉 **Read the module guide:** [`01_arraysRepresentation/README.md`](./1_data_structures_code/01_arraysRepresentation/README.md)

- **Memory Models**: Static (Stack) vs Dynamic (Heap) arrays, array capacity expansion via pointer redirection.
- **2D Array Representations**:
  1. *Method 1*: Pure stack allocation (`int A[3][4]`).
  2. *Method 2*: Stack array of pointers to heap rows (`int *A[3]`).
  3. *Method 3*: Double pointer heap allocation (`int **A`).
- **Addressing Formulas**:
  - **1D Array**: $Address(A[i]) = L_0 + (i - l) \times w$
  - **2D Array (Row-Major)**: $Address(A[i][j]) = L_0 + [(i - l_1) \times n + (j - l_2)] \times w$
  - **2D Array (Column-Major)**: $Address(A[i][j]) = L_0 + [(j - l_2) \times m + (i - l_1)] \times w$
  - **3D Array & n-D Array**: Generalized hypercube addressing and **Horner's Rule optimization** (reducing time from $O(n^2)$ down to $O(n)$ multiplications).
- **Quiz 2**: Memory address calculation and pointer arithmetic.

---

### 02 · Array ADT (Abstract Data Type)

👉 **Read the module guide:** [`02_arrayADT/README.md`](./1_data_structures_code/02_arrayADT/README.md)

- **17 Core Operations (`Functions/`)**:
  - `01 Display`, `02 Append`, `03 Insert`, `04 Delete`
  - `05 Search`: Normal linear search, Improved linear search (Transposition & Move to Head), Iterative & Recursive Binary Search ($O(\log n)$)
  - `06 Get`, `07 Set`, `08 Max/Min`, `09 Sum & Average` (Iterative & Recursive)
  - `10 Reverse`: Method 1 (auxiliary array) & Method 2 (two-pointer in-place swap)
  - `11 Shift & Rotate`: Left/Right Shift and Left/Right Circular Rotate
  - `12 Insert in Sorted Array` & `13 Check if Sorted`
  - `14 Rearrange Positive & Negative`: Two-pointer partition algorithm in $O(n)$
  - `15 Merge Sorted Arrays`: Linear two-finger merge in $\Theta(m + n)$
  - `16 Set Operations`: Union, Intersection, Difference & Membership on unsorted ($O(m \times n)$) and sorted arrays ($O(m + n)$)
  - `17 C++ Class`: Object-Oriented Array ADT with dynamic allocation, constructors, destructor, and methods
- **5 High-Frequency Student Challenges (`StudentChallenge/`)**:
  - `00 Find Missing Elements`: Single missing (sum formula & index diff), multiple missing, and single-pass Hash Table method ($O(n)$)
  - `01 Duplicates in Sorted Array`: Linear scan with counting & Hash Table frequency
  - `02 Duplicates in Unsorted Array`: Nested loops $O(n^2)$ with marking vs Hash Table $O(n)$
  - `03 Pair of Elements with Sum K (Two-Sum)`: Two-pointer $O(n)$ on sorted array vs Hash Table $O(n)$ on unsorted array
  - `04 Min & Max in Single Scan`: Minimized comparisons ($(n-1)$ best case, $2(n-1)$ worst case, $\approx 1.5n$ average)
- **Quiz**: Interactive dynamic memory Array ADT test program.

---

### 03 · Strings & Character Array Fundamentals

👉 **Read the module guide:** [`03_string/README.md`](./1_data_structures_code/03_string/README.md)

- **Memory & Representation**: Stack memory allocation, 1-byte storage, ASCII encoding table ($0 \dots 127$), valid vs invalid character assignments.
- **Character Arrays vs Strings**: 5 array initialization methods, partial zero-initialization, and the Null Terminator (`'\0'`) sentinel delimiter.
- **Core Operations & Algorithms**:
  - `04 String Length`: $O(n)$ traversal using sentinel loop.
  - `05 Change Case`: Uppercase, lowercase, and toggle case transformations using ASCII offset ($32$) and bitwise logic.
  - `06 Count Vowels, Consonants & Words`: Single-scan classification and multi-space word delimiter parsing.
  - `07 Validation`: Alphanumeric character validation ($O(n)$).
  - `08 Reversing`: Auxiliary buffer ($O(n)$ space) vs two-pointer in-place swap ($O(1)$ space).
  - `09 Comparing & Palindrome`: Case-insensitive lexicographical comparison and palindrome detection.
  - `10 Finding Duplicates`: Bitwise masking ($x \ \& \ H$), left shifting ($1 \ll (A[i]-97)$), and merging ($H \mid x$) in $O(n)$ time and $O(1)$ space ($4$ bytes) vs Hash Table.
  - `11 Anagram Checking`: Single hash table frequency increment/decrement technique ($O(n)$ time, $O(1)$ auxiliary space).

---

## 📚 DSA Roadmap

| Topic | Status | Detailed Documentation |
| :--- | :---: | :---: |
| **00 · Recursion** | ✅ Completed | [`00_recursion/README.md`](./1_data_structures_code/00_recursion/README.md) |
| **01 · Array Representation** | ✅ Completed | [`01_arraysRepresentation/README.md`](./1_data_structures_code/01_arraysRepresentation/README.md) |
| **02 · Array ADT** | ✅ Completed | [`02_arrayADT/README.md`](./1_data_structures_code/02_arrayADT/README.md) |
| **03 · Strings** | ⏳ In Progress | [`03_string/README.md`](./1_data_structures_code/03_string/README.md) |
| **04 · Matrices** | ⏳ Planned | Special matrices: Diagonal, Tri-diagonal, Symmetric, Triangular |
| **05 · Sparse Matrix & Polynomial** | ⏳ Planned | Coordinate list, linked representation, addition & multiplication |
| **06 · Linked Lists** | ⏳ Planned | Singly, Doubly, Circular, operations, reverse, cycle detection |
| **07 · Stacks** | ⏳ Planned | Array/Linked List implementations, infix-to-postfix, matching |
| **08 · Queues** | ⏳ Planned | Linear, Circular, Deque, Priority Queue |
| **09 · Trees** | ⏳ Planned | Binary Trees, Traversals (Pre, In, Post, Level), Height, Count |
| **10 · Binary Search Trees** | ⏳ Planned | BST Insert, Delete, Search, Predecessor, Successor |
| **11 · AVL Trees** | ⏳ Planned | Self-balancing BSTs, LL/RR/LR/RL rotations |
| **12 · Search Trees & Heaps** | ⏳ Planned | 2-3 Trees, B-Trees, Max/Min Binary Heap, Heap Sort |
| **13 · Sorting Techniques** | ⏳ Planned | Bubble, Insertion, Selection, Quick, Merge, Count, Radix, Shell |
| **14 · Hashing Techniques** | ⏳ Planned | Chaining, Linear Probing, Quadratic Probing, Double Hashing |
| **15 · Graphs** | ⏳ Planned | BFS, DFS, Prim's, Kruskal's, Dijkstra's, Floyd-Warshall |

---

## 🧰 Standard Template Library (STL)

The [`2_STL`](./2_STL/README.md) directory covers modern C++ STL containers (`vector`, `list`, `deque`, `stack`, `queue`, `priority_queue`, `set`, `map`, `unordered_map`), iterators, and algorithms, contrasting standard implementations against our custom ADTs.

👉 **Read the STL guide:** [`2_STL/README.md`](./2_STL/README.md)

---

## 📝 Notes & References

The [`notes`](./notes/README.md) directory contains supporting study notes, syntax rules, memory byte layouts, and diagrams.

```text
notes/
├── 00_intro.md                   # C++ overview & I/O comparison
├── 01_whitespaces.md             # Lexer whitespace handling
├── 02_namespaces.md              # Namespace scoping rules
├── 03_namingconvention copy.md  # Style & naming conventions
├── 04_class.md                   # Class vs struct & ADT principles
├── decimals.png                  # IEEE-754 floating point layout
├── ints.png                      # Integer sign & bit layout
└── unibyte.png                   # 8-bit byte representation
```

👉 **Read the notes index:** [`notes/README.md`](./notes/README.md)

---

## ⚙️ Compile & Run

Compile any source file using Clang or GCC:

```bash
# Clang (Recommended on macOS)
clang++ -std=c++17 <file_path>.cpp -o main
./main

# GCC / G++
g++ -std=c++17 <file_path>.cpp -o main
./main
```

---

## 🎯 Learning Philosophy

> **Build it $\to$ Understand the low-level memory & time cost $\to$ Utilize the STL abstraction.**

<div align="center">

### ⚙️ Build it · Understand it · Then use the abstraction

**C++ × Data Structures × Algorithms**

</div>
