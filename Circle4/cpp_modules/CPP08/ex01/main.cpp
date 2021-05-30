// TODO : remake main
#include "span.hpp"

int main()
{
    Span sp(5);

    sp.addNumber(3);
    // span을 구하려면 원소 2개가 필요한데 1개밖에없어서 예외처리
    try
    {
        std::cout << sp.shortestSpan() << '\n';
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }

    sp.addNumber(10);
    sp.addNumber(6);
    sp.addNumber(16);
    sp.addNumber(1);
    // sp의 크기가 5라 그 크기 이상 원소를 넣으면 예외처리
    try
    {
        sp.addNumber(21);
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
    std::cout << sp.shortestSpan() << '\n';
    std::cout << sp.longestSpan() << '\n';

    std::vector<int> temp;
    Span sp2(10000);

    for (int i = 0; i < 10000; i++)
        temp.push_back(i * 3);               // 0부터 29997이 들어감
    sp2.addNumber(temp.begin(), temp.end()); // addNumber 한번호출로 원소 10000개 다넣음
    std::cout << sp2.shortestSpan() << '\n';
    std::cout << sp2.longestSpan() << '\n';
}