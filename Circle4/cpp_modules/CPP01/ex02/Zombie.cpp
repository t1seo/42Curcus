#include "Zombie.hpp"

int Zombie::mZombieNum = 0;

Zombie::Zombie()
{
    mZombieNum++;
    name = "Zombie " + std::to_string(mZombieNum);
    type = "🧟";
}

Zombie::Zombie(std::string name, std::string type)
    : name(name), type(type)
{
    mZombieNum++;
}

Zombie::~Zombie()
{
    mZombieNum--;
}

void Zombie::announce(void) const
{
    std::cout << ANSI_COLOR_CYAN
              << "<" << name << " (" << type << ")>"
              << " Braiiiiiiinnnssss..."
              << ANSI_COLOR_RESET
              << std::endl;
}