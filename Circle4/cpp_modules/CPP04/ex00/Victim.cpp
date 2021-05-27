#include "Victim.hpp"

Victim::Victim()
    : mName("John Doe")
{
    std::cout << ANSI_COLOR_GREEN
              << "Some random victim called "
              << ANSI_COLOR_YELLOW
              << mName
              << ANSI_COLOR_GREEN
              << " just appeared!"
              << ANSI_COLOR_RESET
              << std::endl;
}

Victim::Victim(const std::string &name)
    : mName(name)
{
    std::cout << ANSI_COLOR_GREEN
              << "Some random victim called "
              << ANSI_COLOR_YELLOW
              << mName
              << ANSI_COLOR_GREEN
              << " just appeared!"
              << ANSI_COLOR_RESET
              << std::endl;
}

Victim::Victim(const Victim &victim)
{
    *this = victim;
    std::cout << ANSI_COLOR_GREEN
              << "Some random victim called "
              << ANSI_COLOR_YELLOW
              << mName
              << ANSI_COLOR_GREEN
              << " just appeared!"
              << ANSI_COLOR_RESET
              << std::endl;
}

Victim::~Victim()
{
    std::cout << ANSI_COLOR_GREEN
              << "Victim "
              << ANSI_COLOR_YELLOW
              << mName
              << ANSI_COLOR_GREEN
              << " just died for no apparent reason!"
              << ANSI_COLOR_RESET
              << std::endl;
}

Victim &Victim::operator=(const Victim &victim)
{
    mName = victim.mName;
    return (*this);
}

const std::string &Victim::getName() const
{
    return (mName);
}

void Victim::setName(const std::string &name)
{
    mName = name;
}

void Victim::getPolymorphed() const
{
    std::cout << ANSI_COLOR_YELLOW
              << mName
              << ANSI_COLOR_RED
              << " has been turned into a cute little sheep!"
              << ANSI_COLOR_RESET
              << std::endl;
}

std::ostream &operator<<(std::ostream &os, const Victim &victim)
{
    os << ANSI_COLOR_GREEN
       << "I am "
       << ANSI_COLOR_YELLOW
       << victim.getName()
       << ANSI_COLOR_GREEN
       << " and I like otters!"
       << std::endl;

    return os;
}
