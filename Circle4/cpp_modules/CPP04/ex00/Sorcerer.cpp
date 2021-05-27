#include "Sorcerer.hpp"

Sorcerer::Sorcerer(const std::string &name, const std::string &title)
    : mName(name), mTitle(title)
{
    std::cout << ANSI_COLOR_YELLOW
              << mName
              << ANSI_COLOR_GREEN
              << ", "
              << ANSI_COLOR_YELLOW
              << mTitle
              << ANSI_COLOR_GREEN
              << ", is born!"
              << ANSI_COLOR_RESET
              << std::endl;
}

Sorcerer::Sorcerer(const Sorcerer &sorcerer)
{
    *this = sorcerer;
    std::cout << ANSI_COLOR_YELLOW
              << mName
              << ANSI_COLOR_GREEN
              << ", "
              << ANSI_COLOR_YELLOW
              << mTitle
              << ANSI_COLOR_GREEN
              << ", is born!"
              << ANSI_COLOR_RESET
              << std::endl;
}

Sorcerer::~Sorcerer()
{
    std::cout << ANSI_COLOR_YELLOW
              << mName
              << ANSI_COLOR_GREEN
              << ", "
              << ANSI_COLOR_YELLOW
              << mTitle
              << ANSI_COLOR_GREEN
              << ", is dead. Consequences will never be the same!"
              << ANSI_COLOR_RESET
              << std::endl;
}

Sorcerer &Sorcerer::operator=(const Sorcerer &sorcerer)
{
    mName = sorcerer.mName;
    mTitle = sorcerer.mTitle;

    return (*this);
}

std::string Sorcerer::getName() const
{
    return (mName);
}

std::string Sorcerer::getTitle() const
{
    return (mTitle);
}

void Sorcerer::polymorph(const Victim &victim) const
{
    victim.getPolymorphed();
}

std::ostream &operator<<(std::ostream &os, const Sorcerer &sorcerer)
{
    os << ANSI_COLOR_GREEN
       << "I am "
       << ANSI_COLOR_YELLOW
       << sorcerer.getName()
       << ANSI_COLOR_GREEN
       << ", "
       << ANSI_COLOR_YELLOW
       << sorcerer.getTitle()
       << ANSI_COLOR_GREEN
       << ", and I like ponies!"
       << std::endl;

    return os;
}
