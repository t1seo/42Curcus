# get_next_line

## 프로젝트 개요

get_next_line(GNL)은 파일 디스크립터에서 한 줄씩 읽어오는 함수를 구현하는 프로젝트입니다. 정적 변수(static variable)를 활용하여 여러 번의 함수 호출에 걸쳐 읽기 상태를 유지합니다.

## 함수 프로토타입

```c
int get_next_line(int fd, char **line);
```

### 매개변수
- `fd`: 읽을 파일 디스크립터
- `line`: 읽은 줄을 저장할 문자열 포인터의 주소

### 반환값
| 값 | 의미 |
|----|------|
| 1 | 줄을 성공적으로 읽음 |
| 0 | 파일 끝(EOF)에 도달 |
| -1 | 오류 발생 |

## 구조

```
get_next_line/
├── get_next_line.c          # 메인 함수
├── get_next_line.h          # 헤더 파일
├── get_next_line_utils.c    # 유틸리티 함수
├── get_next_line_bonus.c    # 보너스: 다중 fd 지원
├── get_next_line_bonus.h    # 보너스 헤더
└── get_next_line_utils_bonus.c
```

## 핵심 개념

### 정적 변수 (Static Variable)
```c
static char *backup;  // 함수 호출 사이에 상태 유지
```

### BUFFER_SIZE
컴파일 시 버퍼 크기를 지정할 수 있습니다:
```bash
gcc -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c
```

기본값: 25

### 다중 파일 디스크립터 (Bonus)
```c
static char *backup[MAX_FD];  // 최대 1024개 fd 지원
```

## 사용법

```c
#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int main(void)
{
    int     fd;
    char    *line;
    int     ret;

    fd = open("test.txt", O_RDONLY);
    if (fd == -1)
        return (1);

    while ((ret = get_next_line(fd, &line)) > 0)
    {
        printf("%s\n", line);
        free(line);
    }

    // 마지막 줄 처리 (EOF)
    if (ret == 0)
    {
        printf("%s\n", line);
        free(line);
    }

    close(fd);
    return (0);
}
```

## 유틸리티 함수

- `ft_strlen` - 문자열 길이 반환
- `ft_strchr` - 문자열에서 문자 검색
- `ft_strdup` - 문자열 복제
- `ft_strjoin` - 두 문자열 연결
- `ft_strappend` - 문자열 추가 (메모리 해제 포함)

## 작동 방식

1. `read()`로 BUFFER_SIZE만큼 데이터 읽기
2. 개행 문자(`\n`) 검색
3. 개행이 있으면: 개행 전까지를 `line`에 저장, 나머지는 정적 변수에 보관
4. 개행이 없으면: 다시 `read()` 호출하여 데이터 축적
5. EOF 도달 시: 남은 데이터를 `line`에 저장하고 0 반환

## 주의사항

- 반환된 `line`은 호출자가 `free()` 해야 함
- `\n`은 반환되는 줄에 포함되지 않음
- 표준 입력(fd = 0)에서도 사용 가능

## 컴파일러 플래그

```
-Wall -Wextra -Werror -D BUFFER_SIZE=32
```
