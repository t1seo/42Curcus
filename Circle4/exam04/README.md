# Exam 04

## Project Overview

Exam 04 is the fourth exam at 42 Seoul. It primarily features the microshell task, where you implement a simple shell.

## microshell Task

### Requirements

- Implement `cd` builtin command
- Support pipes (`|`)
- Support semicolons (`;`) for sequential execution
- External command execution

### Restrictions

- No variable, wildcard, or quote handling needed
- No environment variable expansion needed
- `cd` takes exactly 2 arguments (cd + path)

### Error Messages

```c
// cd errors
"error: cd: bad arguments\n"          // Wrong argument count
"error: cd: cannot change directory to PATH\n"  // Directory change failed

// Execution error
"error: cannot execute COMMAND\n"     // execve failed

// Fatal error
"error: fatal\n"                      // fork, pipe failed
```

### Implementation Example

```c
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>

int err(char *str)
{
    while (*str)
        write(2, str++, 1);
    return 1;
}

int cd(char **argv, int i)
{
    if (i != 2)
        return err("error: cd: bad arguments\n");
    if (chdir(argv[1]) == -1)
    {
        err("error: cd: cannot change directory to ");
        err(argv[1]);
        return err("\n");
    }
    return 0;
}
```

### Pipe Handling Core Logic

```c
// When pipe exists
if (has_pipe)
{
    pipe(fd);
    pid = fork();
    if (pid == 0)
    {
        dup2(prev_fd, 0);    // Previous output as input
        dup2(fd[1], 1);      // Current output to pipe
        close(fd[0]);
        close(fd[1]);
        execve(argv[0], argv, envp);
    }
    close(fd[1]);
    if (prev_fd)
        close(prev_fd);
    prev_fd = fd[0];
}
```

## Folder Structure

```
exam04/
└── microshell/      # microshell practice
```

## Compile

```bash
gcc -Wall -Wextra -Werror microshell.c -o microshell
```

## Test

```bash
# Basic command
./microshell /bin/ls

# Pipe
./microshell /bin/ls "|" /usr/bin/wc -l

# Semicolon
./microshell /bin/ls ";" /bin/pwd

# cd
./microshell cd /tmp ";" /bin/pwd

# Combined
./microshell /bin/ls "|" /usr/bin/grep microshell ";" /bin/echo done
```

## Exam Tips

1. **Keep It Simple**: Longer code increases error probability
2. **Exact Error Messages**: Wrong output format means point deduction
3. **Use stderr**: Error messages go to fd 2
4. **Memory Leaks OK**: Functionality is more important than leaks in exams
5. **Thorough Testing**: Test pipe, semicolon, cd combinations

## Required System Calls

| Function | Purpose |
|----------|---------|
| `fork()` | Create process |
| `execve()` | Execute program |
| `waitpid()` | Wait for child process |
| `pipe()` | Create pipe |
| `dup2()` | Duplicate file descriptor |
| `chdir()` | Change directory |
| `close()` | Close file descriptor |
