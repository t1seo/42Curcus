#ifndef HUMANA
#define HUMANA

#include "Weapon.hpp"

class HumanA
{
public:
    HumanA(const std::string &name, const Weapon &weapon);
    void attack() const;

private:
    const std::string name;
    const Weapon &weapon;
};

#endif