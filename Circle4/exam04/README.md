# Exam 04

## 프로젝트 개요

Exam 04는 42 Seoul의 네 번째 시험입니다. 주로 microshell 과제가 출제되며, 간단한 셸을 구현해야 합니다.

## microshell 과제

### 요구사항

- `cd` 빌트인 명령어 구현
- 파이프(`|`) 지원
- 세미콜론(`;`) 지원 (순차 실행)
- 외부 명령어 실행

### 제한사항

- 변수, 와일드카드, 따옴표 처리 불필요
- 환경 변수 확장 불필요
- `cd`는 정확히 2개의 인자만 받음 (cd + 경로)

### 에러 메시지

```c
// cd 에러
"error: cd: bad arguments\n"          // 인자 개수 오류
"error: cd: cannot change directory to PATH\n"  // 디렉토리 변경 실패

// 실행 에러
"error: cannot execute COMMAND\n"     // execve 실패

// 치명적 에러
"error: fatal\n"                      // fork, pipe 실패
```

### 구현 예시

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

int exec(char **argv, int i, char **envp)
{
    int pid;
    int status;

    if (i == 0)
        return 0;
    if (!strcmp(argv[0], "cd"))
        return cd(argv, i);

    pid = fork();
    if (pid == 0)
    {
        execve(argv[0], argv, envp);
        err("error: cannot execute ");
        err(argv[0]);
        err("\n");
        exit(1);
    }
    else if (pid < 0)
    {
        err("error: fatal\n");
        exit(1);
    }
    waitpid(pid, &status, 0);
    return WIFEXITED(status) && WEXITSTATUS(status);
}

int main(int argc, char **argv, char **envp)
{
    int i = 0;
    int status = 0;
    int fd[2];
    int prev_fd = 0;

    // 파이프와 세미콜론 처리 로직
    // ...

    return status;
}
```

### 파이프 처리 핵심 로직

```c
// 파이프가 있는 경우
if (has_pipe)
{
    pipe(fd);
    pid = fork();
    if (pid == 0)
    {
        dup2(prev_fd, 0);    // 이전 출력을 입력으로
        dup2(fd[1], 1);      // 현재 출력을 파이프로
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

## 폴더 구조

```
exam04/
└── microshell/      # microshell 과제 연습
```

## 컴파일

```bash
gcc -Wall -Wextra -Werror microshell.c -o microshell
```

## 테스트

```bash
# 기본 명령어 실행
./microshell /bin/ls

# 파이프
./microshell /bin/ls "|" /usr/bin/wc -l

# 세미콜론
./microshell /bin/ls ";" /bin/pwd

# cd
./microshell cd /tmp ";" /bin/pwd

# 복합
./microshell /bin/ls "|" /usr/bin/grep microshell ";" /bin/echo done
```

## 시험 팁

1. **간결하게 작성**: 코드가 길어지면 실수 확률 증가
2. **에러 메시지 정확히**: 출력 형식이 틀리면 감점
3. **stderr 사용**: 에러 메시지는 fd 2로 출력
4. **메모리 누수 무시 가능**: 시험에서는 누수보다 기능 구현이 중요
5. **테스트 철저히**: 파이프, 세미콜론, cd 조합 테스트

## 필수 시스템 콜

| 함수 | 용도 |
|------|------|
| `fork()` | 프로세스 생성 |
| `execve()` | 프로그램 실행 |
| `waitpid()` | 자식 프로세스 대기 |
| `pipe()` | 파이프 생성 |
| `dup2()` | 파일 디스크립터 복제 |
| `chdir()` | 디렉토리 변경 |
| `close()` | 파일 디스크립터 닫기 |
