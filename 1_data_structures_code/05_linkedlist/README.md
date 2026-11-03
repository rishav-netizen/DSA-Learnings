<div align="center">

# 🔗 05 · Linked Lists (Singly, Circular, Doubly & Advanced Operations)

### Dynamic Linear Data Structures · Node Pointers · Heap Memory · Abdul Bari DSA Curriculum

![C++](https://img.shields.io/badge/C%2B%2B-17%2F20-00599C?style=for-the-badge&logo=c%2B%2B&logoColor=white)
![Status](https://img.shields.io/badge/Status-In_Progress-yellow?style=for-the-badge)
![Curriculum](https://img.shields.io/badge/Abdul_Bari-Section_11-informational?style=for-the-badge)

*A comprehensive implementation of Linked List data structures and algorithms in C/C++, transitioning from foundational pointer mechanics to advanced algorithmic problems, circular/doubly variants, and OOP class abstractions.*

</div>

---

## 📖 Core Concepts & Motivation

### Why Linked Lists?
In static or dynamic contiguous arrays:
1. **Fixed Capacity & Costly Resizing**: Expanding capacity requires allocating a new memory block and copying all $n$ elements ($O(n)$ overhead).
2. **Expensive Insertions/Deletions**: Inserting or removing elements at the beginning or middle requires shifting $O(n)$ adjacent elements.
3. **Memory Fragmentation**: Requires a large contiguous block of free RAM, which can fail if memory is fragmented.

A **Linked List** overcomes these constraints:
- **Dynamic Allocation**: Nodes are allocated individually in the heap on-demand.
- **Efficient Insertions/Deletions**: Non-contiguous memory; insertion and deletion simply update neighboring pointers in $O(1)$ time (once the position is found).
- **No Wasted Memory**: Only consumes heap storage for the exact number of active elements (plus pointer overhead).

```text
Singly Linked Node Memory Model:
┌──────────────┐     ┌──────────────┐     ┌──────────────┐
│  data │ next ├────►│  data │ next ├────►│  data │ next ├──► NULL
└──────────────┘     └──────────────┘     └──────────────┘
  Heap Node 1          Heap Node 2          Heap Node 3
```

---

## 🗂️ Directory Structure

```text
05_linkedlist/
├── 01_singly_linked_list/                  # Singly Linked List Core Functions & Algorithms
│   ├── 01_display/                        # ✅ Iterative & Recursive Traversal (Forward & Reverse)
│   ├── 02_count_and_sum/                  # ✅ Node Counting & Element Summation (Iterative & Recursive)
│   ├── 03_max_min/                        # ✅ Finding Maximum & Minimum Elements
│   ├── 04_search/                         # ✅ Linear Search & Optimization (Move-to-Head / Transposition)
│   ├── 05_insert/                         # ✅ Insertion at Head, Given Index, and Tail
│   ├── 06_insert_sorted/                  # ✅ Inserting into a Sorted Linked List
│   ├── 07_delete/                         # ✅ Deleting Head, Middle, or Tail Nodes
│   ├── 08_is_sorted/                      # ✅ Validating Sorted Order
│   ├── 09_remove_duplicates/              # ✅ Removing Duplicate Elements from Sorted List
│   ├── 10_reverse/                        # ✅ Reversing: Elements vs Links (Sliding Pointers & Recursion)
│   ├── 11_concatenate_and_merge/          # ✅ Concatenation & Two-Finger Sorted Merge
│   ├── 12_check_loop/                     # ✅ Cycle Detection (Floyd's Tortoise and Hare Algorithm)
│   └── 13_cpp_class/                      # ✅ Full C++ OOP Template Class Encapsulation
├── 02_circular_linked_list/               # Circular Singly Linked List (Last node points to Head)
│   ├── 01_display/                        # do-while Iterative & Recursive Traversal
│   ├── 02_insert/                         # Insert at Head (with tail pointer update) & Given Position
│   └── 03_delete/                         # Deleting Head & Intermediate Nodes
├── 03_doubly_linked_list/                 # Bidirectional Doubly Linked List (prev & next pointers)
│   ├── 01_display/                        # Forward & Backward Bi-directional Traversal
│   ├── 02_insert/                         # Two-way Pointer Insertion
│   ├── 03_delete/                         # Two-way Pointer Deletion without tracking predecessor
│   └── 04_reverse/                        # In-place Reversal by swapping prev & next pointers
├── 04_circular_doubly_linked_list/        # Circular Doubly Linked List (head->prev = last, last->next = head)
├── StudentChallenge/                      # Interview Challenges & Classical Algorithmic Problems
│   ├── 01_middle_element/                 # Finding Middle Node in a Single Pass (Fast/Slow Pointers)
│   └── 02_intersection_point/             # Finding Intersection Node of Two Merging Linked Lists
├── notes.txt                              # Conceptual notes, formulas & whiteboard dry-runs
└── README.md                              # Module documentation & curriculum progress tracker (this file)
```

---

## 📚 Curriculum Breakdown & Algorithms

### 1. Singly Linked List (`01_singly_linked_list/`)

#### Fundamental Node Structure
```cpp
struct Node {
    int data;
    Node *next;
};
```

#### Core Operations
1. **Display & Traversals (`01_display`)**:
   - *Iterative*: Traverses via pointer `p = p->next` until `p == nullptr`.
   - *Recursive Forward*: Prints `p->data` before recursive call `display(p->next)`.
   - *Recursive Reverse*: Recursively calls `display(p->next)` first, printing `p->data` during activation record unwinding ($O(n)$ auxiliary stack space).
2. **Count & Sum (`02_count_and_sum`)**:
   - Computes total node count $n$ and element sum $\sum x$ iteratively and recursively.
3. **Maximum & Minimum (`03_max_min`)**:
   - Single-scan search tracking `INT_MIN` / `INT_MAX`.
4. **Search Optimization (`04_search`)**:
   - Standard Linear Search ($O(n)$).
   - *Move-to-Head*: Re-links the accessed node directly to the front so subsequent lookups execute in $O(1)$ time.
5. **Insertions (`05_insert`, `06_insert_sorted`)**:
   - Insert at beginning: New node points to `head`, `head` updated ($O(1)$).
   - Insert at position $k$: Traverses to $(k-1)$-th node, re-links pointers ($O(n)$).
   - Insert in sorted list: Employs two sliding pointers (`p` and `q`) to find the insertion gap ($O(n)$).
6. **Deletion (`07_delete`)**:
   - Deleting head: Updates `head = head->next`, deallocates old head memory ($O(1)$).
   - Deleting at position $k$: Predecessor pointer bridges over target node, safely invoking `delete` ($O(n)$).
7. **Validation & Deduplication (`08_is_sorted`, `09_remove_duplicates`)**:
   - `isSorted`: Compares `p->data` against `p->next->data`.
   - `removeDuplicates`: In a sorted list, deletes matching consecutive nodes in a single scan ($O(n)$ time, $O(1)$ space).
8. **Reversal Techniques (`10_reverse`)**:
   - *Elements Reversal*: Auxiliary array buffer copies data and writes backwards ($O(n)$ time, $O(n)$ space).
   - *Sliding Pointers (Recommended)*: Three trailing pointers (`p`, `q`, `r`) reverse link directions in a single pass ($O(n)$ time, $O(1)$ space).
   - *Recursive Reversal*: Re-links `p->next->next = p; p->next = nullptr;` upon stack return.
9. **Concatenation & Merging (`11_concatenate_and_merge`)**:
   - *Concatenation*: Navigates to tail of first list, links `last->next = second` ($O(m)$).
   - *Merge Sorted*: Two-finger linear merge linking existing nodes into non-decreasing sequence ($\Theta(m + n)$ time, $O(1)$ auxiliary space).
10. **Loop Detection (`12_check_loop`)**:
    - *Floyd’s Tortoise and Hare*: `slow` advances 1 node while `fast` advances 2 nodes. If `slow == fast`, a cycle exists.
11. **Object-Oriented C++ Class (`13_cpp_class`)**:
    - Encapsulates raw pointers inside a `LinkedList` class with destructor for heap deallocation and overloaded operators.

---

### 2. Circular Linked List (`02_circular_linked_list/`)
- In a Circular Linked List, the `next` pointer of the final node references the `head` instead of `nullptr`.
- **Traversal**: Uses a `do-while` loop condition (`do { ...; p = p->next; } while (p != head);`).
- **Insertion at Head**: Requires traversing to the tail node to update its `next` pointer to the new head, or inserting after head and swapping data.

---

### 3. Doubly Linked List (`03_doubly_linked_list/`)
- Each node maintains two pointers: `prev` and `next`:
```cpp
struct Node {
    Node *prev;
    int data;
    Node *next;
};
```
- **Advantages**: Bidirectional traversal; deletion of a node $p$ does not require traversing from head to find its predecessor ($O(1)$ pointer redirection).
- **In-place Reversal**: Iteratively swaps the `prev` and `next` pointers for every node in the list.

---

### 4. Circular Doubly Linked List (`04_circular_doubly_linked_list/`)
- Merges circular and doubly linked properties:
  - `head->prev` points directly to the last node.
  - `last->next` points directly to `head`.
- Enables $O(1)$ access to both head and tail nodes simultaneously.

---

### 5. Student Challenges (`StudentChallenge/`)
1. **Middle Element of a Linked List (`01_middle_element`)**:
   - Using two pointers: `fast` moves at $2\times$ speed and `slow` moves at $1\times$ speed. When `fast` reaches the end, `slow` points precisely to the middle element in a single pass.
2. **Intersection Point of Two Linked Lists (`02_intersection_point`)**:
   - Identifies the common node where two distinct linked lists merge:
     - *Approach 1*: Stack auxiliary traversal ($O(m + n)$ space).
     - *Approach 2*: Difference of node lengths $\Delta = |m - n|$; advance longer list pointer by $\Delta$, then traverse both pointers simultaneously ($O(1)$ auxiliary space).

---

## ⚡ Complexity Cheat Sheet

| Operation | Best Case | Worst / Average Case | Auxiliary Space |
| :--- | :---: | :---: | :---: |
| **Insert at Head** | $O(1)$ | $O(1)$ | $O(1)$ |
| **Insert at Index $k$** | $O(1)$ | $O(n)$ | $O(1)$ |
| **Delete Head** | $O(1)$ | $O(1)$ | $O(1)$ |
| **Delete at Index $k$** | $O(1)$ | $O(n)$ | $O(1)$ |
| **Linear Search** | $O(1)$ | $O(n)$ | $O(1)$ |
| **Reverse (Sliding Pointers)** | $O(n)$ | $O(n)$ | $O(1)$ |
| **Merge Sorted Lists** | $O(m + n)$ | $O(m + n)$ | $O(1)$ |
| **Loop Detection (Floyd's)** | $O(1)$ | $O(n)$ | $O(1)$ |
| **Find Middle Element** | $O(n)$ | $O(n)$ | $O(1)$ |
