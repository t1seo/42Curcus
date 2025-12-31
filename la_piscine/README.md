# La Piscine

## 프로젝트 개요

La Piscine(수영장)은 42 Seoul 입학을 위한 4주간의 집중 프로그래밍 부트캠프입니다. C 언어와 Shell 스크립팅의 기초를 학습하며, 42의 교육 방식에 적응하는 기간입니다.

## 구성

```
la_piscine/
├── Shell00/     # Shell 기초
└── Shell01/     # Shell 심화
```

## Shell00 - Shell 기초

### 학습 주제
- 기본 Shell 명령어
- 파일 권한
- 입출력 리다이렉션
- 파이프

### 주요 명령어

| 명령어 | 설명 |
|--------|------|
| `ls` | 파일 목록 표시 |
| `cd` | 디렉토리 이동 |
| `pwd` | 현재 디렉토리 출력 |
| `chmod` | 파일 권한 변경 |
| `cat` | 파일 내용 출력 |
| `touch` | 빈 파일 생성/시간 변경 |
| `mkdir` | 디렉토리 생성 |
| `rm` | 파일/디렉토리 삭제 |
| `cp` | 파일 복사 |
| `mv` | 파일 이동/이름 변경 |

### 파일 권한

```bash
# 권한 형식: rwxrwxrwx (소유자/그룹/기타)
chmod 755 file  # rwxr-xr-x
chmod 644 file  # rw-r--r--
chmod u+x file  # 소유자에게 실행 권한 추가
```

## Shell01 - Shell 심화

### 학습 주제
- 정규 표현식
- sed, awk
- 환경 변수
- Shell 스크립트 작성

### 주요 명령어

| 명령어 | 설명 |
|--------|------|
| `grep` | 패턴 검색 |
| `sed` | 스트림 편집기 |
| `awk` | 텍스트 처리 |
| `find` | 파일 검색 |
| `wc` | 단어/줄 수 세기 |
| `sort` | 정렬 |
| `uniq` | 중복 제거 |
| `cut` | 텍스트 잘라내기 |
| `tr` | 문자 변환 |
| `head/tail` | 앞/뒤 부분 출력 |

### grep 예시

```bash
grep "pattern" file         # 기본 검색
grep -r "pattern" dir/      # 재귀 검색
grep -i "pattern" file      # 대소문자 무시
grep -n "pattern" file      # 줄 번호 표시
grep -v "pattern" file      # 역 매칭
```

### sed 예시

```bash
sed 's/old/new/' file       # 첫 번째 매칭만 치환
sed 's/old/new/g' file      # 모든 매칭 치환
sed -n '5p' file            # 5번째 줄만 출력
sed '1d' file               # 첫 번째 줄 삭제
```

### awk 예시

```bash
awk '{print $1}' file       # 첫 번째 필드 출력
awk -F: '{print $1}' file   # 구분자 지정
awk 'NR==5' file            # 5번째 줄 출력
awk '{sum+=$1} END {print sum}' file  # 합계
```

## Piscine 일정 (4주)

### 1주차
- C00: C 언어 기초 (변수, 조건문, 반복문)
- Shell00: Shell 기초

### 2주차
- C01: 포인터 기초
- C02: 문자열 처리
- Shell01: Shell 심화

### 3주차
- C03: 문자열 함수
- C04: 숫자 처리 함수
- C05: 재귀 함수

### 4주차
- C06: argc, argv
- C07: 동적 메모리 할당
- C08: 헤더 파일, 매크로
- Rush: 팀 프로젝트

## 평가 시스템

- **동료 평가 (Peer Evaluation)**: 다른 학생들과 서로 코드 리뷰
- **Moulinette**: 자동 채점 시스템
- **시험**: 주 1회 시험

## 필수 도구

- **Git**: 버전 관리 및 과제 제출
- **Vim/Emacs**: 텍스트 편집기 (IDE 사용 금지)
- **gcc**: C 컴파일러

## Norminette

42의 코딩 스타일 규칙:
- 함수당 최대 25줄
- 한 줄 최대 80자
- 함수당 최대 4개의 매개변수
- 전역 변수 금지 (대부분의 과제)
- 들여쓰기는 탭 사용

```bash
norminette file.c
```

## 팁

1. **기초를 탄탄히**: 포인터, 메모리 관리 철저히 학습
2. **동료와 협력**: 서로 가르치며 학습
3. **Man 페이지 활용**: `man 함수명`으로 문서 확인
4. **충분한 테스트**: 엣지 케이스 고려
5. **시간 관리**: 4주는 생각보다 짧음
