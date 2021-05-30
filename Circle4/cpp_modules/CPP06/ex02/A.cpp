#include "A.hpp"

A::A()
{
}

A::A(const A &a)
{
    *this = a;
}

A::~A()
{
}

A &A::operator=(const A &a)
{
    (void)a;
    return (*this);
}
