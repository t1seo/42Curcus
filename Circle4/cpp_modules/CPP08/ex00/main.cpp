#include <iostream>
#include <vector>
#include <deque>
#include "easyfind.hpp"

int main(void)
{
    // empty vector
    std::vector<int> vec1;
    try
    {
        std::cout << *easyfind(vec1, 10) << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }

    // found something
    std::vector<int> vec2;
    for (int i = 0; i < 5; i++)
    {
        vec2.push_back(i * 10);
    }
    try
    {
        std::cout << *easyfind(vec2, 10) << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }

    // not found
    std::vector<int> vec3;
    for (int i = 0; i < 5; i++)
    {
        vec3.push_back(i * 10);
    }
    try
    {
        std::cout << *easyfind(vec3, 100) << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }

    // deque
    std::deque<int> deque1;
    for (int i = 0; i < 5; i++)
    {
        deque1.push_back(i * 10);
    }
    try
    {
        std::cout << *easyfind(deque1, 20) << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
}