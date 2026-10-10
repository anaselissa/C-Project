*This activity has been created as part of the 42 curriculum by aaleassa.*

# get_next_line

## Description
**get_next_line** is a custom C function designed to read and return a single line from a specified file descriptor (`fd`) upon each consecutive call. It handles dynamic buffering, prevents memory manipulation overhead, and manages data persistence seamlessly across multiple file streams without reading the entire file into memory at once.

The library compiles into an efficient, lightweight utility that acts as a fundamental component for text parsing and stream manipulation in subsequent C programming projects.

---

## 🎯 Project Goals & Constraints
* **Static Persistence:** Master the use of static variables to preserve data states between sequential function executions.
* **Dynamic Buffering:** Ensure flawless behavior across extreme `BUFFER_SIZE` values (e.g., `1`, `9999`, or `10000000`) without memory corruption or segmentation faults.
* **Strict Constraints:** Developed using only three permitted external system functions (`read`, `malloc`, `free`). Built-in string manipulation wrappers or global variables are strictly forbidden.
* **Code Standard:** Complies fully with the 42 coding standard (The Norme).

---

## 🧠 Technical Implementation (Under the Hood)

### Static Stash Buffer Mechanism
Because system I/O reads data in chunks defined by `BUFFER_SIZE`, a single read operation might fetch less or more than a single line. To prevent data loss, a `static char *store` variable is implemented. This static pointer retains characters that were read from the stream but belong to the next line, keeping them safe in the heap memory across subsequent invocations of `get_next_line`.

### 📐 Visualizing the Stream & Stash Pipeline

```text
File Descriptor Stream:  [ Line 1 \n Line 2 \n Line 3 ]
                               │
                               │ read(fd, buf, BUFFER_SIZE)
                               ▼
Temporary Buffer (buf):  [ Line 1 \n Lin ]
                               │
                               │ ft_gnl_strjoin(store, buf)
                               ▼
Static Stash (store):    [ Leftover from prev. call ] + [ Line 1 \n Lin ]
                                                      │
                                     ┌────────────────┴──────────────┐
                                     ▼                               ▼
                          Extracted Line (to return)        Updated Stash (kept)
                          [ Leftover + Line 1 \n ]          [ Lin ]
````md



🛠️ Compilation & Usage

### 1. Compilation Flags

The project must compile seamlessly with and without the explicit definition of the macro `-D BUFFER_SIZE=n`.

```bash
# Compilation using an explicit buffer size of 42 as an example
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c main.c -o gnl_test
````

### 2. Integration Example

To integrate this function into your application testbed, reference the prototype in your code environment:

```c
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include "get_next_line.h"

int main(void)
{
    int   fd;
    char  *line;

    fd = open("sample.txt", O_RDONLY);
    if (fd < 0)
        return (1);
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);
        free(line);
    }
    close(fd);
    return (0);
}
```

📂 Resources

* man 2 read / Unix System I/O Documentation.
* Storage Classes in C - Lifespan and Scope of Static Heap Pointers.
* 42 Subject: Get Next Line (Version 1.3)

🤖 AI Usage & Workflow Disclosure

* Markdown Formatting: AI was utilized to convert raw function definitions into structural scannable documentation and layout patterns.
* Visual Representation: AI assisted in designing the ASCII text architecture map showcasing tracking, cropping, and stash preservation transitions.

**Note:** No functional C logic or algorithmic implementations within the project source files were auto-generated or copied from artificial intelligence outputs.
