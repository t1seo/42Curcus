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
    mSize = span.getSize();
    mVector = span.getVector();
    return (*this);
}

int Span::getSize() const
{
    return mSize;
}

std::vector<int> Span::getVector() const
{
    return mVector;
}

void Span::addNumber(int value)
{
    if (mVector.size() >= mSize)
        throw Span::NoSpaceException();
    mVector.push_back(value);
}

// void Span::addNumber(iter begin, iter end)
// {
//     if (this->mVector.size() + std::distance(begin, end) > this->mSize)
//         throw Span::NoSpaceException();
//     this->mVector.insert(mVector.end(), begin, end);
// }

// TODO: remake longestSpan
unsigned int Span::longestSpan()
{
    if (mVector.size() < 2)
        throw Span::NoSpanException();

    sort(mVector.begin(), mVector.end());
    return (*(--mVector.end()) - *mVector.begin());
}

// TODO: remake shortestSpan
unsigned int Span::shortestSpan()
{
    if (mVector.size() < 2)
        throw Span::NoSpanException();

    std::vector<int> vec1(mVector);        // temp vector
    std::vector<int> vec2(mVector.size()); // to save adjacent_difference and find shortest span (minimum value)

    std::sort(vec1.begin(), vec1.end()); // sort vector1
    // TODO: adjacent_difference is C++20 method so it have to be changed
    std::adjacent_difference(vec1.begin(), vec1.end(), vec2.begin()); // get adjacent differences and save them to the vec2

    std::sort(vec2.begin() + 1, vec2.end()); // sort the vector2 to get minimum // TODO: using find minimum

    return vec2[1];
}

const char *Span::NoSpaceException::what() const throw()
{
    return ("SpanException: There is no space.");
}

const char *Span::NoSpanException::what() const throw()
{
    return ("SpanException: There is no span.");
}
