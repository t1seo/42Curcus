#include "Peasant.hpp"

Peasant::Peasant() : Victim()
{
    std::cout << ANSI_COLOR_MAGENTA
              << "I'm a Peasant."
              << ANSI_COLOR_RESET
              << std::endl;
}

Peasant::Peasant(const std::string &name)
    : Victim(name)
{
    std::cout << ANSI_COLOR_MAGENTA
              << "I'm a Peasant."
              << ANSI_COLOR_RESET
              << std::endl;
}

Peasant::Peasant(const Peasant &peasant)
    : Victim(peasant)
{
    *this = peasant;
    std::cout << ANSI_COLOR_MAGENTA
              << "I'm a Peasant."
              << ANSI_COLOR_RESET
              << std::endl;
}

Peasant::~Peasant()
{
    std::cout << ANSI_COLOR_MAGENTA
              << "Bye Bye"
              << ANSI_COLOR_RESET
              << std::endl;
}

Peasant &Peasant::operator=(const Peasant &peasant)
{
    setName(peasant.getName());
    return (*this);
}

void Peasant::getPolymorphed() const
{
    std::cout << ANSI_COLOR_YELLOW
              << getName()
              << ANSI_COLOR_RED
              << " has been turned into a chicken!"
              << ANSI_COLOR_RESET
              << std::endl;
}
