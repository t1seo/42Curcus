#include <iostream>
#include "mutantstack.hpp"
#include "mutantstack.cpp"

int main()
{
    MutantStack<int> mstack;

    mstack.push(5);
    mstack.push(17);

    std::cout << "top: " << mstack.top() << std::endl;

    mstack.pop();

    std::cout << "size: " << mstack.size() << std::endl;

    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(10);
    mstack.push(0);

    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();

    ++it;
    --it;
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }
    std::stack<int> s(mstack);

    // reverse
    MutantStack<int> reverse;
    reverse.push(1);
    reverse.push(2);
    reverse.push(3);
    reverse.push(4);
    reverse.push(5);
    for (MutantStack<int>::reverse_iterator iter = reverse.rbegin(); iter != reverse.rend(); iter++)
        std::cout << "reverse : " << *iter << std::endl;

    return 0;
}
