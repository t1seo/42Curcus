#ifndef ZOMBIE_EVENT
#define ZOMBIE_EVENT

#include <cstdlib>
#include <time.h>

#include "Zombie.hpp"

class ZombieEvent
{
public:
    ZombieEvent();
    void setZombieType(std::string type);
    Zombie *newZombie(std::string name);
    Zombie *randomChump();

private:
    std::string type;
};

#endif