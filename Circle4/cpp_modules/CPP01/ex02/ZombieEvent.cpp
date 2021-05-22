#include "ZombieEvent.hpp"

ZombieEvent::ZombieEvent()
{
    std::srand(std::time(NULL));
    this->type = "🧟";
}

void ZombieEvent::setZombieType(std::string type)
{
    this->type = type;
}

Zombie *ZombieEvent::newZombie(std::string name)
{
    return (new Zombie(this->type, name));
}

Zombie *ZombieEvent::randomChump()
{
    std::string zombiePool[] = {
        "John Lennon",
        "Paul McCartney",
        "George Harrison",
        "Ringo Starr"};

    int len = sizeof(zombiePool) / sizeof(std::string);

    std::string name = zombiePool[rand() % len];
    Zombie *zombie = new Zombie(name, this->type);
    zombie->announce();
    return zombie;
}