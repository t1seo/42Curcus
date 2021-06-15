#include <iostream>
#include "whatever.hpp"

class Awesome
{
public:
    Awesome(int n) : _n(n) {}

    bool operator==(Awesome const &rhs) const { return (this->_n == rhs._n); }
    bool operator!=(Awesome const &rhs) const { return (this->_n != rhs._n); }
    bool operator>(Awesome const &rhs) const { return (this->_n > rhs._n); }
    bool operator<(Awesome const &rhs) const { return (this->_n < rhs._n); }
    bool operator>=(Awesome const &rhs) const { return (this->_n >= rhs._n); }
    bool operator<=(Awesome const &rhs) const { return (this->_n <= rhs._n); }

    int getNumber() const { return (this->_n); }

private:
    int _n;
};

std::ostream &operator<<(std::ostream &out, Awesome const &awe)
{
    out << awe.getNumber();
    return (out);
}

template <typename T>
void printResult(T &a, T &b)
{
    std::cout << "a: " << a << ", "
              << "b: " << b << std::endl;

    swap(a, b);
    std::cout << "SWAP: "
              << a << ", " << b << std::endl;
    std::cout << "MAX: " << max(a, b) << std::endl;
    std::cout << "MIN: " << min(a, b) << std::endl
              << std::endl;
}

int main(void)
{
    int a = 10;
    int b = 20;
    printResult(a, b);

    float c = 30.0f;
    float d = 40.0f;
    printResult(c, d);

    double e = 100.0;
    double f = 200.0;
    printResult(e, f);

    std::string s1 = "str1";
    std::string s2 = "str2";
    printResult(s1, s2);

    // class test
    Awesome awe1(50);
    Awesome awe2(100);
    ::swap(awe1, awe2);
    std::cout << "awe1: " << awe1 << ", awe2: " << awe2 << std::endl;
    std::cout << "min(awe1, awe2) = " << ::min(awe1, awe2) << std::endl;
    std::cout << "max(awe1, awe2) = " << ::max(awe1, awe2) << std::endl;

    return 0;
}