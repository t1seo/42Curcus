#include <iostream>

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base *generate(void)
{
    int num = rand() % 3;

    switch (num)
    {
    case 0:
        return (new A);
        break;
    case 1:
        return (new B);
        break;
    case 2:
        return (new C);
        break;
    default:
        return NULL;
        break;
    }
}

void identify_from_pointer(Base *p)
{
    if (dynamic_cast<A *>(p))
    {
        std::cout << "A" << std::endl;
    }
    else if (dynamic_cast<B *>(p))
    {
        std::cout << "B" << std::endl;
    }
    else if (dynamic_cast<C *>(p))
    {
        std::cout << "C" << std::endl;
    }
}

void identify_from_reference(Base &p)
{
    try
    {
        (void)dynamic_cast<A &>(p);
        std::cout << "A" << std::endl;
    }
    catch (const std::exception &e)
    {
        // std::cerr << e.what() << '\n';
    }
    try
    {
        (void)dynamic_cast<B &>(p);
        std::cout << "B" << std::endl;
    }
    catch (const std::exception &e)
    {
        // std::cerr << e.what() << '\n';
    }
    try
    {
        (void)dynamic_cast<C &>(p);
        std::cout << "C" << std::endl;
    }
    catch (const std::exception &e)
    {
        // std::cerr << e.what() << '\n';
    }
}

int main(void)
{
    Base *base;
    base = generate();
    identify_from_pointer(base);
    identify_from_reference(*base);
    delete base;
}