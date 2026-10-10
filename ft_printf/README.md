
# ft_printf
> A custom implementation of the standard C library `printf()` function, focusing on variadic arguments and format parsing.

---

## 🎯 Project Goals & Constraints

* **Core Objective:** Write a library (`libftprintf.a`) that contains `ft_printf()`, mimicking the original `printf()` without implementing its internal buffer management.
* **Variadic Functions:** Master the use of a variable number of arguments using the `<stdarg.h>` library (`va_start`, `va_arg`, `va_end`).
* **Strict Constraints:** External functions are strictly limited to `malloc`, `free`, `write`, and the `va_*` macros. Using `libtool` is forbidden; the library must be created using the `ar` command.
* **Code Standard:** Complies fully with the 42 coding standard (The Norme).

---

## 🧠 Technical Implementation (Algorithm)

The function relies on a sequential string parsing algorithm combined with a dispatcher for variadic arguments:

1. **Variadic Initialization:** A `va_list` is initialized using `va_start` to gain access to the dynamic arguments passed after the format string.
2. **Sequential Parsing:** The main loop iterates through the format string character by character.
3. **Format Dispatcher:**
   * If a standard character is read, it is written directly to standard output (`fd = 1`).
   * If the `%` delimiter is encountered, the subsequent character is evaluated against the supported format specifiers.
4. **Delegation & Counting:** The dispatcher routes the argument to a specific helper function (e.g., `ft_puthex` for base-16 conversions). Each helper function independently tracks and returns the exact number of bytes written.
5. **Accumulation:** The main function aggregates the byte counts from all outputs and returns the total length, exactly as the original `printf()` does.

---

## 🧮 Supported Conversions

| Specifier | Description | Helper Function |
|:---------:|-------------|-----------------|
| `%c` | Prints a single character. | `ft_putchar_fd` |
| `%s` | Prints a string. | `ft_putstr_fd` |
| `%p` | Prints a `void *` pointer argument in hexadecimal format. | `ft_putptr` |
| `%d` / `%i` | Prints a decimal (base 10) number or integer. | `ft_putnbr_fd` |
| `%u` | Prints an unsigned decimal (base 10) number. | `ft_putunnum` |
| `%x` | Prints a number in hexadecimal (base 16) lowercase format. | `ft_puthex` |
| `%X` | Prints a number in hexadecimal (base 16) uppercase format. | `ft_putcaphex` |
| `%%` | Prints a literal percent sign. | *Inline write* |

---

## 🛠️ Compilation & Usage

### 1. Building the Library

The Makefile compiles the source files with `-Wall -Wextra -Werror` flags and builds the static archive `libftprintf.a` using the `ar rcs` command.

```bash
# Compile the static library
make

# Clean object files
make clean

# Clean objects and the static library
make fclean

# Re-compile from scratch
make re
```

### 2. Integration

Include the header file in your C codebase:

```c
#include "ft_printf.h"
```

Compile your project source files by linking the static library:

```bash
cc main.c libftprintf.a -o my_program
```

---

## 📂 Resources

* **System Documentation:** `man 3 printf`, `man 3 stdarg`
* **42 Subject:** *Printf (Version 1.1)*

---

## 🤖 AI Usage & Workflow Disclosure

* **Conceptual Guidance:** AI was utilized to clarify the mechanics of variadic functions and stack memory layout for dynamic arguments.
* **Testing:** AI assisted in generating edge-case testing scenarios (e.g., `INT_MIN`, `NULL` pointers).
* **Formatting:** AI was used to structure this `README.md` file into a scannable, engineering-focused format.