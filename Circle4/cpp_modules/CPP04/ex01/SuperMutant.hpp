#ifndef SUPERMUTANT
#define SUPERMUTANT

#include "Enemy.hpp"

class SuperMutant : public Enemy
{
public:
    SuperMutant();
    SuperMutant(const SuperMutant &superMutant);
    ~SuperMutant();

    SuperMutant &operator=(const SuperMutant &superMutant);

    void takeDamage(int damage);
};

#endif