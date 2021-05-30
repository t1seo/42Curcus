#ifndef MUTANTSTACK
#define MUTANTSTACK

#include <stack>

template <typename T>
class MutantStack : public std::stack<T>
{
public:
    MutantStack();
    MutantStack(const MutantStack<T> &mutantStack);
    ~MutantStack();
    MutantStack<T> &operator=(const MutantStack<T> &mutantStack);

    typedef typename std::stack<T>::container_type::iterator iter;
    iter begin();
    iter end();
};

#endif