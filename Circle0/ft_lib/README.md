# ft_lib

## Project Overview

ft_lib is a personal C library that extends libft. It includes all functions from the original libft while providing additional string utility functions.

## Structure

```
ft_lib/
├── Makefile
├── ft_lib.h         # Unified header file
├── libft/           # Original libft functions
│   └── ft_*.c
└── ft_string/       # Additional string functions
    └── ft_*.c
```

## Included Functions

### libft Functions (Original)

All libft functions for memory, strings, character classification, and linked lists are included.

### ft_string Additional Functions

- `ft_strappend` - Concatenate two strings and free the first string's memory
- `ft_putstr` - Output string to standard output

## Build

```bash
make        # Generate ft_lib.a
make clean  # Remove object files
make fclean # Remove object files and library
make re     # Rebuild
```

## Usage

```c
#include "ft_lib.h"

int main(void)
{
    char *s1 = ft_strdup("Hello, ");
    char *s2 = ft_strdup("World!");

    // Free s1's memory and return concatenated new string
    s1 = ft_strappend(s1, s2);
    ft_putstr(s1);

    free(s1);
    free(s2);
    return (0);
}
```

## Differences from libft

| Item | libft | ft_lib |
|------|-------|--------|
| Header | libft.h | ft_lib.h |
| Additional Functions | - | ft_strappend, ft_putstr |
| Purpose | Basic project submission | Personal project extension |

## Compiler Flags

```
-Wall -Wextra -Werror
```
