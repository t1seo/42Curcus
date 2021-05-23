#ifndef HUMANB
#define HUMANB

#include "Weapon.hpp"

class HumanB
{
public:
    HumanB(const std::string &name);
    void setWeapon(const Weapon &weapon);
    void attack() const;

private:
    const std::string name;
    const Weapon *weapon;
};

#endif