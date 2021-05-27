#include "PlasmaRifle.hpp"

PlasmaRifle::PlasmaRifle()
    : AWeapon("Plasma Rifle", 5, 21)
{
}

PlasmaRifle::PlasmaRifle(const PlasmaRifle &plasmaRifle)
    : AWeapon(plasmaRifle)
{
    *this = plasmaRifle;
}

PlasmaRifle::~PlasmaRifle()
{
}

PlasmaRifle &PlasmaRifle::operator=(const PlasmaRifle &plasmaRifle)
{
    setName(plasmaRifle.getName());
    setAPCost(plasmaRifle.getAPCost());
    setDamage(plasmaRifle.getDamage());
    return (*this);
}

void PlasmaRifle::attack() const
{
    std::cout << ANSI_COLOR_BLUE
              << "* piouuu piouuu piouuu *"
              << ANSI_COLOR_RESET
              << std::endl;
}
