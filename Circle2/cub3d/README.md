# cub3D

## 프로젝트 개요

cub3D는 레이캐스팅(Raycasting) 기법을 사용하여 울펜슈타인 3D 스타일의 3D 그래픽 엔진을 구현하는 프로젝트입니다. MiniLibX 그래픽 라이브러리를 사용하여 1인칭 시점의 미로 게임을 만듭니다.

## 핵심 개념

### 레이캐스팅 (Raycasting)
2D 맵에서 각 화면 열(column)마다 광선을 쏘아 벽과의 교차점을 계산하여 3D 효과를 구현하는 기법입니다.

### DDA 알고리즘 (Digital Differential Analyzer)
광선이 벽에 닿을 때까지 그리드를 따라 이동하는 알고리즘입니다.

## 기능

- 1인칭 시점 3D 렌더링
- 텍스처 매핑 (북/남/서/동 벽면)
- 스프라이트 렌더링
- 플레이어 이동 및 회전
- .cub 맵 파일 파싱
- BMP 스크린샷 저장 (--save 옵션)

## 조작법

| 키 | 동작 |
|----|------|
| W | 전진 |
| S | 후진 |
| A | 좌측 이동 |
| D | 우측 이동 |
| ← | 좌회전 |
| → | 우회전 |
| ESC | 종료 |

## 맵 파일 형식 (.cub)

```
R 1920 1080                    # 해상도
NO ./textures/north.xpm        # 북쪽 벽 텍스처
SO ./textures/south.xpm        # 남쪽 벽 텍스처
WE ./textures/west.xpm         # 서쪽 벽 텍스처
EA ./textures/east.xpm         # 동쪽 벽 텍스처
S ./textures/sprite.xpm        # 스프라이트 텍스처
F 220,100,0                    # 바닥 색상 (RGB)
C 225,30,0                     # 천장 색상 (RGB)

        1111111111111111111111111
        1000000000110000000000001
        1011000001110000000000001
        1001000000000000000000001
111111111011000001110000000000001
100000000011000001110111111111111
11110111111111011100000010001
11110111111111011101010010001
11000000110101011100000010001
10000000000000001100000010001
10000000000000001101010010001
11000001110101011111011110N0111
11110111 1110101 101111010001
11111111 1111111 111111111111
```

맵 요소:
- `0`: 빈 공간
- `1`: 벽
- `2`: 스프라이트
- `N/S/E/W`: 플레이어 시작 위치 및 방향

## 구조

```
cub3d/
├── Makefile
├── inc/
│   └── cub3d.h              # 헤더 파일
├── src/
│   ├── main.c               # 메인 함수
│   ├── parsing_*.c          # 맵 파일 파싱
│   ├── map_validation.c     # 맵 유효성 검사
│   ├── wall_casting.c       # 벽 렌더링
│   ├── sprite_casting.c     # 스프라이트 렌더링
│   ├── drawing.c            # 화면 그리기
│   ├── key_handling.c       # 키 입력 처리
│   ├── player_moving.c      # 플레이어 이동
│   └── saving_bmp.c         # BMP 저장
├── libft/                   # libft 라이브러리
├── mlx/                     # MiniLibX 라이브러리
├── maps/                    # 맵 파일들
└── textures/                # 텍스처 파일들
```

## 핵심 구조체

```c
typedef struct s_player_info
{
    double  pos_x;        // 플레이어 X 좌표
    double  pos_y;        // 플레이어 Y 좌표
    double  dir_x;        // 방향 벡터 X
    double  dir_y;        // 방향 벡터 Y
    double  plane_x;      // 카메라 평면 X
    double  plane_y;      // 카메라 평면 Y
    int     **texture;    // 텍스처 데이터
    int     **world_map;  // 맵 데이터
    double  *z_buffer;    // 깊이 버퍼 (스프라이트용)
}   t_player_info;

typedef struct s_wall_casting_info
{
    double  ray_dir_x;        // 광선 방향 X
    double  ray_dir_y;        // 광선 방향 Y
    double  perp_wall_dist;   // 벽까지의 수직 거리
    int     side;             // 벽면 방향 (0: X축, 1: Y축)
    int     line_height;      // 그릴 선의 높이
    int     draw_start;       // 그리기 시작 Y좌표
    int     draw_end;         // 그리기 끝 Y좌표
}   t_wall_casting_info;
```

## 빌드

```bash
make        # cub3D 실행 파일 생성
make clean  # 오브젝트 파일 삭제
make fclean # 오브젝트 파일 및 실행 파일 삭제
make re     # 재빌드
```

## 실행

```bash
./cub3D maps/map.cub           # 일반 실행
./cub3D maps/map.cub --save    # 첫 프레임 BMP로 저장
```

## 의존성

- MiniLibX (mlx)
- libft
- math 라이브러리 (-lm)

## 참고 자료

- [Lode's Raycasting Tutorial](https://lodev.org/cgtutor/raycasting.html)
- 울펜슈타인 3D (1992)
