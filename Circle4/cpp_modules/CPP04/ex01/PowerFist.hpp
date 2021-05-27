#ifndef POWERFIST
#define POWERFIST

#include "AWeapon.hpp"

class PowerFist : public AWeapon
{
public:
    PowerFist();
    PowerFist(const PowerFist &powerFist);
    virtual ~PowerFist();

    PowerFist &operator=(const PowerFist &powerFist);

    void attack() const;
};

#endif