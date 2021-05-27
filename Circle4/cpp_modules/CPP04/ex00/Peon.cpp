#include "Peon.hpp"

Peon::Peon() : Victim()
{
    std::cout << ANSI_COLOR_MAGENTA
              << "Zog zog."
              << ANSI_COLOR_RESET
              << std::endl;
}

Peon::Peon(const std::string &name)
    : Victim(name)
{
    std::cout << ANSI_COLOR_MAGENTA
              << "Zog zog."
              << ANSI_COLOR_RESET
              << std::endl;
}

Peon::Peon(const Peon &peon)
    : Victim(peon)
{
    *this = peon;
    std::cout << ANSI_COLOR_MAGENTA
              << "Zog zog."
              << ANSI_COLOR_RESET
              << std::endl;
}

Peon::~Peon()
{
    std::cout << ANSI_COLOR_MAGENTA
              << "Bleuark..."
              << ANSI_COLOR_RESET
              << std::endl;
}

Peon &Peon::operator=(const Peon &peon)
{
    setName(peon.getName());
    return (*this);
}

void Peon::getPolymorphed() const
{
    std::cout << ANSI_COLOR_YELLOW
              << getName()
              << ANSI_COLOR_RED
              << " has been turned into a pink pony!"
              << ANSI_COLOR_RESET
              << std::endl;
}
