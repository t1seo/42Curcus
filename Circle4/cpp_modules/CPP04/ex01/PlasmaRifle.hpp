#ifndef PLASMARIFLE
#define PLASMARIFLE

#include "AWeapon.hpp"

class PlasmaRifle : public AWeapon
{
public:
    PlasmaRifle();
    PlasmaRifle(const PlasmaRifle &plasmaRifle);
    virtual ~PlasmaRifle();

    PlasmaRifle &operator=(const PlasmaRifle &plasmaRifle);

    void attack() const;
};

#endif