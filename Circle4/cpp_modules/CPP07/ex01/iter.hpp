#ifndef ITER
#define ITER

#include <iostream>

template <typename T>
void iter(T *arr, std::size_t len, void (*f)(T &elem))
{
    for (std::size_t i = 0; i < len; ++i)
    {
        (*f)(arr[i]);
    }
}

template <typename T>
void printElem(T &elem)
{
    std::cout << elem << " ";
}

template <typename T>
void printElemPlus5(T &elem)
{
    std::cout << elem + 5 << " ";
}

#endif