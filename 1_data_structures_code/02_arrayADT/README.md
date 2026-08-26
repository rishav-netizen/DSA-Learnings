<div align="center">

# 📦 02 · Array Abstract Data Type (Array ADT)

### Encapsulation · Dynamic Allocation · 17 Core Operations · 5 Algorithmic Challenges · C++ OOP Class

![C++](https://img.shields.io/badge/C%2B%2B-17%2F20-00599C?style=for-the-badge&logo=c%2B%2B&logoColor=white)
![Status](https://img.shields.io/badge/Status-Completed-success?style=for-the-badge)
![Operations](https://img.shields.io/badge/Operations-17_Implemented-brightgreen?style=for-the-badge)
![Challenges](https://img.shields.io/badge/Challenges-5_Solved-blue?style=for-the-badge)

*A comprehensive implementation of an Array Abstract Data Type in C++, covering foundational mutations, searching optimizations, set theory operations, and interview problem challenges.*

</div>

---

## 📖 What is an Array ADT?

An **Abstract Data Type (ADT)** defines a data structure solely by the data it holds and the set of operations that can be performed on it, independent of the underlying implementation.

An Array ADT manages:
1. **Data**:
   - `int *A`: Pointer to the contiguous dynamic array on the Heap.
   - `int size`: Total allocated capacity of the array.
   - `int length`: Current number of valid elements stored ($0 \le \text{length} \le \text{size}$).
2. **Operations**: Display, Append, Insert, Delete, Search, Get, Set, Max, Min, Sum, Reverse, Shift, Sorted Insert, Merge, Set Operations, and OOP Encapsulation.

---

## 🗂️ Directory Structure

```text
02_arrayADT/
├── Functions/                    # 17 Core Array ADT Operations & OOP Class
│   ├── 01_display/               # Traversing & printing all elements
│   ├── 02_append/                # Inserting at the end of the array: O(1)
│   ├── 03_insert/                # Inserting at specific index (right shift): O(n)
│   ├── 04_delete/                # Deleting at index (left shift): O(n)
│   ├── 05_search/
│   │   ├── 00_linear_search/     # Normal linear search & Improvements (Transposition, Move to Front)
│   │   └── 01_binary_search/     # Iterative & Recursive Binary Search: O(log n)
│   ├── 06_get/                   # Direct index lookup: O(1)
│   ├── 07_set/                   # Modifying element at index: O(1)
│   ├── 08_max_min/               # Finding global maximum and minimum: O(n)
│   ├── 09_sum/                   # Iterative sum, Recursive sum, and Average
│   ├── 10_reverse/               # Method 1 (auxiliary array) & Method 2 (two-pointer in-place swap)
│   ├── 11_shift/                 # Left/Right Shift and Left/Right Rotate operations
│   ├── 12_insert/                # Inserting an element into an already sorted array
│   ├── 13_is_sorted/             # Verifying sorted order
│   ├── 14_positive_negative/     # Rearranging negative elements to left, positive to right: O(n)
│   ├── 15_merge_sorted/          # Merging two sorted arrays into a third sorted array: O(m + n)
│   ├── 16_set_operations/
│   │   ├── 00_unsorted/          # Union, Intersection, Difference & Membership on unsorted arrays
│   │   └── 01_sorted/            # Merge-based Union, Intersection, Difference on sorted arrays
│   └── 17_class/                 # Full Object-Oriented C++ Array class implementation
│
├── StudentChallenge/             # 5 High-Frequency Algorithmic Challenges
│   ├── 00_findMissingElement/
│   │   ├── 00_sorted/
│   │   │   ├── 00_single/        # Single missing element (Sum formula & Index-difference method)
│   │   │   └── 01_multiple/      # Multiple missing elements using difference tracking
│   │   └── best_method_hash/     # Single-pass missing element search using Hash Table / Bitset: O(n)
│   │
│   ├── 01_duplicatesInSortedArray/
│   │   ├── 00_findingUsingLoop/  # Adjacent comparison & count counting: O(n) time, O(1) space
│   │   └── 01_findingUsingHashTable/# Frequency counting using Hash Table: O(n) time, O(M) space
│   │
│   ├── 02_duplicatesInUnSortedArray/
│   │   ├── 00_loops/             # Nested loops with in-place marking (-1): O(n^2)
│   │   └── 01_hash/              # Hash table frequency count: O(n) time
│   │
│   ├── 03_pairOfElementsWithSumK/
│   │   ├── 00_sortedArray/       # Two-pointer convergence approach (i=0, j=n-1): O(n)
│   │   └── 01_unsortedArray/
│   │       ├── 00_loops/         # Brute-force nested loops: O(n^2)
│   │       └── 01_hash/          # Hash Table complement lookup (K - A[i]): O(n)
│   │
│   └── 04_maxMinOnce/            # Finding Min & Max in single scan with minimized comparisons
│
├── Quiz/
│   └── main.cpp                  # Interactive Array ADT Quiz program
└── notes.txt                     # Summary notes on Array ADT theory
```

---

## 🛠️ Operations Breakdown (`Functions/`)

### 1. Searching & Optimization (`05_search`)
- **Linear Search Improvements**:
  - **Transposition**: When key $x$ is found at index $i$, swap $A[i]$ with $A[i-1]$. Repeated searches progressively bring frequent keys closer to index $0$.
  - **Move to Front / Head**: When key $x$ is found, swap $A[i]$ with $A[0]$. Subsequent searches for the same key take $O(1)$ time.
- **Binary Search**: Requires sorted array. Repeatedly divides the search interval in half.
  - Formula: $\text{mid} = \lfloor \frac{\text{low} + \text{high}}{2} \rfloor$
  - Time Complexity: Best $O(1)$, Worst/Average $O(\log n)$.

### 2. In-Place Array Reversal (`10_reverse`)
- **Method 1 (Auxiliary Array)**: Copy elements from $A$ to $B$ in reverse order ($B[j] = A[i]$), then copy back to $A$. Requires $O(n)$ auxiliary space.
- **Method 2 (Two Pointers Swap)**: Use pointer $i=0$ and $j = \text{length}-1$. Swap $A[i]$ and $A[j]$, increment $i$, decrement $j$ until $i \ge j$. $O(1)$ auxiliary space.

### 3. Segregating Negative & Positive Numbers (`14_positive_negative`)
- Two-pointer partition algorithm:
  - $i$ scans from the left looking for the first positive element ($A[i] \ge 0$).
  - $j$ scans from the right looking for the first negative element ($A[j] < 0$).
  - Swap $A[i]$ and $A[j]$ and repeat until $i \ge j$.
  - Executes in **$O(n)$ time** and **$O(1)$ auxiliary space**.

### 4. Merging Two Sorted Arrays (`15_merge_sorted`)
- Compares elements from array $A$ (index $i$) and array $B$ (index $j$), copying the smaller value into array $C$ (index $k$).
- Copies all remaining elements once one array is exhausted.
- **Time Complexity**: $\Theta(m + n)$ · **Space Complexity**: $\Theta(m + n)$.

### 5. Set Operations on Arrays (`16_set_operations`)

| Operation | Unsorted Approach | Sorted Approach (Merge-like) |
| :--- | :--- | :--- |
| **Union ($A \cup B$)** | Copy $A$, then append elements of $B$ not present in $A$. Time: $O(m \times n)$. | Compare $A[i]$ and $B[j]$. Copy smaller. If equal, copy once and increment both $i, j$. Time: $O(m + n)$. |
| **Intersection ($A \cap B$)** | Copy elements of $A$ that exist in $B$. Time: $O(m \times n)$. | If $A[i] == B[j]$, copy to $C$ and increment both. Else increment smaller pointer. Time: $O(m + n)$. |
| **Difference ($A - B$)** | Copy elements of $A$ that do not exist in $B$. Time: $O(m \times n)$. | If $A[i] < B[j]$, copy $A[i]$ ($A[i]$ is unique to $A$). If $A[i] == B[j]$, skip both. Time: $O(m + n)$. |
| **Set Membership** | Linear Search: $O(n)$. | Binary Search: $O(\log n)$. |

---

## 🏆 Student Challenges Breakdown (`StudentChallenge/`)

### Challenge 0 · Find Missing Elements (`00_findMissingElement`)
1. **Single Missing in First $N$ Naturals**:
   $$\text{Sum} = \frac{n(n+1)}{2} \implies \text{Missing} = \text{Sum} - \sum A[i]$$
2. **Single Missing in Arbitrary Sorted Sequence**:
   Compare $A[i] - i$ with initial difference $\text{diff} = A[0] - 0$. If $A[i] - i \ne \text{diff}$, the missing number is $i + \text{diff}$.
3. **Multiple Missing Elements in Sorted Sequence**:
   Whenever $A[i] - i > \text{diff}$, print missing elements while $\text{diff} < A[i] - i$ by printing $\text{diff} + i$ and incrementing $\text{diff}$.
4. **Hash Table / Counting Array Method**:
   Create a boolean/frequency array up to $\max(A)$. Mark occurrences in $O(n)$ time. Elements with frequency $0$ are missing. Works on both sorted and unsorted arrays in $O(n)$ time.

### Challenge 1 · Duplicates in Sorted Array (`01_duplicatesInSortedArray`)
- **Linear Scan**: Compare $A[i] == A[i+1]$. Count duplicates by advancing an inner pointer $j$ while $A[j] == A[i]$. $O(n)$ time, $O(1)$ space.
- **Hash Table**: Direct frequency lookup in $O(n)$ time.

### Challenge 2 · Duplicates in Unsorted Array (`02_duplicatesInUnSortedArray`)
- **Nested Loops**: For each $A[i]$, count occurrences in $A[i+1 \dots n-1]$. Mark counted elements with $-1$ (if positive) to avoid recounting. $O(n^2)$ time.
- **Hash Table**: Increment `hashTable[A[i]]++`. Print elements with count $> 1$. $O(n)$ time, $O(\max(A))$ space.

### Challenge 3 · Pair of Elements with Sum $K$ (`03_pairOfElementsWithSumK`)
- **Sorted Array (Two-Pointer)**:
  Initialize $i = 0, j = \text{length}-1$.
  - If $A[i] + A[j] == K$: Pair found, $i++, j--$.
  - If $A[i] + A[j] < K$: Need larger sum $\implies i++$.
  - If $A[i] + A[j] > K$: Need smaller sum $\implies j--$.
  - **Time Complexity**: **$O(n)$** · **Space Complexity**: **$O(1)$**.
- **Unsorted Array (Hash Table)**:
  For each $A[i]$, check if `hashTable[K - A[i]] > 0`. If yes, pair found. Increment `hashTable[A[i]]++`. **$O(n)$ time**.

### Challenge 4 · Min & Max in a Single Scan (`04_maxMinOnce`)
- Initialize $\text{min} = A[0], \text{max} = A[0]$.
- For each $A[i]$ ($i = 1 \dots n-1$):
  ```cpp
  if (A[i] < min)
      min = A[i];
  else if (A[i] > max)
      max = A[i];
  ```
- **Comparison Analysis**:
  - **Best Case (Decreasingly Sorted Array)**: $(n - 1)$ comparisons.
  - **Worst Case (Increasingly Sorted Array)**: $2(n - 1)$ comparisons.
  - **Average Case**: $\approx 1.5(n - 1)$ comparisons.

---

## 📊 Operations Complexity Summary Matrix

| Operation | Best Case | Average Case | Worst Case | Auxiliary Space |
| :--- | :---: | :---: | :---: | :---: |
| **Display** | $O(n)$ | $O(n)$ | $O(n)$ | $O(1)$ |
| **Append** | $O(1)$ | $O(1)$ | $O(1)$ | $O(1)$ |
| **Insert** | $O(1)$ (at end) | $O(n)$ | $O(n)$ (at index 0) | $O(1)$ |
| **Delete** | $O(1)$ (at end) | $O(n)$ | $O(n)$ (at index 0) | $O(1)$ |
| **Linear Search** | $O(1)$ | $O(n)$ | $O(n)$ | $O(1)$ |
| **Binary Search** | $O(1)$ | $O(\log n)$ | $O(\log n)$ | $O(1)$ iter / $O(\log n)$ rec |
| **Get / Set** | $O(1)$ | $O(1)$ | $O(1)$ | $O(1)$ |
| **Max / Min** | $O(n)$ | $O(n)$ | $O(n)$ | $O(1)$ |
| **Sum / Avg** | $O(n)$ | $O(n)$ | $O(n)$ | $O(1)$ |
| **Reverse (In-place)** | $O(n)$ | $O(n)$ | $O(n)$ | $O(1)$ |
| **Rearrange Pos/Neg** | $O(n)$ | $O(n)$ | $O(n)$ | $O(1)$ |
| **Merge Sorted** | $\Theta(m + n)$ | $\Theta(m + n)$ | $\Theta(m + n)$ | $\Theta(m + n)$ |
| **Sorted Set Operations** | $O(m + n)$ | $O(m + n)$ | $O(m + n)$ | $O(m + n)$ |

---

## ⚙️ Compilation & Testing

Compile and run any of the Array ADT operations or challenges:

```bash
# Run C++ Array ADT OOP Class
clang++ -std=c++17 Functions/17_class/main.cpp -o array_class
./array_class

# Run Pair of Elements with Sum K (Sorted Array)
clang++ -std=c++17 StudentChallenge/03_pairOfElementsWithSumK/00_sortedArray/main.cpp -o pair_sum
./pair_sum

# Run Min/Max Single Scan Challenge
clang++ -std=c++17 StudentChallenge/04_maxMinOnce/main.cpp -o max_min
./max_min

# Run Array ADT Quiz
clang++ -std=c++17 Quiz/main.cpp -o quiz
./quiz
```

---

## 🔗 Related Sections

- 🔙 [Data Structures Overview](../README.md)
- ⬅️ [00 · Recursion](../00_recursion/README.md)
- ⬅️ [01 · Array Representation](../01_arraysRepresentation/README.md)
- 🧰 [Standard Template Library (STL)](../../2_STL/README.md)
