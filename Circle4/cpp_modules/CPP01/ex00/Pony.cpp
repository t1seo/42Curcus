#include "Pony.hpp"

Pony::Pony(std::string name)
    : mName(name)
{
    std::cout << ANSI_COLOR_BLUE
              << "The " << mName << " was born."
              << ANSI_COLOR_RESET
              << std::endl;
}

Pony::~Pony()
{
    std::cout << ANSI_COLOR_RED
              << "The " << mName << " is died."
              << ANSI_COLOR_RESET
              << std::endl;
}

void Pony::Eat(void) const
{
    std::cout << mName << " is eating" << std::endl;
}

void Pony::Run(void) const
{

    std::cout << mName << " is running" << std::endl;
}

void Pony::Sleep(void) const
{

    std::cout << mName << " is sleeping" << std::endl;
}
