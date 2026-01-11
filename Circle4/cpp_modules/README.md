# CPP Modules

## Project Overview

CPP Modules is a series for learning core C++ concepts step by step. It consists of 9 modules (CPP00 ~ CPP08), each focusing on specific C++ concepts.

## Module Structure

### CPP00 - C++ Basics
- **Topics**: Namespaces, classes, member functions, stdio streams, initialization lists, static, const
- **Exercises**:
  - ex00: String uppercase conversion
  - ex01: PhoneBook class implementation

### CPP01 - Memory Management
- **Topics**: new/delete, references, difference between pointers and references, file streams
- **Key Concepts**:
  ```cpp
  // new/delete
  int *ptr = new int(42);
  delete ptr;

  int *arr = new int[10];
  delete[] arr;

  // Reference
  int a = 10;
  int &ref = a;  // ref is an alias for a
  ```

### CPP02 - Operator Overloading
- **Topics**: Ad-hoc polymorphism, operator overloading, Orthodox Canonical Form
- **Canonical Form**:
  ```cpp
  class Sample {
  public:
      Sample();                              // Default constructor
      Sample(const Sample& other);           // Copy constructor
      Sample& operator=(const Sample& rhs);  // Assignment operator
      ~Sample();                             // Destructor
  };
  ```

### CPP03 - Inheritance
- **Topics**: Inheritance, access specifiers, multiple inheritance, diamond problem
- **Inheritance Example**:
  ```cpp
  class Animal {
  protected:
      std::string name;
  public:
      virtual void speak() = 0;  // Pure virtual function
  };

  class Dog : public Animal {
  public:
      void speak() override { std::cout << "Woof!" << std::endl; }
  };
  ```

### CPP04 - Polymorphism
- **Topics**: Subtype polymorphism, abstract classes, interfaces
- **Virtual Functions**:
  ```cpp
  class Base {
  public:
      virtual ~Base() {}  // Virtual destructor
      virtual void func() { std::cout << "Base" << std::endl; }
  };

  class Derived : public Base {
  public:
      void func() override { std::cout << "Derived" << std::endl; }
  };
  ```

### CPP05 - Exception Handling
- **Topics**: try/catch, throw, custom exceptions
- **Exception Handling**:
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

### CPP06 - Type Casting
- **Topics**: static_cast, dynamic_cast, reinterpret_cast, const_cast
- **Cast Types**:
  ```cpp
  // static_cast - Compile-time type conversion
  double d = 3.14;
  int i = static_cast<int>(d);

  // dynamic_cast - Runtime type checking (requires polymorphism)
  Base* base = new Derived();
  Derived* derived = dynamic_cast<Derived*>(base);

  // reinterpret_cast - Bit-level reinterpretation
  int* p = reinterpret_cast<int*>(0x12345678);

  // const_cast - Remove const
  const int* cp = &i;
  int* mp = const_cast<int*>(cp);
  ```

### CPP07 - Templates
- **Topics**: Function templates, class templates
- **Template Examples**:
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

### CPP08 - STL Containers
- **Topics**: STL containers, iterators, algorithms
- **Main Containers**:
  ```cpp
  #include <vector>
  #include <list>
  #include <map>
  #include <stack>
  #include <algorithm>

  std::vector<int> vec = {1, 2, 3, 4, 5};
  std::list<int> lst(vec.begin(), vec.end());
  std::map<std::string, int> mp;

  // Algorithms
  std::sort(vec.begin(), vec.end());
  auto it = std::find(vec.begin(), vec.end(), 3);
  ```

## Folder Structure

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
└── Practice/        # Practice code
```

## Build (In each exercise folder)

```bash
make        # Compile
make clean  # Remove object files
make fclean # Remove all
make re     # Rebuild
```

## Compiler Flags

```
c++ -Wall -Wextra -Werror -std=c++98
```

**Note**: 42 projects must use C++98 standard.

## Forbidden Features

- STL containers (before CPP08)
- `<algorithm>` header (before CPP08)
- `using namespace std;`
- `friend` keyword (except where explicitly allowed)

## References

- [cppreference.com](https://en.cppreference.com/)
- [C++ Core Guidelines](https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines)
