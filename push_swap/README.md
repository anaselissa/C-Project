
# 🔄 Push_Swap Project — 42 Curriculum

![C](https://img.shields.io/badge/language-C-blue.svg)
![Status](https://img.shields.io/badge/status-completed-brightgreen.svg)


## Description

**push_swap** is a core algorithmic project in the 42 curriculum, written in C. The goal is to sort a list of random integers using **two stacks only** (stack **A** and stack **B**) and a **restricted set of operations**, while producing **as few moves as possible**.

### Goal

Sort integers in **ascending order** in stack **A** using stack **B**, aiming for the most efficient sequence of allowed operations (e.g., `sa`, `pb`, `ra`).

The real challenge is **optimization** (minimizing the number of operations), not just achieving a sorted result.

### Overview

The program follows three main phases:

1. **Input Handling:** parse arguments and validate them (integers only, no duplicates, within `int` range).
2. **Sorting Process:** move values between stacks using strategies optimized for different input sizes (e.g., 5, 100, 500).
3. **Efficiency Improvements:** reduce moves as much as possible through strategy selection and tuned operations.

---

## Team & Responsibilities

This project was completed collaboratively by:

### Joint Responsibilities

* Planning: defining the roadmap and milestones.
* Algorithm development: building and improving the main sorting logic.
* Performance tuning: benchmarking and reducing operation count.

### Anas (aaleassa) — Foundation & Memory Management

* Program flow (`main`): setup and orchestration.
* Data structure setup: building stack structures from inputs.
* Input protection: handling invalid inputs (duplicates, non-numeric values, `int` overflow/underflow).
* Memory management: ensuring the program is leak-free.

### [Abd Alghani (aabtah)](https://github.com/AbdAlghaniAbtah) — Operations, Analysis & Tooling

* Operations engine: implementing the 11 stack operations (`sa`, `pa`, `ra`, `rra`, etc.).
* Benchmark system: adding the `--bench` mode for performance statistics.
* Tooling functions: `set_index`, `compute_disorder`, and searching helpers.
* Small sort: designing an optimal `sort_three`.

### Detailed Role Breakdown (Anti Free-Riding)

* Parser / Input Validation: `aaleassa`
* Algorithm Logic & Selection: `aabtah` (`adaptive_sort.c`, Selection, Chunk-based, and Radix strategies)
* Operations Implementation: `aabtah`
* Memory & Leaks Auditing: `aaleassa` (freeing helpers + Valgrind checks)
* Benchmark & Tooling: `aabtah`

---

## Features

### Benchmark Mode (`--bench`)

The program includes a benchmarking option to help analyze performance:

* Total operation count
* Selected strategy (Adaptive / Simple / Medium / Complex)
* Disorder ratio before sorting

---

## Instructions

### Compilation

```bash
make
```

### Usage

Normal mode (prints operations only):

```bash
./push_swap 4 67 3 87 23
```

Benchmark mode:

```bash
./push_swap --bench 4 67 3 87 23
```

### Verification (Checker)

```bash
ARG="4 67 3 87 23"
./push_swap $ARG | ./checker_linux $ARG
```

If the result is `OK`, the sorting is valid.

---

## Algorithm Choices & Justification

To satisfy the project requirements and minimize moves, we implemented **four strategies** and select between them depending on input size and disorder.

### 1) Indexing (Normalization)

Values are converted into ranks (`0..n-1`) to:

* simplify comparisons
* enable radix/chunk logic reliably
* avoid issues with wide value ranges

### 2) Simple Strategy — Selection Sort

Used for very small input sizes (typically `< 6`).

* Why: minimal overhead and efficient in practice for tiny sets.
* Complexity: `O(n²)`.

### 3) Medium Strategy — Chunk-Based Sorting

Used for medium-sized inputs (commonly around 20–200 elements).

* Idea: split the stack into chunks and move them gradually to reduce unnecessary rotations.
* Why: often reduces total moves compared to generic approaches.
* Complexity (practical): often close to `O(n√n)` depending on chunk sizing.

### 4) Complex Strategy — Binary Radix Sort

Used for large inputs (e.g., 500 elements).

* Idea: apply bit-by-bit radix sorting on normalized indices.
* Why: highly compatible with the push_swap constraints.
* Complexity: `O(n × k)` where `k` is the number of bits.

### 5) Adaptive Strategy — Disorder-Based Selector

Before sorting, the program computes a **disorder ratio** using `compute_disorder`.

Example rule:

* disorder `< 0.2` → Simple strategy
* `0.2 ≤ disorder ≤ 0.5` → Chunk-based strategy
* disorder `> 0.5` → Radix strategy

This helps reduce operation count compared to always using the same algorithm.

#### compute_disorder

The function counts adjacent inversions:

```text
current->index > next->index
```

The result is divided by `(n - 1)` to produce a value in the range `[0,1]`, which is then used by the adaptive selector.

---

## Benchmarks (Local Results)

| Input Size | Avg Operations | Target Threshold | Status      |
| ---------- | -------------- | ---------------- | ----------- |
| 3          | 1–2            | ≤ 3              | ✅ Excellent |
| 100        | ~1200          | ≤ 1250           | ✅ Expected  |
| 500        | ~8800          | ≤ 11500          | ✅ Expected  |

---

## Data Structure

Stacks are implemented using a doubly linked list:

```c
typedef struct s_stack
{
    int             value;
    int             index;
    struct s_stack  *next;
    struct s_stack  *prev;
}   t_stack;
```

This allows efficient `rotate` and `reverse rotate` operations.

---

## Resources

* [https://push.eliotlucas.ch/](https://push.eliotlucas.ch/)
* [https://www.geeksforgeeks.org/dsa/radix-sort/](https://www.geeksforgeeks.org/dsa/radix-sort/)
* [https://youtu.be/8kpR2mUiZpk](https://youtu.be/8kpR2mUiZpk)

---

## AI Usage

AI tools were used to:

* propose edge cases and randomized testing ideas
* draft parser error-handling approaches
* help write explanatory summaries
* generate an initial README structure

All AI-generated suggestions were reviewed, tested, and adapted manually. The implementation itself was written and validated by the project team.
