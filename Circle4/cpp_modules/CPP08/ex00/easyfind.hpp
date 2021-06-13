#ifndef EASYFIND
#define EASYFIND

#include <algorithm>

class EmptyException : public std::exception
{
    virtual const char *what() const throw()
    {
        return ("EasyfindException: The container is empty");
    }
};

class NotFoundException : public std::exception
{
    virtual const char *what() const throw()
    {
        return ("EasyfindException: Value not found");
    }
};

template <typename T>
typename T::iterator easyfind(T &container, int value)
{
    if (container.begin() == container.end()) // if it is empty
        throw EmptyException();

    typename T::iterator found = std::find(container.begin(), container.end(), value);

    if (found == container.end()) // if value not found
        throw NotFoundException();

    return found;
}

#endif