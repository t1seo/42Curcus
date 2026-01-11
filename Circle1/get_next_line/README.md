# get_next_line

## Project Overview

get_next_line (GNL) is a project to implement a function that reads one line at a time from a file descriptor. It uses static variables to maintain reading state across multiple function calls.

## Function Prototype

```c
int get_next_line(int fd, char **line);
```

### Parameters
- `fd`: File descriptor to read from
- `line`: Address of pointer to store the read line

### Return Value
| Value | Meaning |
|-------|---------|
| 1 | Line successfully read |
| 0 | End of file (EOF) reached |
| -1 | Error occurred |

## Structure

```
get_next_line/
├── get_next_line.c          # Main function
├── get_next_line.h          # Header file
├── get_next_line_utils.c    # Utility functions
├── get_next_line_bonus.c    # Bonus: Multiple fd support
├── get_next_line_bonus.h    # Bonus header
└── get_next_line_utils_bonus.c
```

## Core Concepts

### Static Variable
```c
static char *backup;  // Maintain state between function calls
```

### BUFFER_SIZE
Buffer size can be specified at compile time:
```bash
gcc -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c
```

Default value: 25

### Multiple File Descriptors (Bonus)
```c
static char *backup[MAX_FD];  // Support up to 1024 fds
```

## Usage

```c
#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int main(void)
{
    int     fd;
    char    *line;
    int     ret;

    fd = open("test.txt", O_RDONLY);
    if (fd == -1)
        return (1);

    while ((ret = get_next_line(fd, &line)) > 0)
    {
        printf("%s\n", line);
        free(line);
    }

    // Handle last line (EOF)
    if (ret == 0)
    {
        printf("%s\n", line);
        free(line);
    }

    close(fd);
    return (0);
}
```

## Utility Functions

- `ft_strlen` - Return string length
- `ft_strchr` - Search for character in string
- `ft_strdup` - Duplicate string
- `ft_strjoin` - Concatenate two strings
- `ft_strappend` - Append string (with memory free)

## How It Works

1. Read BUFFER_SIZE bytes using `read()`
2. Search for newline character (`\n`)
3. If newline found: Store content before newline in `line`, keep remainder in static variable
4. If no newline: Call `read()` again to accumulate data
5. On EOF: Store remaining data in `line` and return 0

## Notes

- Returned `line` must be `free()`d by the caller
- `\n` is not included in the returned line
- Can also be used with standard input (fd = 0)

## Compiler Flags

```
-Wall -Wextra -Werror -D BUFFER_SIZE=32
```
