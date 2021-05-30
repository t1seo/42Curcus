// TODO : remake main file

#include <iostream>
#include "Array.hpp"

int main(void)
{
    Array<int> arr1(10);
    for (int i = 0; i < 10; i++)
        arr1[i] = i;
    for (int i = 0; i < 10; i++)
        std::cout << arr1[i] << ' ';
    std::cout << '\n';
    try
    {
        arr1[10] = 10;
    }
    catch (const std::exception &e)
    {
        std::cout << e.what() << '\n';
    }

    Array<char> arr2(0);
    try
    {
        std::cout << arr2[0];
    }
    catch (const std::exception &e)
    {
        std::cout << e.what() << '\n';
    }

    // const 객체에도 인덱스 접근은 가능
    // const 객체를 반환하는 []연산자 오버로딩을 하지않으면 에러남
    Array<double> const arr3(3);
    for (int i = 0; i < 3; i++)
        std::cout << arr3[i] << ' ';
    std::cout << '\n';
}