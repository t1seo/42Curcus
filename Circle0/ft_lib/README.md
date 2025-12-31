# ft_lib

## 프로젝트 개요

ft_lib는 libft를 확장한 개인 C 라이브러리입니다. 기존 libft의 모든 함수를 포함하면서, 추가적인 문자열 유틸리티 함수를 제공합니다.

## 구조

```
ft_lib/
├── Makefile
├── ft_lib.h         # 통합 헤더 파일
├── libft/           # 기존 libft 함수들
│   └── ft_*.c
└── ft_string/       # 추가 문자열 함수들
    └── ft_*.c
```

## 포함된 함수

### libft 함수 (기존)

메모리, 문자열, 문자 분류, 연결 리스트 관련 모든 libft 함수가 포함되어 있습니다.

### ft_string 추가 함수

- `ft_strappend` - 두 문자열을 연결하고 첫 번째 문자열 메모리 해제
- `ft_putstr` - 표준 출력으로 문자열 출력

## 빌드

```bash
make        # ft_lib.a 생성
make clean  # 오브젝트 파일 삭제
make fclean # 오브젝트 파일 및 라이브러리 삭제
make re     # 재빌드
```

## 사용법

```c
#include "ft_lib.h"

int main(void)
{
    char *s1 = ft_strdup("Hello, ");
    char *s2 = ft_strdup("World!");

    // s1의 메모리를 해제하고 연결된 새 문자열 반환
    s1 = ft_strappend(s1, s2);
    ft_putstr(s1);

    free(s1);
    free(s2);
    return (0);
}
```

## libft와의 차이점

| 항목 | libft | ft_lib |
|------|-------|--------|
| 헤더 | libft.h | ft_lib.h |
| 추가 함수 | - | ft_strappend, ft_putstr |
| 용도 | 기본 과제 제출용 | 개인 프로젝트 확장용 |

## 컴파일러 플래그

```
-Wall -Wextra -Werror
```
