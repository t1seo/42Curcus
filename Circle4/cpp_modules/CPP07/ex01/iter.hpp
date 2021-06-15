#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template <typename T>
void iter(T *arr, std::size_t len, void (*f)(T const &))
{
    if (arr == NULL)
        std::cout << "Error: Parameter arr is NULL" << std::endl;
    else
    {
        for (std::size_t i = 0; i < len; ++i)
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