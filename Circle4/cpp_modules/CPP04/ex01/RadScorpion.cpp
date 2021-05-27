#include "RadScorpion.hpp"
RadScorpion::RadScorpion()
    : Enemy(80, "RadScorpion")
{
    std::cout << ANSI_COLOR_MAGENTA
              << "* click click click *"
              << ANSI_COLOR_RESET
              << std::endl;
}

RadScorpion::RadScorpion(const RadScorpion &radScorpion)
    : Enemy(radScorpion)
{
    *this = radScorpion;
    std::cout << ANSI_COLOR_MAGENTA
              << "* click click click *"
              << ANSI_COLOR_RESET
              << std::endl;
}

RadScorpion::~RadScorpion()
{
    std::cout << ANSI_COLOR_MAGENTA
              << "* SPROTCH *"
              << ANSI_COLOR_RESET
              << std::endl;
}

RadScorpion &RadScorpion::operator=(const RadScorpion &radScorpion)
{
    setHP(radScorpion.getHP());
    setType(radScorpion.getType());
    return (*this);
}

void RadScorpion::takeDamage(int damage)
{
    Enemy::takeDamage(damage);
}
