
# Libft

> Re-implementing core standard C library functions and data structures from scratch to master memory allocation, pointers, and low-level optimization.

---

## 🎯 Project Goals & Constraints
* **Zero Dependencies:** Developed strictly in C without using any built-in functions from standard headers (except `unistd.h` and `stdlib.h` for system-level memory allocation).
* **Code Quality:** Adheres strictly to the 42 coding standard (The Norme).
* **Deliverable:** Compiles into a static library (`libft.a`) that acts as the core dependency for all subsequent C system projects in the curriculum.

---

## 🧠 Technical Implementation (Under the Hood)

The library is engineered with strict adherence to memory safety and defensive programming:

* **Byte-Level Memory Operations:** Functions like `ft_memcpy` and `ft_memset` utilize `unsigned char *` typecasting to ensure precise, byte-by-byte memory manipulation regardless of the underlying data type.
* **Overlap Handling (`ft_memmove`):** Implements conditional directional copying (forward vs. backward) to safely transfer data between overlapping memory blocks without corruption.
* **Leak Prevention (Rollback Mechanisms):** Dynamic allocation functions (e.g., `ft_split`, `ft_lstmap`) include built-in fallback loops. If a `malloc` fails during a multi-allocation process, all previously allocated nodes/strings are explicitly freed to prevent memory leaks.

### 📐 Visualizing Memory Overlap Handling (`ft_memmove`)

When source (`src`) and destination (`dst`) overlap, simple forward copying corrupts data. This implementation dynamically switches copy directions:

```text
Case 1: src < dst (Copy Backwards)
[  s  r  c  ]
      [  d  s  t  ]
      ◄─────────── (Copy from end to start to protect source bytes)

Case 2: src > dst (Copy Forwards)
      [  s  r  c  ]
[  d  s  t  ]
───────────►      (Copy from start to end)

```

---

## 📂 Function Catalog

| Category | Re-implemented Functions |
| --- | --- |
| **Memory Manipulation** | `ft_memset` • `ft_bzero` • `ft_memcpy` • `ft_memmove` • `ft_memchr` • `ft_memcmp` • `ft_calloc` |
| **String Operations** | `ft_strlen` • `ft_strlcpy` • `ft_strlcat` • `ft_strchr` • `ft_strrchr` • `ft_strncmp` • `ft_strnstr` • `ft_strdup` |
| **Advanced Utilities** | `ft_substr` • `ft_strjoin` • `ft_strtrim` • `ft_split` • `ft_itoa` • `ft_strmapi` • `ft_striteri` |
| **Character Checks & I/O** | `ft_isalpha` • `ft_isdigit` • `ft_isalnum` • `ft_isascii` • `ft_isprint` • `ft_toupper` • `ft_tolower` • `ft_atoi` • `ft_putchar_fd` • `ft_putstr_fd` • `ft_putendl_fd` • `ft_putnbr_fd` |

---

## ⛓️ Linked List Implementation

A custom implementation of a singly linked list structure to handle dynamic memory allocation, iterative tracking, and safe multi-node deletion.

### Structure

```c
typedef struct s_list
{
    void            *content;
    struct s_list   *next;
} t_list;

```

### Operations

* **Creation & Insertion:** `ft_lstnew` • `ft_lstadd_front` • `ft_lstadd_back`
* **Traversal & Metrics:** `ft_lstsize` • `ft_lstlast`
* **Destruction (Safe Memory Freeing):** `ft_lstdelone` • `ft_lstclear`
* **Functional Mapping:** `ft_lstiter` • `ft_lstmap`

---

## 🛠️ Compilation & Usage

### 1. Building the Library

The included `Makefile` compiles the source files with `-Wall -Wextra -Werror` flags and generates the static archive file without causing relinks.

```bash
# Compile the static library (libft.a)
make

# Clean object files
make clean

# Clean object files and the static library
make fclean

# Re-compile everything from scratch
make re

```

### 2. Integration

Include the header file in your C codebase:

```c
#include "libft.h"

```

Compile your project source files alongside the static library:

```bash
cc main.c -L. -lft -o my_program

```