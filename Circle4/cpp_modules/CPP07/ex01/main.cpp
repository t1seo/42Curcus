#include "iter.hpp"
#include <iostream>

class Awesome
{
public:
    Awesome(void) : _n(42) { return; }
    int get(void) const { return this->_n; }

private:
    int _n;
};

std::ostream &operator<<(std::ostream &o, Awesome const &rhs)
{
    o << rhs.get();
    return o;
}

template <typename T>
void print(T const &x)
{
    std::cout << x << std::endl;
    return;
}

int main(void)
{
    int iArr[5] = {1, 2, 3, 4, 5};
    float fArr[5] = {10.0f, 20.0f, 30.0f, 40.0f, 50.0f};
    double dArr[5] = {100.0, 200.0, 300.0, 400.0, 500.0};
    std::string sArr[5] = {"A", "B", "C", "D", "E"};

    iter(iArr, sizeof(iArr) / sizeof(int), &printElem);
    std::cout << std::endl;
    iter(iArr, sizeof(iArr) / sizeof(int), &printElemPlus5);
    std::cout << std::endl;
    iter(fArr, sizeof(fArr) / sizeof(float), &printElem);
    std::cout << std::endl;
    iter(dArr, sizeof(dArr) / sizeof(double), &printElem);
    std::cout << std::endl;
    iter(sArr, sizeof(sArr) / sizeof(std::string), &printElem);
    std::cout << std::endl;

    // std::cout << "\n*** Test6 : Class ***" << std::endl;
    Awesome awesomes[5];
    ::iter(awesomes, 5, print);

    return 0;
}