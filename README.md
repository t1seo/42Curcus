# 42 Cursus

42 Seoul 커리큘럼 프로젝트 모음입니다.

## 커리큘럼 구조

```
42Curcus/
├── la_piscine/          # 입학 전 부트캠프
├── Circle0/             # 첫 번째 서클
├── Circle1/             # 두 번째 서클
├── Circle2/             # 세 번째 서클
├── Circle3/             # 네 번째 서클
└── Circle4/             # 다섯 번째 서클
```

## La Piscine (입학 전)

| 프로젝트 | 설명 |
|----------|------|
| Shell00 | Shell 기초 명령어 |
| Shell01 | Shell 심화 (grep, sed, awk) |

## Circle 0

| 프로젝트 | 설명 |
|----------|------|
| [libft](Circle0/libft/) | C 표준 라이브러리 함수 직접 구현 |
| [ft_lib](Circle0/ft_lib/) | libft 확장 라이브러리 |

## Circle 1

| 프로젝트 | 설명 |
|----------|------|
| [ft_printf](Circle1/ft_printf/) | printf 함수 구현 (가변 인자 처리) |
| [get_next_line](Circle1/get_next_line/) | 파일에서 한 줄씩 읽는 함수 (정적 변수 활용) |
| [netwhat](Circle1/netwhat/) | 네트워크 기초 이론 (퀴즈) |

## Circle 2

| 프로젝트 | 설명 |
|----------|------|
| [cub3d](Circle2/cub3d/) | 레이캐스팅 3D 그래픽 엔진 (울펜슈타인 3D 스타일) |
| [push_swap](Circle2/push_swap/) | 스택 정렬 알고리즘 |
| [ft_server](Circle2/ft_server/) | Docker로 LEMP 스택 구축 |
| [exam02](Circle2/exam02/) | 시험 대비 (inter, union, GNL, printf) |
| [cub3d_tutorial](Circle2/cub3d_tutorial/) | cub3d 학습 자료 |

## Circle 3

| 프로젝트 | 설명 |
|----------|------|
| [minishell](Circle3/minishell/) | bash 스타일 간이 셸 구현 |
| [minishell_practice](Circle3/minishell_practice/) | minishell용 시스템 콜 학습 |
| [libasm](Circle3/libasm/) | x86-64 어셈블리로 libc 함수 구현 |
| [ft_services](Circle3/ft_services/) | Kubernetes 클러스터 배포 |
| [exam03](Circle3/exam03/) | 시험 대비 (mini_paint, micro_paint) |

## Circle 4

| 프로젝트 | 설명 |
|----------|------|
| [cpp_modules](Circle4/cpp_modules/) | C++ 기초부터 STL까지 (CPP00~CPP08) |
| [philosophers](Circle4/philosophers/) | 식사하는 철학자 문제 (멀티스레딩) |
| [exam04](Circle4/exam04/) | 시험 대비 (microshell) |

## 빌드 방법

대부분의 C/C++ 프로젝트는 Makefile을 사용합니다:

```bash
make        # 빌드
make clean  # 오브젝트 파일 삭제
make fclean # 전체 삭제
make re     # 재빌드
```

## 컴파일러 플래그

```bash
# C 프로젝트
gcc -Wall -Wextra -Werror

# C++ 프로젝트
c++ -Wall -Wextra -Werror -std=c++98
```

## 학습 로드맵

```
La Piscine (4주)
    │
    ▼
Circle 0: C 기초
    │
    ▼
Circle 1: 파일 I/O, 가변 인자
    │
    ▼
Circle 2: 그래픽, 알고리즘, Docker
    │
    ▼
Circle 3: 시스템 프로그래밍, 어셈블리
    │
    ▼
Circle 4: C++, 멀티스레딩
```

## 참고 자료

- [42 Docs](https://harm-smits.github.io/42docs/)
- [cppreference.com](https://en.cppreference.com/)
- [Linux man pages](https://man7.org/linux/man-pages/)
