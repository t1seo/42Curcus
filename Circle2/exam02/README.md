# Exam 02

## Project Overview

Exam 02 is the second exam at 42 Seoul, where specific tasks must be completed within a time limit. This folder contains practice code for exam preparation.

## Exam Tasks

### 1. inter
Output characters that exist in both strings.

```c
// Usage: ./inter "string1" "string2"
// Example: ./inter "padinton" "pototan" → "padinto"
```

### 2. union
Output the union of two strings (no duplicates).

```c
// Usage: ./union "string1" "string2"
// Example: ./union "zpadinton" "pototan" → "zpadinton"
```

### 3. get_next_line
Implement a function that reads a file line by line.

### 4. ft_printf
Implement partial functionality of the printf function.

## Structure

```
exam02/
├── exam/            # Exam-related materials
├── inter/           # inter solution
├── union/           # union solution
├── get_next_line/   # GNL solution
└── ft_printf/       # ft_printf solution
```

## inter Solution Strategy

```c
#include <unistd.h>

int main(int argc, char **argv)
{
    int seen[256] = {0};  // Record characters from first string
    int printed[256] = {0};  // Record already printed characters
    int i = 0;

    if (argc == 3)
    {
        // Record characters from first string
        while (argv[1][i])
            seen[(unsigned char)argv[1][i++]] = 1;

        i = 0;
        // Iterate second string and print common characters
        while (argv[2][i])
        {
            if (seen[(unsigned char)argv[2][i]] &&
                !printed[(unsigned char)argv[2][i]])
            {
                write(1, &argv[2][i], 1);
                printed[(unsigned char)argv[2][i]] = 1;
            }
            i++;
        }
    }
    write(1, "\n", 1);
    return (0);
}
```

## union Solution Strategy

```c
#include <unistd.h>

int main(int argc, char **argv)
{
    int printed[256] = {0};
    int i = 0;
    int j = 1;

    if (argc == 3)
    {
        while (j <= 2)
        {
            i = 0;
            while (argv[j][i])
            {
                if (!printed[(unsigned char)argv[j][i]])
                {
                    write(1, &argv[j][i], 1);
                    printed[(unsigned char)argv[j][i]] = 1;
                }
                i++;
            }
            j++;
        }
    }
    write(1, "\n", 1);
    return (0);
}
```

## Exam Tips

1. **Time Management**: Strictly follow time allocated for each problem
2. **Compile Test**: Always verify compilation before submission
3. **Edge Cases**: Handle empty strings, NULL, special characters
4. **Norminette**: Follow code style rules

## Compile

```bash
gcc -Wall -Wextra -Werror inter.c -o inter
gcc -Wall -Wextra -Werror union.c -o union
```
