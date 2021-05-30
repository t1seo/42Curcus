#include <iostream>
#include "whatever.hpp"

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

    std::string s1 = "chaine1";
    std::string s2 = "chaine2";
    printResult(s1, s2);

    return 0;
}