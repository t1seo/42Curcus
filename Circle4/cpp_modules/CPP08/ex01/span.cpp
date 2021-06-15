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

void Span::addNumber(iter begin, iter end)
{
    if (this->mVector.size() + std::distance(begin, end) > this->mSize)
        throw Span::NoSpaceException();
    this->mVector.insert(mVector.end(), begin, end);
}

// TODO: remake longestSpan
unsigned int Span::longestSpan()
{
    if (mVector.size() < 2)
        throw Span::NoSpanException();
    int max = *std::max_element(mVector.begin(), mVector.end()); // max num of vector
    int min = *std::min_element(mVector.begin(), mVector.end()); // min num of vector
    return (max - min);
}

// TODO: remake shortestSpan
unsigned int Span::shortestSpan()
{
    if (mVector.size() < 2)
        throw Span::NoSpanException();

    std::vector<int> vec1(mVector);        // the vector same as mVector
    std::vector<int> vec2(mVector.size()); // an empty vector same size of mVector

    std::sort(vec1.begin(), vec1.end());                              // sort the vector2
    std::adjacent_difference(vec1.begin(), vec1.end(), vec2.begin()); // save the adjacent difference of the vector1 to the vector2

    std::sort(vec2.begin() + 1, vec2.end()); // sort the vector2

    // std::cout << "ITER" << std::endl;
    // std::vector<int>::iterator iter;
    // for (iter = vec2.begin(); iter != vec2.end(); ++iter)
    // {
    //     std::cout << *iter << std::endl;
    // }
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
