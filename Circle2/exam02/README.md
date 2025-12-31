# Exam 02

## 프로젝트 개요

Exam 02는 42 Seoul의 두 번째 시험으로, 제한된 시간 내에 특정 과제들을 완성해야 합니다. 이 폴더에는 시험 대비 연습 코드들이 포함되어 있습니다.

## 시험 과제 목록

### 1. inter
두 문자열에 공통으로 존재하는 문자들을 출력합니다.

```c
// 사용법: ./inter "문자열1" "문자열2"
// 예시: ./inter "padinton" "pototan" → "padinto"
```

### 2. union
두 문자열의 합집합을 출력합니다 (중복 제거).

```c
// 사용법: ./union "문자열1" "문자열2"
// 예시: ./union "zpadinton" "pototan" → "zpadinton"
```

### 3. get_next_line
파일에서 한 줄씩 읽는 함수를 구현합니다.

### 4. ft_printf
printf 함수의 일부 기능을 구현합니다.

## 구조

```
exam02/
├── exam/            # 시험 관련 자료
├── inter/           # inter 과제 풀이
├── union/           # union 과제 풀이
├── get_next_line/   # GNL 과제 풀이
└── ft_printf/       # ft_printf 과제 풀이
```

## inter 풀이 전략

```c
#include <unistd.h>

int main(int argc, char **argv)
{
    int seen[256] = {0};  // 첫 번째 문자열의 문자 기록
    int printed[256] = {0};  // 이미 출력한 문자 기록
    int i = 0;

    if (argc == 3)
    {
        // 첫 번째 문자열의 문자들 기록
        while (argv[1][i])
            seen[(unsigned char)argv[1][i++]] = 1;

        i = 0;
        // 두 번째 문자열 순회하며 공통 문자 출력
        while (argv[2][i])
        {
            if (seen[(unsigned char)argv[2][i]] &&
                !printed[(unsigned char)argv[2][i]])
            {
                write(1, &argv[2][i], 1);
                printed[(unsigned char)argv[2][i]] = 1;
            }
            i++;
        }
    }
    write(1, "\n", 1);
    return (0);
}
```

## union 풀이 전략

```c
#include <unistd.h>

int main(int argc, char **argv)
{
    int printed[256] = {0};
    int i = 0;
    int j = 1;

    if (argc == 3)
    {
        while (j <= 2)
        {
            i = 0;
            while (argv[j][i])
            {
                if (!printed[(unsigned char)argv[j][i]])
                {
                    write(1, &argv[j][i], 1);
                    printed[(unsigned char)argv[j][i]] = 1;
                }
                i++;
            }
            j++;
        }
    }
    write(1, "\n", 1);
    return (0);
}
```

## 시험 팁

1. **시간 관리**: 각 문제에 할당된 시간을 철저히 지키기
2. **컴파일 테스트**: 제출 전 반드시 컴파일 확인
3. **엣지 케이스**: 빈 문자열, NULL, 특수 문자 처리
4. **Norminette**: 코드 스타일 규칙 준수

## 컴파일

```bash
gcc -Wall -Wextra -Werror inter.c -o inter
gcc -Wall -Wextra -Werror union.c -o union
```
