#include "PowerFist.hpp"
PowerFist::PowerFist()
    : AWeapon("Power Fist", 8, 50)
{
}

PowerFist::PowerFist(const PowerFist &powerFist)
    : AWeapon(powerFist)
{
    *this = powerFist;
}

PowerFist::~PowerFist()
{
}

PowerFist &PowerFist::operator=(const PowerFist &powerFist)
{
    setName(powerFist.getName());
    setAPCost(powerFist.getAPCost());
    setDamage(powerFist.getDamage());
    return (*this);
}

void PowerFist::attack() const
{
    std::cout << ANSI_COLOR_BLUE
              << "* pschhh... SBAM! *"
              << ANSI_COLOR_RESET
              << std::endl;
}
