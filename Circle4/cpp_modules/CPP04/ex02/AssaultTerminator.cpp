#include "AssaultTerminator.hpp"

AssaultTerminator::AssaultTerminator()
{
    std::cout << ANSI_COLOR_BLUE
              << "* teleports from space *"
              << ANSI_COLOR_RESET
              << std::endl;
}

AssaultTerminator::AssaultTerminator(const AssaultTerminator &assaultTerminator)
{
    *this = assaultTerminator;
    std::cout << ANSI_COLOR_BLUE
              << "* teleports from space *"
              << ANSI_COLOR_RESET
              << std::endl;
}

AssaultTerminator::~AssaultTerminator()
{
    std::cout << ANSI_COLOR_BLUE
              << "I'll be back..."
              << ANSI_COLOR_RESET
              << std::endl;
}

AssaultTerminator &AssaultTerminator::operator=(const AssaultTerminator &assaultTerminator)
{
    (AssaultTerminator) assaultTerminator;
    return (*this);
}

ISpaceMarine *AssaultTerminator::clone() const
{
    return (new AssaultTerminator(*this));
}

void AssaultTerminator::battleCry() const
{
    std::cout << ANSI_COLOR_BLUE
              << "This code is unclean. PURIFY IT!"
              << ANSI_COLOR_RESET
              << std::endl;
}

void AssaultTerminator::rangedAttack() const
{
    std::cout << ANSI_COLOR_BLUE
              << "* does nothing *"
              << ANSI_COLOR_RESET
              << std::endl;
}

void AssaultTerminator::meleeAttack() const
{
    std::cout << ANSI_COLOR_BLUE
              << "* attacks with chainfists *"
              << ANSI_COLOR_RESET
              << std::endl;
}
