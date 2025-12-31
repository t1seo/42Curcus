# cub3D Tutorial

## 프로젝트 개요

cub3D 프로젝트를 완성하기 위해 학습한 튜토리얼과 연습 코드들을 모아놓은 폴더입니다.

## 구조

```
cub3d_tutorial/
├── 01_math_library_tutorial/   # 수학 라이브러리 학습
├── 02_error/                   # 에러 처리 학습
├── 03_mlx_tutorial/            # MiniLibX 학습
│   ├── 01_open_window/         # 윈도우 열기
│   ├── 02_key_handling/        # 키 입력 처리
│   ├── 03_image_loading/       # 이미지 로딩
│   ├── 04_image_making/        # 이미지 생성
│   ├── 05_img_loading_and_modifying/  # 이미지 수정
│   └── 06_2d_map/              # 2D 맵 렌더링
└── pikuma_tutorial/            # Pikuma 강의 자료
```

## 학습 주제

### 1. MiniLibX 기초

#### 윈도우 생성
```c
void *mlx_ptr = mlx_init();
void *win_ptr = mlx_new_window(mlx_ptr, 800, 600, "Title");
mlx_loop(mlx_ptr);
```

#### 키 이벤트 처리
```c
mlx_hook(win_ptr, 2, 0, key_press_handler, &data);   // 키 누름
mlx_hook(win_ptr, 3, 0, key_release_handler, &data); // 키 뗌
mlx_hook(win_ptr, 17, 0, close_handler, &data);      // 창 닫기
```

#### 이미지 처리
```c
// 이미지 생성
void *img = mlx_new_image(mlx_ptr, width, height);
int *data = (int *)mlx_get_data_addr(img, &bpp, &size_l, &endian);

// XPM 파일 로드
void *img = mlx_xpm_file_to_image(mlx_ptr, "texture.xpm", &width, &height);
```

### 2. 레이캐스팅 수학

#### 벡터 연산
- 방향 벡터 회전
- 카메라 평면 계산
- 광선 방향 계산

#### DDA 알고리즘
- 그리드 기반 광선 추적
- 벽과의 교차점 계산

### 3. 렌더링 파이프라인

1. 각 화면 열에 대해 광선 계산
2. DDA로 벽 충돌 검출
3. 벽까지의 거리로 높이 계산
4. 텍스처 좌표 계산
5. 픽셀 그리기

## 빌드 (각 튜토리얼 폴더에서)

```bash
make
./program
```

## 참고 자료

- [MiniLibX 문서](https://harm-smits.github.io/42docs/libs/minilibx)
- [Pikuma Raycasting Course](https://pikuma.com/)
- [Lode's Computer Graphics Tutorial](https://lodev.org/cgtutor/)
