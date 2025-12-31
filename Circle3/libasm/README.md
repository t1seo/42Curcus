# libasm

## 프로젝트 개요

libasm은 x86-64 어셈블리 언어로 기본적인 libc 함수들을 구현하는 프로젝트입니다. 어셈블리 프로그래밍의 기초와 시스템 콜 호출 방법을 학습합니다.

## 필수 구현 함수

| 함수 | 프로토타입 | 설명 |
|------|-----------|------|
| `ft_strlen` | `size_t ft_strlen(char *str)` | 문자열 길이 반환 |
| `ft_strcpy` | `char *ft_strcpy(char *dst, const char *src)` | 문자열 복사 |
| `ft_strcmp` | `int ft_strcmp(const char *s1, const char *s2)` | 문자열 비교 |
| `ft_write` | `ssize_t ft_write(int fd, const void *buf, size_t n)` | 파일에 쓰기 |
| `ft_read` | `ssize_t ft_read(int fd, void *buf, size_t n)` | 파일에서 읽기 |
| `ft_strdup` | `char *ft_strdup(const char *s)` | 문자열 복제 |

## 구조

```
libasm/
├── Makefile
├── main.c           # 테스트 코드
└── srcs/
    ├── libasm.h     # 헤더 파일
    ├── ft_strlen.s  # strlen 구현
    ├── ft_strcpy.s  # strcpy 구현
    ├── ft_strcmp.s  # strcmp 구현
    ├── ft_write.s   # write 구현
    ├── ft_read.s    # read 구현
    └── ft_strdup.s  # strdup 구현
```

## x86-64 어셈블리 기초

### 레지스터

| 레지스터 | 용도 |
|----------|------|
| `rax` | 반환값, 시스템 콜 번호 |
| `rdi` | 첫 번째 인자 |
| `rsi` | 두 번째 인자 |
| `rdx` | 세 번째 인자 |
| `rcx` | 네 번째 인자 / 루프 카운터 |
| `r8` | 다섯 번째 인자 |
| `r9` | 여섯 번째 인자 |

### 시스템 콜 (Linux)

| 시스템 콜 | 번호 (rax) |
|-----------|------------|
| read | 0 |
| write | 1 |

### 명령어 예시

```asm
section .text
    global ft_strlen

ft_strlen:
    xor rax, rax            ; rax = 0 (카운터)
.loop:
    cmp byte [rdi + rax], 0 ; 현재 문자가 null인지 확인
    je .done                ; null이면 종료
    inc rax                 ; 카운터 증가
    jmp .loop               ; 루프 계속
.done:
    ret                     ; rax에 길이 반환
```

### ft_write 구현 예시

```asm
section .text
    global ft_write
    extern __errno_location

ft_write:
    mov rax, 1              ; syscall 번호 (write)
    syscall                 ; 시스템 콜 실행
    cmp rax, 0              ; 에러 체크
    jl .error               ; 음수면 에러
    ret

.error:
    neg rax                 ; 에러 코드를 양수로 변환
    push rax                ; 에러 코드 저장
    call __errno_location wrt ..plt  ; errno 주소 얻기
    pop qword [rax]         ; errno에 에러 코드 저장
    mov rax, -1             ; -1 반환
    ret
```

## 빌드

```bash
make        # libasm.a 생성
make clean  # 오브젝트 파일 삭제
make fclean # 오브젝트 파일 및 라이브러리 삭제
make re     # 재빌드
```

## 테스트

```bash
# 컴파일
make
gcc main.c -L. -lasm -o test

# 실행
./test
```

## 주의사항

### errno 처리
`ft_read`와 `ft_write`는 에러 발생 시 errno를 설정해야 합니다.

### 호출 규약 (Calling Convention)
- x86-64 System V ABI 준수
- 인자: rdi, rsi, rdx, rcx, r8, r9 순서
- 반환값: rax
- 호출자 저장 레지스터: rax, rcx, rdx, rsi, rdi, r8-r11
- 피호출자 저장 레지스터: rbx, rbp, r12-r15

### NASM 문법
```asm
section .data    ; 초기화된 데이터
section .bss     ; 초기화되지 않은 데이터
section .text    ; 코드

global func_name ; 외부에서 접근 가능
extern other_func ; 외부 함수 사용
```

## 참고 자료

- [x86-64 시스템 콜 테이블](https://blog.rchapman.org/posts/Linux_System_Call_Table_for_x86_64/)
- [NASM 매뉴얼](https://www.nasm.us/doc/)
- [x86-64 ABI](https://refspecs.linuxbase.org/elf/x86_64-abi-0.99.pdf)
