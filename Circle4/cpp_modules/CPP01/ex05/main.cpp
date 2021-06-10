#include "Human.hpp"

int main()
{
    Human bob;

    bob.getThink();

    std::cout << bob.identify() << std::endl;
    std::cout << bob.getBrain().identify() << std::endl;
}