#ifndef SPAN
#define SPAN

#include <iostream>
#include <vector>
#include <iterator>
#include <numeric>
#include <algorithm>

typedef std::vector<int>::iterator iter;

class Span
{
public:
    Span(unsigned int n);
    ~Span();
    Span(const Span &span);
    Span &operator=(const Span &span);

    std::vector<int> getVector() const;
    void addNumber(int value);
    void addNumber(iter begin, iter end);
    unsigned int longestSpan();
    unsigned int shortestSpan();

    class NoSpaceException : public std::exception
    {
        virtual const char *what() const throw();
    };

    class NoSpanException : public std::exception
    {
        virtual const char *what() const throw();
    };

private:
    Span();
    unsigned int mSize;
    std::vector<int> mVector;
};

#endif