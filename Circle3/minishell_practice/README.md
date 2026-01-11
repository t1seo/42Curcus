# minishell_practice

## Project Overview

This folder contains system call and function study materials for the minishell project. Each subfolder contains examples of specific system calls or functions.

## Study Topics

### 1. fork
Creates a new child process by duplicating the current process.

```c
#include <unistd.h>

pid_t pid = fork();
if (pid == 0) {
    // Child process
} else if (pid > 0) {
    // Parent process
} else {
    // Error
}
```

### 2. execve
Replaces the current process with a new program.

```c
#include <unistd.h>

char *argv[] = {"/bin/ls", "-la", NULL};
char *envp[] = {NULL};
execve("/bin/ls", argv, envp);
```

### 3. wait / waitpid
Waits for child process termination.

```c
#include <sys/wait.h>

int status;
pid_t child_pid = wait(&status);  // Wait for any child
waitpid(pid, &status, 0);          // Wait for specific child

// Check exit status
if (WIFEXITED(status))
    printf("Exit code: %d\n", WEXITSTATUS(status));
```

### 4. pipe
Creates a pipe for inter-process communication.

```c
#include <unistd.h>

int pipefd[2];
pipe(pipefd);
// pipefd[0]: Read end
// pipefd[1]: Write end
```

### 5. dup / dup2
Duplicates file descriptors.

```c
#include <unistd.h>

int newfd = dup(oldfd);           // Duplicate to new fd
dup2(oldfd, STDOUT_FILENO);       // Duplicate to specified fd
```

### 6. signal
Registers signal handlers.

```c
#include <signal.h>

void handler(int signo) {
    // Handle signal
}

signal(SIGINT, handler);   // Ctrl+C
signal(SIGQUIT, handler);  // Ctrl+\
```

### 7. getcwd / chdir
Gets or changes current directory.

```c
#include <unistd.h>

char cwd[1024];
getcwd(cwd, sizeof(cwd));  // Get current directory
chdir("/path/to/dir");     // Change directory
```

### 8. opendir / readdir / closedir
Opens and reads directory contents.

```c
#include <dirent.h>

DIR *dir = opendir(".");
struct dirent *entry;
while ((entry = readdir(dir)) != NULL) {
    printf("%s\n", entry->d_name);
}
closedir(dir);
```

### 9. stat
Gets file information.

```c
#include <sys/stat.h>

struct stat st;
stat("file.txt", &st);
printf("Size: %lld\n", st.st_size);
printf("Is directory: %d\n", S_ISDIR(st.st_mode));
```

### 10. strerror
Returns error message for error number.

```c
#include <string.h>
#include <errno.h>

if (open("nonexistent", O_RDONLY) == -1)
    printf("Error: %s\n", strerror(errno));
```

### 11. envp
Handles environment variable array.

```c
int main(int argc, char **argv, char **envp)
{
    while (*envp) {
        printf("%s\n", *envp);
        envp++;
    }
    return (0);
}
```

### 12. kill
Sends signal to a process.

```c
#include <signal.h>

kill(pid, SIGTERM);  // Request process termination
kill(pid, SIGKILL);  // Force process termination
```

## Folder Structure

```
minishell_practice/
├── fork/           # fork() examples
├── execve/         # execve() examples
├── wait/           # wait() examples
├── waitpid/        # waitpid() examples
├── pipe/           # pipe() examples
├── dup/            # dup/dup2() examples
├── signal/         # signal() examples
├── getcwd/         # getcwd() examples
├── chdir/          # chdir() examples
├── opendir,readdir,closedir/  # Directory function examples
├── stat/           # stat() examples
├── strerror/       # strerror() examples
├── envp/           # Environment variable examples
└── kill/           # kill() examples
```

## Compile

In each folder:
```bash
gcc -Wall -Wextra -Werror *.c -o test
./test
```
