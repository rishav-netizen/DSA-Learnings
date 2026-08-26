<div align="center">

# 🔤 03 · Strings & Character Array Fundamentals

### Character Encoding · ASCII Mechanics · Memory Models · String Operations · C++

![C++](https://img.shields.io/badge/C%2B%2B-17%2F20-00599C?style=for-the-badge&logo=c%2B%2B&logoColor=white)
![Status](https://img.shields.io/badge/Status-Completed-brightgreen?style=for-the-badge)
![Topics](https://img.shields.io/badge/Modules-13_Completed-brightgreen?style=for-the-badge)

*Low-level memory representation, character array initializations, ASCII mathematics, null-terminated C-strings, and fundamental string algorithms implemented from scratch in C++.*

</div>

---

## 📖 Core Concepts

In C and C++, a **String** is not a native primitive data type at the hardware level; it is represented as a contiguous **array of characters terminated by a null character (`'\0'`)**. Understanding strings from the ground up requires mastering:
1. **Character Encoding (ASCII)**: How numeric integer codes ($0 \dots 127$) map to printable symbols and non-printable control instructions.
2. **Memory Layout**: How single `char` variables (1 Byte), character arrays, and string literals reside in the Stack vs Read-Only Data (`.rodata`) segments.
3. **The Sentinel / Delimiter Pattern**: Why `'\0'` (ASCII `0`) is essential for string traversal, bound detection, and standard library I/O.
4. **String Operations**: Algorithmic implementations for length calculation, case conversion/toggling, validation, reversing (auxiliary vs in-place), lexicographical comparison, palindrome checking, finding duplicates via bitwise operations, anagram validation, and finding permutations via recursive backtracking.

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
│   ├── 00_auxillary/             # Method 1: Using auxiliary character array: O(n) space
│   └── 01_inplace/               # Method 2: Two-pointer in-place swap: O(1) space
├── 09_comparing/                 # String comparison & palindrome verification
│   ├── 00_compare/               # Case-insensitive lexicographical string comparison
│   └── 01_palindrome/            # Palindrome detection via string reversal and comparison
├── 10_duplicates/                # Finding duplicate characters using bitwise operations (masking & merging)
├── 11_anagram/                   # Anagram checking via hash table / frequency counting
├── 12_permutations/              # Finding permutations of a string via State Space Tree & Swapping Backtracking
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
- **Method 1 · Auxiliary Array (`00_auxillary`)**:
  Calculate length $l$, allocate an auxiliary buffer $B[l+1]$, copy characters from end of $A$ to start of $B$, and terminate with $B[j] = \text{'\0'}$.
  - **Time**: $O(n)$ · **Auxiliary Space**: $O(n)$.
- **Method 2 · In-Place Two-Pointer Swap (`01_inplace`)**:
  Initialize pointers $i = 0$ and $j = \text{length} - 1$. Swap $A[i]$ with $A[j]$ and increment $i$, decrement $j$ until $i \ge j$.
  - **Time**: $O(n)$ · **Auxiliary Space**: $O(1)$.

#### F. String Comparison & Palindrome Detection (`09_comparing`)
- **Lexicographical Comparison (`00_compare`)**:
  Iterate synchronously through $A[i]$ and $B[j]$, convert to lowercase for case-insensitivity, and detect inequality:
  - If $A[i] == B[j]$ at termination: Strings are **Equal**.
  - If $A[i] < B[j]$: String $A$ is **Smaller** (appears earlier alphabetically).
  - If $A[i] > B[j]$: String $A$ is **Greater**.
- **Palindrome Verification (`01_palindrome`)**:
  Reverse string $A$ into string $B$, then perform character-by-character equality check.
  - **Time**: $O(n)$ · **Space**: $O(n)$ (or $O(1)$ if using two pointers).

#### G. Finding Duplicates via Bitwise Operations (`10_duplicates`)
- Utilizes a single 32-bit / 64-bit integer (`long int H = 0`) as a compact bitset instead of an auxiliary 26-element array (104 bytes $\rightarrow$ 4 bytes).
- **Core Bitwise Mechanics**:
  - **Left Shift (`1 << (A[i] - 97)`)**: Creates a mask with the bit at index $A[i] - 'a'$ turned ON.
  - **Masking (`x & H`)**: Tests if the bit is already ON ($> 0 \implies$ duplicate character detected).
  - **Merging (`H = x | H`)**: Sets the bit to $1$ to record the character's occurrence.
  ```cpp
  long int H = 0;
  for (int i = 0; A[i]; i++) {
      long int x = 1;
      x = x << (A[i] - 97);
      if ((x & H) > 0)
          cout << "Duplicate: " << A[i] << endl;
      else
          H = x | H;
  }
  ```
- **Time Complexity**: $O(n)$ · **Auxiliary Space**: $O(1)$ (only 4 bytes memory).

#### H. Anagram Checking (`11_anagram`)
- Validates if two strings are anagrams using a single 26-element counting hash table (`int H[26] = {0}`):
  1. Compares lengths; if $l_1 \neq l_2$, immediately returns `false`.
  2. Increments frequency counts for characters in string $A$.
  3. Decrements frequency counts for characters in string $B$; if any count drops below $0$, returns `false`.
  4. Verifies all remaining counts are $0$.
  ```cpp
  bool isAnagram(char A[], char B[]) {
      int l1 = 0, l2 = 0;
      for (; A[l1]; l1++);
      for (; B[l2]; l2++);
      if (l1 != l2) return false;

      int H[26] = {0};
      for (int i = 0; A[i]; i++) H[tolower(A[i]) - 'a']++;
      for (int i = 0; B[i]; i++) {
          H[tolower(B[i]) - 'a']--;
          if (H[tolower(B[i]) - 'a'] < 0) return false;
      }
      return true;
  }
  ```
- **Time Complexity**: $O(n)$ · **Auxiliary Space**: $O(1)$ (26 integers = 104 bytes).

#### I. Finding Permutations of a String (`12_permutations`)
- Generates all $n!$ unique permutations of a string of length $n$ using recursive backtracking and State Space Trees:
  - **Method 1 · State Space Tree (Flag Array & Auxiliary Buffer)**:
    Uses an auxiliary result array `Res[]` and a boolean/flag array `A[]` to track available characters. At recursion level $k$, an unused character is placed at `Res[k]`, marked in `A[i] = 1`, and recursed. Upon returning from the recursive call, the state is backtracked via `A[i] = 0`.
  - **Method 2 · In-Place Swapping & Backtracking**:
    Directly swaps character $s[l]$ with $s[i]$ for $l \le i \le h$, recurses for $l+1$, and restores the array by swapping back (`swap(s[l], s[i])`).
  ```cpp
  // Method 1: State Space Tree with Flag Array
  void perm(char s[], int k, char res[], int a[]) {
      if (s[k] == '\0') {
          res[k] = '\0';
          cout << res << endl;
          return;
      }
      for (int i = 0; s[i] != '\0'; i++) {
          if (a[i] == 0) {
              res[k] = s[i];
              a[i] = 1;
              perm(s, k + 1, res, a);
              a[i] = 0; // Backtracking step
          }
      }
  }
  ```
- **Time Complexity**: $O(n \times n!)$ · **Auxiliary Space**: $O(n)$ (Recursion call stack depth $n$).

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
| **Reverse (Auxiliary)** | `08_reversing/00_auxillary` | $O(n)$ | $O(n)$ | End-to-start copy into second array |
| **Reverse (In-Place)** | `08_reversing/01_inplace` | $O(n)$ | $O(1)$ | Two-pointer inward swapping |
| **String Comparison** | `09_comparing/00_compare` | $O(n)$ | $O(1)$ | Lexicographical ASCII delta checking |
| **Palindrome Check** | `09_comparing/01_palindrome` | $O(n)$ | $O(n)$ | Reverse copy & synchronous comparison |
| **Finding Duplicates** | `10_duplicates` | $O(n)$ | $O(1)$ | Bitmasking (`&`), left shifting (`<<`), & merging (`\|`) |
| **Anagram Check** | `11_anagram` | $O(n)$ | $O(1)$ | Hash table frequency increment/decrement |
| **String Permutations (Flag Array)** | `12_permutations` | $O(n \times n!)$ | $O(n)$ | State Space Tree traversal with visited array & backtracking |
| **String Permutations (Swapping)** | `12_permutations` | $O(n \times n!)$ | $O(n)$ | In-place swapping & recursive backtracking |

---

## ⚙️ How to Compile & Run

Compile and execute any program using C++17:

```bash
# String validation (alphanumeric check)
clang++ -std=c++17 07_validation/main.cpp -o valid && ./valid

# String reversal (auxiliary array)
clang++ -std=c++17 08_reversing/00_auxillary/main.cpp -o rev_aux && ./rev_aux

# String reversal (in-place swap)
clang++ -std=c++17 08_reversing/01_inplace/main.cpp -o rev_inplace && ./rev_inplace

# String comparison
clang++ -std=c++17 09_comparing/00_compare/main.cpp -o cmp && ./cmp

# Palindrome detection
clang++ -std=c++17 09_comparing/01_palindrome/main.cpp -o pal && ./pal

# Finding duplicates (bitwise operations)
clang++ -std=c++17 10_duplicates/main.cpp -o duplicates && ./duplicates

# Anagram check
clang++ -std=c++17 11_anagram/main.cpp -o anagram && ./anagram

# String permutations (State Space Tree & Swapping)
clang++ -std=c++17 12_permutations/main.cpp -o perm && ./perm
```

---

## 🔗 Related Sections

- 🔙 [Data Structures Overview](../README.md)
- ⬅️ [00 · Recursion](../00_recursion/README.md)
- ⬅️ [01 · Array Representation](../01_arraysRepresentation/README.md)
- ⬅️ [02 · Array ADT](../02_arrayADT/README.md)
- 🧰 [Standard Template Library (STL)](../../2_STL/README.md)
