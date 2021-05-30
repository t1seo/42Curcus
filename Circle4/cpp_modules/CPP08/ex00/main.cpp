// TODO : remake main file

#include "easyfind.hpp"
#include <iostream>
#include <vector>

int main(void)
{
    std::vector<int> vec1(5);  // 크키가 5인 int형 벡터 생성
    std::vector<char> vec2(5); // 크키가 5인 char형 벡터 생성

    // vec1에 1, 2, 3, 4, 5 저장
    for (unsigned int i = 0; i < vec1.size(); i++)
        vec1[i] = i + 1;

    // vec2에 a, b, c, d, e 저장
    for (unsigned int i = 0; i < vec2.size(); i++)
        vec2[i] = 'a' + i;

    // 5있음
    try
    {
        std::vector<int>::iterator found = easyfind(vec1, 5);
        std::cout << *found << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
    // 6 없음
    try
    {
        easyfind(vec1, 6);
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }

    // a 있음
    try
    {
        std::vector<char>::iterator found = easyfind(vec2, 'a');
        std::cout << *found << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
    // z 없음
    try
    {
        easyfind(vec2, 'z');
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
}