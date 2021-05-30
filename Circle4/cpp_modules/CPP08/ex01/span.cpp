#include "span.hpp"

Span::Span(unsigned int n) : mSize(n)
{
}

Span::Span(const Span &span)
    : mSize(span.mSize), mVector(span.mVector)
{
}

Span::~Span()
{
}

Span &Span::operator=(const Span &span)
{
    if (this == &span)
        return (*this);
    *this = Span(span);
    return (*this);
}

std::vector<int> Span::getVector() const
{
    return mVector;
}

void Span::addNumber(int value)
{
    if (mVector.size() >= mSize)
        throw Span::NoSpanException();
    mVector.push_back(value);
}

void Span::addNumber(iter begin, iter end)
{
    if (this->mVector.size() + std::distance(begin, end) > this->mSize)
        throw Span::NoSpaceException();
    this->mVector.insert(mVector.end(), begin, end);
}

unsigned int Span::longestSpan()
{
    if (mVector.size() < 2)
        throw Span::NoSpanException();
    int min = *std::min_element(mVector.begin(), mVector.end());
    int max = *std::max_element(mVector.begin(), mVector.end());
    return (max - min);
}

unsigned int Span::shortestSpan()
{
    if (mVector.size() < 2)
        throw Span::NoSpanException();

    std::vector<int> temp(mVector);
    std::vector<int> span(mVector.size());

    std::sort(temp.begin(), temp.end());
    std::adjacent_difference(temp.begin(), temp.end(), span.begin());

    std::sort(span.begin() + 1, span.end());
    return span[1];
}

const char *Span::NoSpaceException::what() const throw()
{
    return ("SpanException: There is no space.");
}

const char *Span::NoSpanException::what() const throw()
{
    return ("SpanException: There is no span.");
}