#include <iostream>
#include "Fixed.hpp"

int main(void)
{
    Fixed a;
    Fixed b(a); // Call Copy Constructor
    Fixed c;

    c = b; // Call Assignment Operator

    std::cout << a.getRawBits() << std::endl;
    std::cout << b.getRawBits() << std::endl;
    std::cout << c.getRawBits() << std::endl;

    return 0;
}