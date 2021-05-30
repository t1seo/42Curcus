#include "C.hpp"

C::C()
{
}

C::C(const C &c)
{
    *this = c;
}

C::~C()
{
}

C &C::operator=(const C &c)
{
    (void)c;
    return (*this);
}
