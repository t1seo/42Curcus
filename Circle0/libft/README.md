# Libft

## 프로젝트 개요

Libft는 42 Seoul 커리큘럼의 첫 번째 프로젝트로, C 표준 라이브러리의 핵심 함수들을 직접 구현하는 프로젝트입니다. 이 프로젝트를 통해 C 언어의 기초를 다지고, 이후 42 프로젝트에서 사용할 개인 라이브러리를 구축합니다.

## 구현된 함수 목록

### Part 1 - Libc 함수

메모리 조작 함수:
- `ft_memset` - 메모리 블록을 특정 값으로 채움
- `ft_bzero` - 메모리 블록을 0으로 초기화
- `ft_memcpy` - 메모리 영역 복사
- `ft_memccpy` - 특정 문자까지 메모리 복사
- `ft_memmove` - 메모리 영역 이동 (오버랩 처리)
- `ft_memchr` - 메모리에서 문자 검색
- `ft_memcmp` - 메모리 영역 비교

문자열 함수:
- `ft_strlen` - 문자열 길이 반환
- `ft_strlcpy` - 버퍼 크기를 고려한 문자열 복사
- `ft_strlcat` - 버퍼 크기를 고려한 문자열 연결
- `ft_strchr` - 문자열에서 문자 검색 (처음부터)
- `ft_strrchr` - 문자열에서 문자 검색 (끝에서부터)
- `ft_strnstr` - 문자열에서 부분 문자열 검색
- `ft_strncmp` - 문자열 비교

문자 분류 함수:
- `ft_isalpha` - 알파벳 문자인지 확인
- `ft_isdigit` - 숫자 문자인지 확인
- `ft_isalnum` - 알파벳 또는 숫자인지 확인
- `ft_isascii` - ASCII 문자인지 확인
- `ft_isprint` - 출력 가능한 문자인지 확인
- `ft_toupper` - 소문자를 대문자로 변환
- `ft_tolower` - 대문자를 소문자로 변환

변환 함수:
- `ft_atoi` - 문자열을 정수로 변환

메모리 할당 함수:
- `ft_calloc` - 0으로 초기화된 메모리 할당
- `ft_strdup` - 문자열 복제

### Part 2 - 추가 함수

- `ft_substr` - 부분 문자열 생성
- `ft_strjoin` - 두 문자열 연결
- `ft_strtrim` - 문자열 양끝 특정 문자 제거
- `ft_split` - 구분자로 문자열 분리
- `ft_itoa` - 정수를 문자열로 변환
- `ft_strmapi` - 문자열의 각 문자에 함수 적용
- `ft_putchar_fd` - 파일 디스크립터에 문자 출력
- `ft_putstr_fd` - 파일 디스크립터에 문자열 출력
- `ft_putendl_fd` - 파일 디스크립터에 문자열 + 개행 출력
- `ft_putnbr_fd` - 파일 디스크립터에 숫자 출력

### Bonus - 연결 리스트

```c
typedef struct s_list
{
    void            *content;
    struct s_list   *next;
}   t_list;
```

- `ft_lstnew` - 새 노드 생성
- `ft_lstadd_front` - 리스트 앞에 노드 추가
- `ft_lstsize` - 리스트 크기 반환
- `ft_lstlast` - 마지막 노드 반환
- `ft_lstadd_back` - 리스트 뒤에 노드 추가
- `ft_lstdelone` - 노드 삭제
- `ft_lstclear` - 리스트 전체 삭제
- `ft_lstiter` - 리스트 순회하며 함수 적용
- `ft_lstmap` - 리스트 순회하며 새 리스트 생성

## 빌드

```bash
make        # libft.a 생성
make bonus  # 보너스 함수 포함하여 빌드
make clean  # 오브젝트 파일 삭제
make fclean # 오브젝트 파일 및 라이브러리 삭제
make re     # 재빌드
```

## 사용법

```c
#include "libft.h"

int main(void)
{
    char *str = ft_strdup("Hello, 42!");
    ft_putendl_fd(str, 1);
    free(str);
    return (0);
}
```

컴파일:
```bash
gcc main.c -L. -lft -o program
```

## 컴파일러 플래그

```
-Wall -Wextra -Werror
```

## 파일 구조

```
libft/
├── Makefile
├── libft.h          # 헤더 파일
├── ft_*.c           # 함수 구현 파일들
└── libft.a          # 빌드된 정적 라이브러리
```
