# push_swap

## Project Overview

push_swap is a project to implement a sorting algorithm using a limited set of operations. The goal is to sort integers using as few operations as possible.

## Rules

Two stacks (a, b) are used:
- Stack a: Initially contains unsorted numbers
- Stack b: Initially empty

## Available Operations

### Swap Operations
| Operation | Description |
|-----------|-------------|
| `sa` | Swap top 2 elements of stack a |
| `sb` | Swap top 2 elements of stack b |
| `ss` | Execute sa and sb simultaneously |

### Push Operations
| Operation | Description |
|-----------|-------------|
| `pa` | Push top of stack b to stack a |
| `pb` | Push top of stack a to stack b |

### Rotate Operations
| Operation | Description |
|-----------|-------------|
| `ra` | Rotate stack a upward (first becomes last) |
| `rb` | Rotate stack b upward |
| `rr` | Execute ra and rb simultaneously |

### Reverse Rotate Operations
| Operation | Description |
|-----------|-------------|
| `rra` | Rotate stack a downward (last becomes first) |
| `rrb` | Rotate stack b downward |
| `rrr` | Execute rra and rrb simultaneously |

## Scoring Criteria

Scores are determined by the number of operations used:

### 100 Numbers
| Operations | Score |
|------------|-------|
| < 700 | 5 points |
| < 900 | 4 points |
| < 1100 | 3 points |
| < 1300 | 2 points |
| < 1500 | 1 point |

### 500 Numbers
| Operations | Score |
|------------|-------|
| < 5500 | 5 points |
| < 7000 | 4 points |
| < 8500 | 3 points |
| < 10000 | 2 points |
| < 11500 | 1 point |

## Algorithm Approaches

### Small Numbers (3-5)
- Use hardcoded optimal solutions

### Medium Numbers (~100)
- Chunk-based algorithm
- Insertion sort variant

### Large Numbers (500)
- Radix Sort
- Quick Sort variant

## Structure

```
push_swap/
├── main.c         # Main function
├── push_swap.h    # Header file
└── utils.c        # Utility functions
```

## Build

```bash
make
```

## Run

```bash
./push_swap 2 1 3 6 5 8       # Direct number input
./push_swap "2 1 3 6 5 8"     # String input

# Verify result (using checker)
ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker $ARG
```

## Debugging Tips

```bash
# Check operation count
./push_swap 3 2 1 | wc -l

# Generate random numbers
ARG=$(shuf -i 1-100 -n 100 | tr '\n' ' ')
./push_swap $ARG | wc -l
```

## Reference Algorithms

- [Radix Sort](https://en.wikipedia.org/wiki/Radix_sort)
- [Quick Sort](https://en.wikipedia.org/wiki/Quicksort)
- [Insertion Sort](https://en.wikipedia.org/wiki/Insertion_sort)
