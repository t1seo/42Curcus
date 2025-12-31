# minishell_practice

## 프로젝트 개요

minishell 프로젝트를 위한 시스템 콜 및 함수 학습 폴더입니다. 각 폴더에는 특정 시스템 콜이나 함수의 사용 예제가 포함되어 있습니다.

## 학습 주제

### 1. fork
프로세스를 복제하여 새로운 자식 프로세스를 생성합니다.

```c
#include <unistd.h>

pid_t pid = fork();
if (pid == 0) {
    // 자식 프로세스
} else if (pid > 0) {
    // 부모 프로세스
} else {
    // 에러
}
```

### 2. execve
현재 프로세스를 새로운 프로그램으로 교체합니다.

```c
#include <unistd.h>

char *argv[] = {"/bin/ls", "-la", NULL};
char *envp[] = {NULL};
execve("/bin/ls", argv, envp);
```

### 3. wait / waitpid
자식 프로세스의 종료를 기다립니다.

```c
#include <sys/wait.h>

int status;
pid_t child_pid = wait(&status);  // 아무 자식이나 기다림
waitpid(pid, &status, 0);          // 특정 자식 기다림

// 종료 상태 확인
if (WIFEXITED(status))
    printf("Exit code: %d\n", WEXITSTATUS(status));
```

### 4. pipe
프로세스 간 통신을 위한 파이프를 생성합니다.

```c
#include <unistd.h>

int pipefd[2];
pipe(pipefd);
// pipefd[0]: 읽기 끝
// pipefd[1]: 쓰기 끝
```

### 5. dup / dup2
파일 디스크립터를 복제합니다.

```c
#include <unistd.h>

int newfd = dup(oldfd);           // 새 fd로 복제
dup2(oldfd, STDOUT_FILENO);       // 지정된 fd로 복제
```

### 6. signal
시그널 핸들러를 등록합니다.

```c
#include <signal.h>

void handler(int signo) {
    // 시그널 처리
}

signal(SIGINT, handler);   // Ctrl+C
signal(SIGQUIT, handler);  // Ctrl+\
```

### 7. getcwd / chdir
현재 디렉토리를 얻거나 변경합니다.

```c
#include <unistd.h>

char cwd[1024];
getcwd(cwd, sizeof(cwd));  // 현재 디렉토리 얻기
chdir("/path/to/dir");     // 디렉토리 변경
```

### 8. opendir / readdir / closedir
디렉토리를 열고 내용을 읽습니다.

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
파일 정보를 얻습니다.

```c
#include <sys/stat.h>

struct stat st;
stat("file.txt", &st);
printf("Size: %lld\n", st.st_size);
printf("Is directory: %d\n", S_ISDIR(st.st_mode));
```

### 10. strerror
에러 번호에 해당하는 메시지를 반환합니다.

```c
#include <string.h>
#include <errno.h>

if (open("nonexistent", O_RDONLY) == -1)
    printf("Error: %s\n", strerror(errno));
```

### 11. envp
환경 변수 배열을 다룹니다.

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
프로세스에 시그널을 보냅니다.

```c
#include <signal.h>

kill(pid, SIGTERM);  // 프로세스 종료 요청
kill(pid, SIGKILL);  // 프로세스 강제 종료
```

## 폴더 구조

```
minishell_practice/
├── fork/           # fork() 예제
├── execve/         # execve() 예제
├── wait/           # wait() 예제
├── waitpid/        # waitpid() 예제
├── pipe/           # pipe() 예제
├── dup/            # dup/dup2() 예제
├── signal/         # signal() 예제
├── getcwd/         # getcwd() 예제
├── chdir/          # chdir() 예제
├── opendir,readdir,closedir/  # 디렉토리 함수 예제
├── stat/           # stat() 예제
├── strerror/       # strerror() 예제
├── envp/           # 환경 변수 예제
└── kill/           # kill() 예제
```

## 컴파일

각 폴더에서:
```bash
gcc -Wall -Wextra -Werror *.c -o test
./test
```
