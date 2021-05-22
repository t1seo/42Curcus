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

void Zombie::setName(std::string name)
{
    this->name = name;
}

void Zombie::setType(std::string type)
{
    this->type = type;
}

void Zombie::announce() const
{
    std::cout << ANSI_COLOR_CYAN
              << "<" << name << " (" << type << ")>"
              << " Braiiiiiiinnnssss..."
              << ANSI_COLOR_RESET
              << std::endl;
}