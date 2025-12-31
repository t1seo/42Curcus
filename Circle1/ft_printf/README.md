# ft_printf

## 프로젝트 개요

ft_printf는 C 표준 라이브러리의 `printf` 함수를 직접 구현하는 프로젝트입니다. 가변 인자(variadic arguments)를 처리하고, 다양한 형식 지정자를 지원하는 출력 함수를 만듭니다.

## 지원하는 형식 지정자

| 지정자 | 설명 | 예시 |
|--------|------|------|
| `%c` | 단일 문자 | `ft_printf("%c", 'A')` → `A` |
| `%s` | 문자열 | `ft_printf("%s", "hello")` → `hello` |
| `%p` | 포인터 주소 (16진수) | `ft_printf("%p", ptr)` → `0x7fff5fbff8ac` |
| `%d` | 10진수 정수 (signed) | `ft_printf("%d", -42)` → `-42` |
| `%i` | 10진수 정수 (signed) | `ft_printf("%i", 42)` → `42` |
| `%u` | 10진수 정수 (unsigned) | `ft_printf("%u", 42)` → `42` |
| `%x` | 16진수 (소문자) | `ft_printf("%x", 255)` → `ff` |
| `%X` | 16진수 (대문자) | `ft_printf("%X", 255)` → `FF` |
| `%%` | 퍼센트 기호 | `ft_printf("%%")` → `%` |

## 지원하는 플래그

| 플래그 | 설명 |
|--------|------|
| `-` | 왼쪽 정렬 |
| `0` | 0으로 패딩 |
| 숫자 | 최소 너비 지정 |
| `.숫자` | 정밀도 지정 |
| `*` | 너비/정밀도를 인자로 받음 |

## 구조

```
ft_printf/
├── Makefile
├── inc/
│   └── ft_printf.h      # 헤더 파일
├── lib/
│   └── libft 함수들     # 의존 라이브러리
└── src/
    ├── ft_printf.c              # 메인 함수
    ├── parsing_format.c         # 형식 문자열 파싱
    ├── allocating_chars_data.c  # 문자/문자열 처리
    ├── allocating_numbers_data.c # 숫자 처리
    ├── allocating_pointer_data.c # 포인터 처리
    ├── printing_chars_data.c    # 문자 출력
    ├── printing_num_data.c      # 숫자 출력
    ├── printing_ptr_data.c      # 포인터 출력
    └── utils.c                  # 유틸리티 함수
```

## 핵심 구조체

```c
typedef struct s_va_info
{
    char    flag;       // 플래그 ('-', '0')
    int     width;      // 최소 너비
    int     precision;  // 정밀도
    char    specifier;  // 형식 지정자
    char    *va_data;   // 변환된 데이터
}   t_va_info;
```

## 빌드

```bash
make        # libftprintf.a 생성
make clean  # 오브젝트 파일 삭제
make fclean # 오브젝트 파일 및 라이브러리 삭제
make re     # 재빌드
```

## 사용법

```c
#include "ft_printf.h"

int main(void)
{
    int count;

    count = ft_printf("Hello %s! Number: %d\n", "World", 42);
    ft_printf("Printed %d characters\n", count);

    // 플래그 사용 예시
    ft_printf("[%10d]\n", 42);      // [        42]
    ft_printf("[%-10d]\n", 42);     // [42        ]
    ft_printf("[%010d]\n", 42);     // [0000000042]
    ft_printf("[%.5d]\n", 42);      // [00042]

    return (0);
}
```

## 반환값

출력된 문자 수를 반환합니다. 오류 발생 시 -1을 반환합니다.

## 컴파일러 플래그

```
-Wall -Wextra -Werror
```
