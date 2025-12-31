# CPP Modules

## 프로젝트 개요

CPP Modules는 C++의 핵심 개념들을 단계별로 학습하는 시리즈입니다. 총 9개의 모듈(CPP00 ~ CPP08)로 구성되어 있으며, 각 모듈은 특정 C++ 개념에 초점을 맞춥니다.

## 모듈 구성

### CPP00 - C++ 기초
- **학습 주제**: 네임스페이스, 클래스, 멤버 함수, stdio 스트림, 초기화 리스트, static, const
- **예제**:
  - ex00: 문자열 대문자 변환
  - ex01: PhoneBook 클래스 구현

### CPP01 - 메모리 관리
- **학습 주제**: new/delete, 참조, 포인터와 참조의 차이, 파일 스트림
- **핵심 개념**:
  ```cpp
  // new/delete
  int *ptr = new int(42);
  delete ptr;

  int *arr = new int[10];
  delete[] arr;

  // 참조
  int a = 10;
  int &ref = a;  // ref는 a의 별칭
  ```

### CPP02 - 연산자 오버로딩
- **학습 주제**: Ad-hoc 다형성, 연산자 오버로딩, 정규 형식 (Orthodox Canonical Form)
- **정규 형식**:
  ```cpp
  class Sample {
  public:
      Sample();                              // 기본 생성자
      Sample(const Sample& other);           // 복사 생성자
      Sample& operator=(const Sample& rhs);  // 할당 연산자
      ~Sample();                             // 소멸자
  };
  ```

### CPP03 - 상속
- **학습 주제**: 상속, 접근 지정자, 다중 상속, 다이아몬드 문제
- **상속 예시**:
  ```cpp
  class Animal {
  protected:
      std::string name;
  public:
      virtual void speak() = 0;  // 순수 가상 함수
  };

  class Dog : public Animal {
  public:
      void speak() override { std::cout << "Woof!" << std::endl; }
  };
  ```

### CPP04 - 다형성
- **학습 주제**: 서브타입 다형성, 추상 클래스, 인터페이스
- **가상 함수**:
  ```cpp
  class Base {
  public:
      virtual ~Base() {}  // 가상 소멸자
      virtual void func() { std::cout << "Base" << std::endl; }
  };

  class Derived : public Base {
  public:
      void func() override { std::cout << "Derived" << std::endl; }
  };
  ```

### CPP05 - 예외 처리
- **학습 주제**: try/catch, throw, 사용자 정의 예외
- **예외 처리**:
  ```cpp
  class GradeTooHighException : public std::exception {
  public:
      const char* what() const throw() {
          return "Grade is too high!";
      }
  };

  try {
      throw GradeTooHighException();
  } catch (std::exception& e) {
      std::cerr << e.what() << std::endl;
  }
  ```

### CPP06 - 타입 캐스팅
- **학습 주제**: static_cast, dynamic_cast, reinterpret_cast, const_cast
- **캐스팅 종류**:
  ```cpp
  // static_cast - 컴파일 타임 타입 변환
  double d = 3.14;
  int i = static_cast<int>(d);

  // dynamic_cast - 런타임 타입 확인 (다형성 필요)
  Base* base = new Derived();
  Derived* derived = dynamic_cast<Derived*>(base);

  // reinterpret_cast - 비트 단위 재해석
  int* p = reinterpret_cast<int*>(0x12345678);

  // const_cast - const 제거
  const int* cp = &i;
  int* mp = const_cast<int*>(cp);
  ```

### CPP07 - 템플릿
- **학습 주제**: 함수 템플릿, 클래스 템플릿
- **템플릿 예시**:
  ```cpp
  template <typename T>
  T max(T a, T b) {
      return (a > b) ? a : b;
  }

  template <typename T>
  class Array {
  private:
      T* data;
      size_t size;
  public:
      Array(size_t n) : data(new T[n]()), size(n) {}
      T& operator[](size_t i) { return data[i]; }
  };
  ```

### CPP08 - STL 컨테이너
- **학습 주제**: STL 컨테이너, 반복자, 알고리즘
- **주요 컨테이너**:
  ```cpp
  #include <vector>
  #include <list>
  #include <map>
  #include <stack>
  #include <algorithm>

  std::vector<int> vec = {1, 2, 3, 4, 5};
  std::list<int> lst(vec.begin(), vec.end());
  std::map<std::string, int> mp;

  // 알고리즘
  std::sort(vec.begin(), vec.end());
  auto it = std::find(vec.begin(), vec.end(), 3);
  ```

## 폴더 구조

```
cpp_modules/
├── CPP00/
│   ├── ex00/
│   └── ex01/
├── CPP01/
│   └── ex00-ex07/
├── CPP02/
│   └── ex00-ex03/
├── CPP03/
│   └── ex00-ex03/
├── CPP04/
│   └── ex00-ex03/
├── CPP05/
│   └── ex00-ex03/
├── CPP06/
│   └── ex00-ex02/
├── CPP07/
│   └── ex00-ex02/
├── CPP08/
│   └── ex00-ex02/
└── Practice/        # 연습 코드
```

## 빌드 (각 exercise 폴더에서)

```bash
make        # 컴파일
make clean  # 오브젝트 파일 삭제
make fclean # 전체 삭제
make re     # 재빌드
```

## 컴파일러 플래그

```
c++ -Wall -Wextra -Werror -std=c++98
```

**주의**: 42 과제에서는 C++98 표준을 사용해야 합니다.

## 금지된 기능

- STL 컨테이너 (CPP08 이전)
- `<algorithm>` 헤더 (CPP08 이전)
- `using namespace std;`
- `friend` 키워드 (명시적으로 허용된 경우 제외)

## 참고 자료

- [cppreference.com](https://en.cppreference.com/)
- [C++ Core Guidelines](https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines)
