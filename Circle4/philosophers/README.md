# Philosophers

## 프로젝트 개요

Philosophers(식사하는 철학자들)는 동시성 프로그래밍의 고전적인 문제를 구현하는 프로젝트입니다. 멀티스레딩, 뮤텍스, 데드락 방지 등의 개념을 학습합니다.

## 문제 설명

- N명의 철학자가 원형 테이블에 앉아 있음
- 각 철학자 사이에 포크가 하나씩 있음 (총 N개)
- 철학자는 생각하기 → 먹기 → 잠자기를 반복
- 먹기 위해서는 양쪽 포크 2개가 필요
- 일정 시간 동안 먹지 못하면 사망

## 버전

| 버전 | 동기화 방식 | 파일 위치 |
|------|-------------|-----------|
| philo_one | 뮤텍스 | `philo_one/` |
| philo_two | 세마포어 | `philo_two/` |
| philo_three | 프로세스 + 세마포어 | `philo_three/` |

## 실행 인자

```bash
./philo_one number_of_philosophers time_to_die time_to_eat time_to_sleep [must_eat]
```

| 인자 | 설명 |
|------|------|
| number_of_philosophers | 철학자 수 (= 포크 수) |
| time_to_die | 마지막 식사 후 사망까지의 시간 (ms) |
| time_to_eat | 식사에 걸리는 시간 (ms) |
| time_to_sleep | 수면 시간 (ms) |
| must_eat | (옵션) 모든 철학자가 먹어야 하는 횟수 |

### 예시

```bash
./philo_one 5 800 200 200      # 5명, 800ms마다 식사 필요
./philo_one 4 410 200 200 5    # 5번씩 먹으면 종료
```

## 출력 형식

```
timestamp_in_ms X has taken a fork
timestamp_in_ms X is eating
timestamp_in_ms X is sleeping
timestamp_in_ms X is thinking
timestamp_in_ms X died
```

예시 출력:
```
0 1 has taken a fork
0 1 has taken a fork
0 1 is eating
200 1 is sleeping
200 2 has taken a fork
200 2 has taken a fork
200 2 is eating
...
```

## 핵심 개념

### 뮤텍스 (philo_one)

```c
#include <pthread.h>

pthread_mutex_t mutex;
pthread_mutex_init(&mutex, NULL);
pthread_mutex_lock(&mutex);
// 임계 영역
pthread_mutex_unlock(&mutex);
pthread_mutex_destroy(&mutex);
```

### 세마포어 (philo_two, philo_three)

```c
#include <semaphore.h>

sem_t *sem = sem_open("/forks", O_CREAT, 0644, n);
sem_wait(sem);   // P 연산 (감소)
// 임계 영역
sem_post(sem);   // V 연산 (증가)
sem_close(sem);
sem_unlink("/forks");
```

### 스레드 생성

```c
#include <pthread.h>

pthread_t thread;
pthread_create(&thread, NULL, routine, arg);
pthread_join(thread, NULL);  // 또는 pthread_detach(thread);
```

## 구조 (philo_one)

```
philosophers/philo_one/
├── Makefile
├── philo_one.h      # 헤더 파일
├── main.c           # 메인 함수
├── parser.c         # 인자 파싱
├── setting.c        # 초기 설정
├── routine.c        # 철학자 루틴
├── checker.c        # 사망 체크
├── message.c        # 메시지 출력
└── utils.c          # 유틸리티 함수
```

## 핵심 구조체

```c
typedef struct s_info
{
    int             num_of_philos;
    unsigned long   time_to_die;
    unsigned long   time_to_eat;
    unsigned long   time_to_sleep;
    int             num_of_must_eat;
    unsigned long   start_time;
    pthread_mutex_t *forks;
    pthread_mutex_t message;
}   t_info;

typedef struct s_philo
{
    int             idx;
    int             fork_1;
    int             fork_2;
    int             num_of_eat;
    unsigned long   last_ate_time;
    pthread_t       tid;
}   t_philo;
```

## 데드락 방지 전략

1. **포크 집는 순서 고정**: 짝수 번호 철학자는 왼쪽 먼저, 홀수는 오른쪽 먼저
2. **시간차 시작**: 짝수/홀수 철학자 그룹이 번갈아 시작
3. **타임아웃**: 일정 시간 내 포크를 못 잡으면 포기

## 빌드

```bash
cd philo_one
make
./philo_one 5 800 200 200
```

## 테스트 케이스

```bash
# 철학자 1명 (죽어야 함)
./philo_one 1 800 200 200

# 아무도 죽지 않아야 함
./philo_one 5 800 200 200

# 철학자 1명이 죽어야 함
./philo_one 4 310 200 100

# 아무도 죽지 않고 각각 7번 먹고 종료
./philo_one 5 800 200 200 7
```

## 주의사항

- 두 철학자의 사망 시간이 10ms 이상 차이나면 안됨
- 메시지 출력 시 다른 메시지와 섞이면 안됨
- 데이터 레이스(data race) 방지 필수

## 참고 자료

- [Dining Philosophers Problem](https://en.wikipedia.org/wiki/Dining_philosophers_problem)
- [pthread 매뉴얼](https://man7.org/linux/man-pages/man7/pthreads.7.html)
