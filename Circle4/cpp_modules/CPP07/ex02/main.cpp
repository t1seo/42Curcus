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

    // const Array
    Array<double> const arr3(3);
    for (int i = 0; i < static_cast<int>(arr3.size()); i++)
        std::cout << arr3[i] << ' ';
    std::cout << std::endl;

    // assignment test
    // Array<int> arr4(arr1);
    Array<int> arr4;
    arr4 = arr1;
    for (int i = 0; i < static_cast<int>(arr4.size()); i++)
        arr1[i] = i; // access writing
    for (int i = 0; i < static_cast<int>(arr4.size()); i++)
        std::cout << arr1[i] << ' '; // access reading
    std::cout << std::endl;

    return 0;
}