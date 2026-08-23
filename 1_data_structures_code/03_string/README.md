<div align="center">

# 🔤 03 · Strings & Character Array Fundamentals

### Character Encoding · ASCII Mechanics · Memory Models · String Operations · C++

![C++](https://img.shields.io/badge/C%2B%2B-17%2F20-00599C?style=for-the-badge&logo=c%2B%2B&logoColor=white)
![Status](https://img.shields.io/badge/Status-In_Progress-orange?style=for-the-badge)
![Topics](https://img.shields.io/badge/Modules-10_Completed-brightgreen?style=for-the-badge)

*Low-level memory representation, character array initializations, ASCII mathematics, null-terminated C-strings, and fundamental string algorithms implemented from scratch in C++.*

</div>

---

## 📖 Core Concepts

In C and C++, a **String** is not a native primitive data type at the hardware level; it is represented as a contiguous **array of characters terminated by a null character (`'\0'`)**. Understanding strings from the ground up requires mastering:
1. **Character Encoding (ASCII)**: How numeric integer codes ($0 \dots 127$) map to printable symbols and non-printable control instructions.
2. **Memory Layout**: How single `char` variables (1 Byte), character arrays, and string literals reside in the Stack vs Read-Only Data (`.rodata`) segments.
3. **The Sentinel / Delimiter Pattern**: Why `'\0'` (ASCII `0`) is essential for string traversal, bound detection, and standard library I/O.
4. **String Operations**: Algorithmic implementations for length calculation, case conversion/toggling, validation, reversing (auxiliary vs in-place), lexicographical comparison, and palindrome checking.

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
├── 07_validation/                # String validation algorithm (alphanumeric check)
├── 08_reversing/                 # String reversal techniques
│   ├── 0_auxillary/              # Method 1: Using auxiliary character array: O(n) space
│   └── 1_inplace/                # Method 2: Two-pointer in-place swap: O(1) space
├── 09_comparing/                 # String comparison & palindrome verification
│   ├── 0_compare/                # Case-insensitive lexicographical string comparison
│   └── 1_palindrome/             # Palindrome detection via string reversal and comparison
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

#### D. String Validation (`07_validation`)
- Validates whether a string conforms to specific character set constraints (e.g., valid usernames/passwords without special characters):
  ```cpp
  bool valid(const char *name) {
      for (int i = 0; name[i]; i++) {
          if (!('a' <= name[i] && name[i] <= 'z') &&
              !('A' <= name[i] && name[i] <= 'Z') &&
              !('0' <= name[i] && name[i] <= '9')) {
              return false;
          }
      }
      return true;
  }
  ```
- **Time Complexity**: $O(n)$ · **Space Complexity**: $O(1)$.

#### E. String Reversal (`08_reversing`)
- **Method 1 · Auxiliary Array (`0_auxillary`)**:
  Calculate length $l$, allocate an auxiliary buffer $B[l+1]$, copy characters from end of $A$ to start of $B$, and terminate with $B[j] = \text{'\0'}$.
  - **Time**: $O(n)$ · **Auxiliary Space**: $O(n)$.
- **Method 2 · In-Place Two-Pointer Swap (`1_inplace`)**:
  Initialize pointers $i = 0$ and $j = \text{length} - 1$. Swap $A[i]$ with $A[j]$ and increment $i$, decrement $j$ until $i \ge j$.
  - **Time**: $O(n)$ · **Auxiliary Space**: $O(1)$.

#### F. String Comparison & Palindrome Detection (`09_comparing`)
- **Lexicographical Comparison (`0_compare`)**:
  Iterate synchronously through $A[i]$ and $B[j]$, convert to lowercase for case-insensitivity, and detect inequality:
  - If $A[i] == B[j]$ at termination: Strings are **Equal**.
  - If $A[i] < B[j]$: String $A$ is **Smaller** (appears earlier alphabetically).
  - If $A[i] > B[j]$: String $A$ is **Greater**.
- **Palindrome Verification (`1_palindrome`)**:
  Reverse string $A$ into string $B$, then perform character-by-character equality check.
  - **Time**: $O(n)$ · **Space**: $O(n)$ (or $O(1)$ if using two pointers).

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
| **String Validation** | `07_validation` | $O(n)$ | $O(1)$ | Alphanumeric range checking |
| **Reverse (Auxiliary)** | `08_reversing/0_auxillary` | $O(n)$ | $O(n)$ | End-to-start copy into second array |
| **Reverse (In-Place)** | `08_reversing/1_inplace` | $O(n)$ | $O(1)$ | Two-pointer inward swapping |
| **String Comparison** | `09_comparing/0_compare` | $O(n)$ | $O(1)$ | Lexicographical ASCII delta checking |
| **Palindrome Check** | `09_comparing/1_palindrome` | $O(n)$ | $O(n)$ | Reverse copy & synchronous comparison |

---

## ⚙️ How to Compile & Run

Compile and execute any program using C++17:

```bash
# String validation (alphanumeric check)
clang++ -std=c++17 07_validation/main.cpp -o valid && ./valid

# String reversal (auxiliary array)
clang++ -std=c++17 08_reversing/0_auxillary/main.cpp -o rev_aux && ./rev_aux

# String reversal (in-place swap)
clang++ -std=c++17 08_reversing/1_inplace/main.cpp -o rev_inplace && ./rev_inplace

# String comparison
clang++ -std=c++17 09_comparing/0_compare/main.cpp -o cmp && ./cmp

# Palindrome detection
clang++ -std=c++17 09_comparing/1_palindrome/main.cpp -o pal && ./pal
```

---

## 🔗 Related Sections

- 🔙 [Data Structures Overview](../README.md)
- ⬅️ [01 · Array Representation](../01_arraysRepresentation/README.md)
- ⬅️ [02 · Array ADT](../02_arrayADT/README.md)
- 🧰 [Standard Template Library (STL)](../../2_STL/README.md)
