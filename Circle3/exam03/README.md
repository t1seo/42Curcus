# Exam 03

## 프로젝트 개요

Exam 03은 42 Seoul의 세 번째 시험입니다. 그래픽 관련 과제가 출제되며, MiniLibX를 사용하여 도형을 그리는 프로그램을 구현해야 합니다.

## 시험 과제 목록

### 1. micro_paint (rectangle)
파일에서 직사각형 정보를 읽어 그립니다.

### 2. mini_paint (circle)
파일에서 원 정보를 읽어 그립니다.

## micro_paint 과제

### 입력 형식

```
WIDTH HEIGHT BACKGROUND_CHAR
TYPE X Y WIDTH HEIGHT CHAR
TYPE X Y WIDTH HEIGHT CHAR
...
```

- **TYPE**: `r` (직사각형) 또는 `R` (채워진 직사각형)
- **X, Y**: 좌상단 좌표
- **WIDTH, HEIGHT**: 크기
- **CHAR**: 그릴 문자

### 예시 입력 (example.txt)

```
20 10 .
r 1 1 10 5 *
R 15 3 4 4 #
```

### 출력

```
....................
.*********..........
.*       *...###....
.*       *...###....
.*       *...###....
.*********...###....
....................
....................
....................
....................
```

### 구현 로직

```c
// 직사각형인지 확인
int is_rectangle_border(float x, float y, float rect_x, float rect_y,
                         float width, float height)
{
    if ((x >= rect_x && x <= rect_x + width) &&
        (y >= rect_y && y <= rect_y + height))
    {
        if (x == rect_x || x == rect_x + width ||
            y == rect_y || y == rect_y + height)
            return (1);  // 테두리
    }
    return (0);
}
```

## mini_paint 과제

### 입력 형식

```
WIDTH HEIGHT BACKGROUND_CHAR
TYPE X Y RADIUS CHAR
TYPE X Y RADIUS CHAR
...
```

- **TYPE**: `c` (원) 또는 `C` (채워진 원)
- **X, Y**: 중심 좌표
- **RADIUS**: 반지름
- **CHAR**: 그릴 문자

### 예시 입력 (circle.txt)

```
40 20 .
C 20 10 8 *
c 20 10 5 #
```

### 구현 로직

```c
// 점이 원 안에 있는지 확인
int is_in_circle(float x, float y, float center_x, float center_y, float radius)
{
    float distance = sqrtf((x - center_x) * (x - center_x) +
                           (y - center_y) * (y - center_y));
    if (distance <= radius)
        return (1);
    return (0);
}

// 점이 원 테두리인지 확인
int is_circle_border(float x, float y, float center_x, float center_y, float radius)
{
    float distance = sqrtf((x - center_x) * (x - center_x) +
                           (y - center_y) * (y - center_y));
    if (distance <= radius && distance >= radius - 1.0)
        return (1);
    return (0);
}
```

## 폴더 구조

```
exam03/
├── micro_paint(rectangle)/  # 직사각형 과제 연습
└── mini_paint(circle)/      # 원 과제 연습
```

## 컴파일

```bash
gcc -Wall -Wextra -Werror mini_paint.c -lm -o mini_paint
gcc -Wall -Wextra -Werror micro_paint.c -o micro_paint
```

## 실행

```bash
./mini_paint circle.txt
./micro_paint rectangle.txt
```

## 시험 팁

1. **파싱 주의**: 입력 형식을 정확히 파싱하기
2. **좌표 계산**: 부동소수점 연산 정확도 주의
3. **그리기 순서**: 나중에 그린 도형이 위에 표시됨
4. **에러 처리**: 잘못된 입력에 대해 "Error: Operation file corrupted\n" 출력

## 에러 케이스

- 인자가 1개가 아닌 경우
- 파일을 열 수 없는 경우
- 첫 줄 형식이 잘못된 경우
- 도형 정보 형식이 잘못된 경우
