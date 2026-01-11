# 42 Cursus

A collection of 42 Seoul curriculum projects.

## Curriculum Structure

```
42Curcus/
├── la_piscine/          # Pre-admission bootcamp
├── Circle0/             # First circle
├── Circle1/             # Second circle
├── Circle2/             # Third circle
├── Circle3/             # Fourth circle
└── Circle4/             # Fifth circle
```

## La Piscine (Pre-admission)

| Project | Description |
|---------|-------------|
| Shell00 | Basic shell commands |
| Shell01 | Advanced shell (grep, sed, awk) |

## Circle 0

| Project | Description |
|---------|-------------|
| [libft](Circle0/libft/) | Re-implementation of C standard library functions |
| [ft_lib](Circle0/ft_lib/) | Extended libft library |

## Circle 1

| Project | Description |
|---------|-------------|
| [ft_printf](Circle1/ft_printf/) | printf function implementation (variadic arguments) |
| [get_next_line](Circle1/get_next_line/) | Read a line from file descriptor (static variable) |
| [netwhat](Circle1/netwhat/) | Network fundamentals (quiz) |

## Circle 2

| Project | Description |
|---------|-------------|
| [cub3d](Circle2/cub3d/) | Raycasting 3D graphics engine (Wolfenstein 3D style) |
| [push_swap](Circle2/push_swap/) | Stack sorting algorithm |
| [ft_server](Circle2/ft_server/) | Build LEMP stack with Docker |
| [exam02](Circle2/exam02/) | Exam preparation (inter, union, GNL, printf) |
| [cub3d_tutorial](Circle2/cub3d_tutorial/) | cub3d learning materials |

## Circle 3

| Project | Description |
|---------|-------------|
| [minishell](Circle3/minishell/) | Bash-style simple shell implementation |
| [minishell_practice](Circle3/minishell_practice/) | System call practice for minishell |
| [libasm](Circle3/libasm/) | x86-64 assembly libc functions |
| [ft_services](Circle3/ft_services/) | Kubernetes cluster deployment |
| [exam03](Circle3/exam03/) | Exam preparation (mini_paint, micro_paint) |

## Circle 4

| Project | Description |
|---------|-------------|
| [cpp_modules](Circle4/cpp_modules/) | C++ fundamentals to STL (CPP00~CPP08) |
| [philosophers](Circle4/philosophers/) | Dining philosophers problem (multithreading) |
| [exam04](Circle4/exam04/) | Exam preparation (microshell) |

## Build Instructions

Most C/C++ projects use Makefile:

```bash
make        # Build
make clean  # Remove object files
make fclean # Remove all generated files
make re     # Rebuild
```

## Compiler Flags

```bash
# C projects
gcc -Wall -Wextra -Werror

# C++ projects
c++ -Wall -Wextra -Werror -std=c++98
```

## Learning Roadmap

```
La Piscine (4 weeks)
    │
    ▼
Circle 0: C Fundamentals
    │
    ▼
Circle 1: File I/O, Variadic Arguments
    │
    ▼
Circle 2: Graphics, Algorithms, Docker
    │
    ▼
Circle 3: System Programming, Assembly
    │
    ▼
Circle 4: C++, Multithreading
```

## References

- [42 Docs](https://harm-smits.github.io/42docs/)
- [cppreference.com](https://en.cppreference.com/)
- [Linux man pages](https://man7.org/linux/man-pages/)
