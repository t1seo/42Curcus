#ifndef EASYFIND
#define EASYFIND

#include <algorithm>

template <typename T>
typename T::iterator easyfind(T &container, int value)
{
    typename T::iterator found = std::find(container.begin(), container.end(), value);

    if (found == container.end())
        throw std::exception();
    return found;
}

#endif