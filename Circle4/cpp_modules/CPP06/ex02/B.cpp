#include "B.hpp"

B::B()
{
}

B::B(const B &b)
{
    *this = b;
}

B::~B()
{
}

B &B::operator=(const B &b)
{
    (void)b;
    return (*this);
}
