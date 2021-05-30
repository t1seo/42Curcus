#include "mutantstack.hpp"

template <typename T>
MutantStack<T>::MutantStack()
{
}

template <typename T>
MutantStack<T>::MutantStack(const MutantStack<T> &mutantStack)
{
    *this = mutantStack;
}

template <typename T>
MutantStack<T>::~MutantStack()
{
}

template <typename T>
MutantStack<T> &MutantStack<T>::operator=(const MutantStack<T> &mutantStack)
{
    this->c = mutantStack.c;
    return (*this);
}

template <typename T>
typename MutantStack<T>::iter MutantStack<T>::begin()
{
    return (this->c.begin());
}

template <typename T>
typename MutantStack<T>::iter MutantStack<T>::end()
{
    return (this->c.end());
}
