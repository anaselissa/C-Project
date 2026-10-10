# 42 Core Curriculum 🚀

> Building a solid foundation in software engineering, low-level programming, and algorithmic complexity at **42 Irbid**.

## 📌 Overview
This repository serves as a centralized index for my core projects in the 42 curriculum. The focus here is on understanding computer science fundamentals "under the hood" by relying strictly on C, manual memory management, and rigorous coding standards (The Norme) without the safety nets of standard libraries.

## 🗂️ Projects Catalog

| Status | Project | Description | Key Concepts Mastered |
| :---: | :--- | :--- | :--- |
| ✅ | **[Libft](./libft)** | A custom re-implementation of the C standard library. | Memory Allocation, Pointers, Linked Lists |
| ✅ | **[get_next_line](./get_next_line)** | A function that reads and returns a single line from a file descriptor. | Static Variables, Buffer Management, File I/O |
| ✅ | **[ft_printf](./ft_printf)** | A custom implementation of the `printf()` function. | Variadic Functions, Format Parsing, Dispatchers |
| ✅ | **[push_swap](./push_swap)** | A highly optimized sorting algorithm using only two stacks. | Algorithmic Complexity ($O(n \log n)$), Data Structures |

## 🛠️ Technical Stack & Skills
* **Language:** C
* **Memory Management:** `malloc`, `free`, Valgrind (Leak prevention).
* **Build Tools:** `make`, `gcc`/`cc`, Static Archives (`.a`).
* **Version Control:** Git, GitHub.
* **OS & Environment:** Linux (Fedora/Ubuntu), Bash Scripting.

## 📏 The 42 Norm (Constraints)
All projects within this repository strictly adhere to **The Norme**, which enforces:
* Maximum 25 lines per function.
* Maximum 5 functions per file.
* No `for`, `do...while`, `switch`, or `goto` statements.
* Explicit memory management (zero memory leaks allowed).

## 🚀 How to Navigate
Each project is contained within its own directory and includes a dedicated `README.md` detailing the specific architecture, challenges, and compilation instructions. 

To explore a project, navigate to its folder and run:
```bash
make