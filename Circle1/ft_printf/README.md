# ft_printf

## Project Overview

ft_printf is a project to re-implement the C standard library's `printf` function. It handles variadic arguments and supports various format specifiers.

## Supported Format Specifiers

| Specifier | Description | Example |
|-----------|-------------|---------|
| `%c` | Single character | `ft_printf("%c", 'A')` → `A` |
| `%s` | String | `ft_printf("%s", "hello")` → `hello` |
| `%p` | Pointer address (hexadecimal) | `ft_printf("%p", ptr)` → `0x7fff5fbff8ac` |
| `%d` | Decimal integer (signed) | `ft_printf("%d", -42)` → `-42` |
| `%i` | Decimal integer (signed) | `ft_printf("%i", 42)` → `42` |
| `%u` | Decimal integer (unsigned) | `ft_printf("%u", 42)` → `42` |
| `%x` | Hexadecimal (lowercase) | `ft_printf("%x", 255)` → `ff` |
| `%X` | Hexadecimal (uppercase) | `ft_printf("%X", 255)` → `FF` |
| `%%` | Percent sign | `ft_printf("%%")` → `%` |

## Supported Flags

| Flag | Description |
|------|-------------|
| `-` | Left alignment |
| `0` | Zero padding |
| Number | Minimum width specification |
| `.Number` | Precision specification |
| `*` | Width/precision from argument |

## Structure

```
ft_printf/
├── Makefile
├── inc/
│   └── ft_printf.h      # Header file
├── lib/
│   └── libft functions  # Dependency library
└── src/
    ├── ft_printf.c              # Main function
    ├── parsing_format.c         # Format string parsing
    ├── allocating_chars_data.c  # Character/string handling
    ├── allocating_numbers_data.c # Number handling
    ├── allocating_pointer_data.c # Pointer handling
    ├── printing_chars_data.c    # Character output
    ├── printing_num_data.c      # Number output
    ├── printing_ptr_data.c      # Pointer output
    └── utils.c                  # Utility functions
```

## Core Structure

```c
typedef struct s_va_info
{
    char    flag;       // Flag ('-', '0')
    int     width;      // Minimum width
    int     precision;  // Precision
    char    specifier;  // Format specifier
    char    *va_data;   // Converted data
}   t_va_info;
```

## Build

```bash
make        # Generate libftprintf.a
make clean  # Remove object files
make fclean # Remove object files and library
make re     # Rebuild
```

## Usage

```c
#include "ft_printf.h"

int main(void)
{
    int count;

    count = ft_printf("Hello %s! Number: %d\n", "World", 42);
    ft_printf("Printed %d characters\n", count);

    // Flag examples
    ft_printf("[%10d]\n", 42);      // [        42]
    ft_printf("[%-10d]\n", 42);     // [42        ]
    ft_printf("[%010d]\n", 42);     // [0000000042]
    ft_printf("[%.5d]\n", 42);      // [00042]

    return (0);
}
```

## Return Value

Returns the number of characters printed. Returns -1 on error.

## Compiler Flags

```
-Wall -Wextra -Werror
```
