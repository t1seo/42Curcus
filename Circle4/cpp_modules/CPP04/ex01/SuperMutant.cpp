#include "SuperMutant.hpp"

SuperMutant::SuperMutant()
    : Enemy(170, "Super Mutant")
{
    std::cout << ANSI_COLOR_MAGENTA
              << "Gaaah. Me want smash heads!"
              << ANSI_COLOR_RESET
              << std::endl;
}

SuperMutant::SuperMutant(const SuperMutant &superMutant)
    : Enemy(superMutant)
{
    *this = superMutant;
    std::cout << ANSI_COLOR_MAGENTA
              << "Gaaah. Me want smash heads!"
              << ANSI_COLOR_RESET
              << std::endl;
}

SuperMutant::~SuperMutant()
{
    std::cout << ANSI_COLOR_MAGENTA
              << "Aaargh..."
              << ANSI_COLOR_RESET
              << std::endl;
}

SuperMutant &SuperMutant::operator=(const SuperMutant &superMutant)
{
    setHP(superMutant.getHP());
    setType(superMutant.getType());
    return (*this);
}

void SuperMutant::takeDamage(int damage)
{
    Enemy::takeDamage(damage - 3);
}
