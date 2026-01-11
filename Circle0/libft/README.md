# Libft

## Project Overview

Libft is the first project in the 42 Seoul curriculum, where you re-implement core C standard library functions. This project helps build a solid foundation in C programming and creates a personal library for use in future 42 projects.

## Implemented Functions

### Part 1 - Libc Functions

Memory manipulation functions:
- `ft_memset` - Fill memory block with a specific value
- `ft_bzero` - Initialize memory block with zeros
- `ft_memcpy` - Copy memory area
- `ft_memccpy` - Copy memory until specific character
- `ft_memmove` - Move memory area (handles overlap)
- `ft_memchr` - Search for character in memory
- `ft_memcmp` - Compare memory areas

String functions:
- `ft_strlen` - Return string length
- `ft_strlcpy` - Copy string with buffer size consideration
- `ft_strlcat` - Concatenate strings with buffer size consideration
- `ft_strchr` - Search for character in string (from beginning)
- `ft_strrchr` - Search for character in string (from end)
- `ft_strnstr` - Search for substring in string
- `ft_strncmp` - Compare strings

Character classification functions:
- `ft_isalpha` - Check if alphabetic character
- `ft_isdigit` - Check if digit character
- `ft_isalnum` - Check if alphanumeric character
- `ft_isascii` - Check if ASCII character
- `ft_isprint` - Check if printable character
- `ft_toupper` - Convert lowercase to uppercase
- `ft_tolower` - Convert uppercase to lowercase

Conversion functions:
- `ft_atoi` - Convert string to integer

Memory allocation functions:
- `ft_calloc` - Allocate zero-initialized memory
- `ft_strdup` - Duplicate string

### Part 2 - Additional Functions

- `ft_substr` - Create substring
- `ft_strjoin` - Concatenate two strings
- `ft_strtrim` - Trim specific characters from string ends
- `ft_split` - Split string by delimiter
- `ft_itoa` - Convert integer to string
- `ft_strmapi` - Apply function to each character in string
- `ft_putchar_fd` - Output character to file descriptor
- `ft_putstr_fd` - Output string to file descriptor
- `ft_putendl_fd` - Output string with newline to file descriptor
- `ft_putnbr_fd` - Output number to file descriptor

### Bonus - Linked List

```c
typedef struct s_list
{
    void            *content;
    struct s_list   *next;
}   t_list;
```

- `ft_lstnew` - Create new node
- `ft_lstadd_front` - Add node to front of list
- `ft_lstsize` - Return list size
- `ft_lstlast` - Return last node
- `ft_lstadd_back` - Add node to end of list
- `ft_lstdelone` - Delete node
- `ft_lstclear` - Delete entire list
- `ft_lstiter` - Iterate list and apply function
- `ft_lstmap` - Iterate list and create new list

## Build

```bash
make        # Generate libft.a
make bonus  # Build with bonus functions
make clean  # Remove object files
make fclean # Remove object files and library
make re     # Rebuild
```

## Usage

```c
#include "libft.h"

int main(void)
{
    char *str = ft_strdup("Hello, 42!");
    ft_putendl_fd(str, 1);
    free(str);
    return (0);
}
```

Compile:
```bash
gcc main.c -L. -lft -o program
```

## Compiler Flags

```
-Wall -Wextra -Werror
```

## File Structure

```
libft/
├── Makefile
├── libft.h          # Header file
├── ft_*.c           # Function implementation files
└── libft.a          # Built static library
```
