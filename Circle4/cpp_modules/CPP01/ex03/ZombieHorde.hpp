#ifndef ZOMBIE_HORDE
#define ZOMBIE_HORDE

#include "Zombie.hpp"

class ZombieHorde
{
public:
    ZombieHorde(int size);
    ~ZombieHorde();

    void announce() const;

private:
    const int mSize;
    Zombie *mHorde;
};

#endif