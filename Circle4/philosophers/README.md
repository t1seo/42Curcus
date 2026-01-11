# Philosophers

## Project Overview

Philosophers (Dining Philosophers) is a project implementing the classic concurrency problem. It covers multithreading, mutexes, and deadlock prevention concepts.

## Problem Description

- N philosophers sit at a round table
- One fork between each philosopher (N forks total)
- Philosophers alternate between thinking → eating → sleeping
- Eating requires 2 forks (both adjacent forks)
- Philosopher dies if they don't eat within a time limit

## Versions

| Version | Synchronization | File Location |
|---------|-----------------|---------------|
| philo_one | Mutex | `philo_one/` |
| philo_two | Semaphore | `philo_two/` |
| philo_three | Process + Semaphore | `philo_three/` |

## Arguments

```bash
./philo_one number_of_philosophers time_to_die time_to_eat time_to_sleep [must_eat]
```

| Argument | Description |
|----------|-------------|
| number_of_philosophers | Number of philosophers (= number of forks) |
| time_to_die | Time until death after last meal (ms) |
| time_to_eat | Time to eat (ms) |
| time_to_sleep | Sleep time (ms) |
| must_eat | (Optional) Number of times each philosopher must eat |

### Examples

```bash
./philo_one 5 800 200 200      # 5 philosophers, need to eat every 800ms
./philo_one 4 410 200 200 5    # Ends after eating 5 times each
```

## Output Format

```
timestamp_in_ms X has taken a fork
timestamp_in_ms X is eating
timestamp_in_ms X is sleeping
timestamp_in_ms X is thinking
timestamp_in_ms X died
```

Example output:
```
0 1 has taken a fork
0 1 has taken a fork
0 1 is eating
200 1 is sleeping
200 2 has taken a fork
200 2 has taken a fork
200 2 is eating
...
```

## Core Concepts

### Mutex (philo_one)

```c
#include <pthread.h>

pthread_mutex_t mutex;
pthread_mutex_init(&mutex, NULL);
pthread_mutex_lock(&mutex);
// Critical section
pthread_mutex_unlock(&mutex);
pthread_mutex_destroy(&mutex);
```

### Semaphore (philo_two, philo_three)

```c
#include <semaphore.h>

sem_t *sem = sem_open("/forks", O_CREAT, 0644, n);
sem_wait(sem);   // P operation (decrement)
// Critical section
sem_post(sem);   // V operation (increment)
sem_close(sem);
sem_unlink("/forks");
```

### Thread Creation

```c
#include <pthread.h>

pthread_t thread;
pthread_create(&thread, NULL, routine, arg);
pthread_join(thread, NULL);  // or pthread_detach(thread);
```

## Structure (philo_one)

```
philosophers/philo_one/
├── Makefile
├── philo_one.h      # Header file
├── main.c           # Main function
├── parser.c         # Argument parsing
├── setting.c        # Initial setup
├── routine.c        # Philosopher routine
├── checker.c        # Death checker
├── message.c        # Message output
└── utils.c          # Utility functions
```

## Core Structures

```c
typedef struct s_info
{
    int             num_of_philos;
    unsigned long   time_to_die;
    unsigned long   time_to_eat;
    unsigned long   time_to_sleep;
    int             num_of_must_eat;
    unsigned long   start_time;
    pthread_mutex_t *forks;
    pthread_mutex_t message;
}   t_info;

typedef struct s_philo
{
    int             idx;
    int             fork_1;
    int             fork_2;
    int             num_of_eat;
    unsigned long   last_ate_time;
    pthread_t       tid;
}   t_philo;
```

## Deadlock Prevention Strategies

1. **Fixed Fork Order**: Even-numbered philosophers pick left first, odd pick right first
2. **Staggered Start**: Even/odd philosopher groups start alternately
3. **Timeout**: Give up if forks aren't acquired within time limit

## Build

```bash
cd philo_one
make
./philo_one 5 800 200 200
```

## Test Cases

```bash
# 1 philosopher (should die)
./philo_one 1 800 200 200

# No one should die
./philo_one 5 800 200 200

# One philosopher should die
./philo_one 4 310 200 100

# No one dies, each eats 7 times then exits
./philo_one 5 800 200 200 7
```

## Notes

- Death times between two philosophers should not differ by more than 10ms
- Messages should not interleave with each other
- Data race prevention is mandatory

## References

- [Dining Philosophers Problem](https://en.wikipedia.org/wiki/Dining_philosophers_problem)
- [pthread Manual](https://man7.org/linux/man-pages/man7/pthreads.7.html)
