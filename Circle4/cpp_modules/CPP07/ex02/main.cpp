#include <iostream>
#include "Array.hpp"

int main(void)
{
    // print array
    Array<int> arr1(10);
    for (int i = 0; i < static_cast<int>(arr1.size()); i++)
        arr1[i] = i; // access writing
    for (int i = 0; i < static_cast<int>(arr1.size()); i++)
        std::cout << arr1[i] << ' '; // access reading
    std::cout << std::endl;

    // TODO: assignation

    // raise out of range exception
    try
    {
        arr1[10] = 10;
    }
    catch (const std::exception &e)
    {
        std::cout << e.what() << '\n';
    }

    // size 0 array
    Array<char> arr2(0);
    try
    {
        std::cout << arr2[0];
    }
    catch (const std::exception &e)
    {
        std::cout << e.what() << '\n';
    }

    Array<double> const arr3(3); // const Array
    for (int i = 0; i < static_cast<int>(arr3.size()); i++)
        std::cout << arr3[i] << ' ';
}