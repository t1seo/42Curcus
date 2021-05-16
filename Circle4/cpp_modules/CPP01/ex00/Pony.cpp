#include "Pony.hpp"

void Pony::Eat(void) const
{
    std::cout << this->mName << " is eating" << std::endl;
}

void Pony::Run(void) const
{

    std::cout << this->mName << " is running" << std::endl;
}

void Pony::Sleep(void) const
{

    std::cout << this->mName << " is sleeping" << std::endl;
}

Pony::Pony(const std::string &name)
    : mName(name)
{
    std::cout << "The " << this->mName << " was born." << std::endl;
}

Pony::~Pony()
{
    std::cout << "The " << this->mName << " is died." << std::endl;
}