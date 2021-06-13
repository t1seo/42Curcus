#include "span.hpp"

int main(void)
{
    Span s1(5);
    try
    {
        for (int i = 0; i < s1.getSize(); i++)
        {
            s1.addNumber(i * 10);
        }
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
    // std::cout << s1.longestSpan() << " " << s1.shortestSpan() << std::endl;
    std::cout << "Shortest Span of s1: " << s1.shortestSpan() << std::endl;

    // try
    // {
    //     s1.addNumber(100); // exception
    // }
    // catch (const std::exception &e)
    // {
    //     std::cerr << e.what() << '\n';
    // }

    // std::vector<int> vec;
    // Span s2(10000);

    // for (int i = 0; i < 10000; i++)
    //     vec.push_back(i * 10);
    // s2.addNumber(vec.begin(), vec.end());
    // std::cout << s2.longestSpan() << " " << s2.shortestSpan() << std::endl;
}