<div align="center">

# 🔤 03 · Strings & Character Array Fundamentals

### Character Encoding · ASCII Mechanics · Memory Models · String Operations · C++

![C++](https://img.shields.io/badge/C%2B%2B-17%2F20-00599C?style=for-the-badge&logo=c%2B%2B&logoColor=white)
![Status](https://img.shields.io/badge/Status-In_Progress-orange?style=for-the-badge)
![Topics](https://img.shields.io/badge/Modules-7_Completed-brightgreen?style=for-the-badge)

*Low-level memory representation, character array initializations, ASCII mathematics, null-terminated C-strings, and fundamental string algorithms implemented from scratch in C++.*

</div>

---

## 📖 Core Concepts

In C and C++, a **String** is not a native primitive data type at the hardware level; it is represented as a contiguous **array of characters terminated by a null character (`'\0'`)**. Understanding strings from the ground up requires mastering:
1. **Character Encoding (ASCII)**: How numeric integer codes ($0 \dots 127$) map to printable symbols and non-printable control instructions.
2. **Memory Layout**: How single `char` variables (1 Byte), character arrays, and string literals reside in the Stack vs Read-Only Data (`.rodata`) segments.
3. **The Sentinel / Delimiter Pattern**: Why `'\0'` (ASCII `0`) is essential for string traversal, bound detection, and standard library I/O.
4. **String Operations**: Algorithmic implementations for length calculation, case conversion/toggling, and multi-condition token/word counting.

---

## 🗂️ Directory Structure

```text
03_string/
├── 00_introduction/              # ASCII decimal chart (0-127), control codes, and encoding notes
├── 01_charDeclaration/           # Character declaration, memory allocation (1 byte), valid vs invalid assignments
├── 02_charArrayDeclaration/      # 5 methods of character array declaration & partial zero-initialization
├── 03_strDeclaration/            # Null terminator '\0', string literal syntax, array capacity vs string length
├── 04_strlen/                    # String length calculation via sentinel loop traversal: O(n)
├── 05_changeCase/                # Uppercase, Lowercase, and Toggle case conversions using ASCII offset (32)
├── 06_countVowelandWords/        # Counting vowels, consonants, and words (handling multi-space delimiters)
└── README.md                     # Strings module documentation and progress tracker
```

---

## 📚 Module Breakdown & Key Implementations

### 1. ASCII & Character Fundamentals (`00_introduction`, `01_charDeclaration`)
- **ASCII Range Specifications**:
  - **Control Characters**: `0 – 31` and `127` (`\0` = 0, `\t` = 9, `\n` = 10, `\r` = 13, `ESC` = 27, `DEL` = 127).
  - **Digits (`'0'` – `'9'`)**: `48 – 57` (Length: 10).
  - **Uppercase (`'A'` – `'Z'`)**: `65 – 90` (Length: 26).
  - **Lowercase (`'a'` – `'z'`)**: `97 – 122` (Length: 26).
  - **Space (`' '`)**: `32`.
- **Assignment Semantics**:
  - `char temp = 'A';` $\rightarrow$ **Valid**: Stores ASCII `65` in 1 Byte.
  - `char temp = 'AB';` $\rightarrow$ **Invalid**: Multi-character constant exceeds 1 Byte.
  - `char temp = A;` $\rightarrow$ **Invalid**: Treated as an undeclared variable name.
  - `char temp = "A";` $\rightarrow$ **Invalid**: String literal decays to `const char*`, cannot assign pointer to `char`.

---

### 2. Character Arrays vs Null-Terminated Strings (`02_charArrayDeclaration`, `03_strDeclaration`)

```mermaid
graph TD
    subgraph Character Array (No Delimiter)
        A1["X[5] = {'A','B','C','D','E'}"] --> M1["[ A | B | C | D | E ]<br>sizeof = 5 bytes | Not a valid C-string"]
    end

    subgraph Explicit Null Terminator
        A2["name[10] = {'J','o','h','n','\\0'}"] --> M2["[ J | o | h | n | \\0 | 0 | 0 | 0 | 0 | 0 ]<br>sizeof = 10 bytes | strlen = 4"]
    end

    subgraph String Literal Auto-Termination
        A3["name[] = 'John'"] --> M3["[ J | o | h | n | \\0 ]<br>sizeof = 5 bytes | strlen = 4"]
    end
```

- **Partial Initialization Rule**:
  When an array is partially initialized (e.g., `char X[5] = {'A', 'B'};`), all remaining uninitialized elements are automatically set to `0` (`'\0'`). Thus, `X` naturally functions as the valid string `"AB"`.

---

### 3. Core String Algorithms

#### A. Length Calculation (`04_strlen`)
- Traverse the character array using an index until reaching the sentinel delimiter `'\0'`.
- **Time Complexity**: $O(n)$ · **Space Complexity**: $O(1)$.
```cpp
int i = 0;
for (; name[i] != '\0'; i++);
// 'i' holds the string length
```

#### B. Case Conversion & Toggling (`05_changeCase`)
- Since `'a' - 'A' = 97 - 65 = 32`:
  - **To Uppercase**: `c = c - 32` (or `c - ('a' - 'A')` or `c & ~32` / `c & '_'`).
  - **To Lowercase**: `c = c + 32` (or `c + ('a' - 'A')` or `c | 32` / `c | ' '`).
  - **Toggle Case**: Check range or bitwise toggle `c ^ 32`.

#### C. Vowels, Consonants & Word Counting (`06_countVowelandWords`)
- **Vowels & Consonants**: Classify characters by checking membership in `"aeiouAEIOU"` vs remaining alphabetic letters.
- **Word Counting with Consecutive Spaces**:
  Counts word transitions by inspecting the preceding character to robustly handle multiple consecutive whitespace delimiters:
  ```cpp
  int count = 0;
  for (int i = 1; c[i]; i++) {
      if (c[i] == ' ' && c[i - 1] != ' ') {
          count++;
      }
  }
  return count + 1;
  ```

---

## 📊 Operations Complexity Matrix

| Operation | Implementation | Time Complexity | Auxiliary Space | Key Mechanism |
| :--- | :--- | :---: | :---: | :--- |
| **Length Calculation** | `04_strlen` | $O(n)$ | $O(1)$ | Sentinel loop until `'\0'` |
| **To Uppercase** | `05_changeCase` | $O(1)$ per char | $O(1)$ | Subtract ASCII offset (`32`) |
| **To Lowercase** | `05_changeCase` | $O(1)$ per char | $O(1)$ | Add ASCII offset (`32`) |
| **Toggle Case** | `05_changeCase` | $O(1)$ per char | $O(1)$ | Range check / Bitwise XOR `^ 32` |
| **Count Vowels & Consonants** | `06_countVowelandWords` | $O(n)$ | $O(1)$ | Lookup & alphabetic validation |
| **Count Words** | `06_countVowelandWords` | $O(n)$ | $O(1)$ | Space transition check (`c[i]==' ' && c[i-1]!=' '`) |

---

## ⚙️ How to Compile & Run

Compile and execute any program using C++17:

```bash
# Character declaration & valid/invalid syntax
clang++ -std=c++17 01_charDeclaration/main.cpp -o char_decl && ./char_decl

# Character array initialization methods
clang++ -std=c++17 02_charArrayDeclaration/main.cpp -o arr_decl && ./arr_decl

# String declaration & null terminator mechanics
clang++ -std=c++17 03_strDeclaration/main.cpp -o str_decl && ./str_decl

# String length calculation
clang++ -std=c++17 04_strlen/main.cpp -o str_len && ./str_len

# Case conversion and toggling
clang++ -std=c++17 05_changeCase/main.cpp -o case_change && ./case_change

# Vowel, consonant, and word counting
clang++ -std=c++17 06_countVowelandWords/main.cpp -o count_words && ./count_words
```

---

## 🔗 Related Sections

- 🔙 [Data Structures Overview](../README.md)
- ⬅️ [01 · Array Representation](../01_arraysRepresentation/README.md)
- ⬅️ [02 · Array ADT](../02_arrayADT/README.md)
- 🧰 [Standard Template Library (STL)](../../2_STL/README.md)
