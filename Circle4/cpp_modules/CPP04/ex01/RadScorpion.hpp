#ifndef RADSCORPION
#define RADSCORPION

#include "Enemy.hpp"

class RadScorpion : public Enemy
{
public:
    RadScorpion();
    RadScorpion(const RadScorpion &radScorpion);
    virtual ~RadScorpion();

    RadScorpion &operator=(const RadScorpion &radScorpion);

    void takeDamage(int damage);
};

#endif