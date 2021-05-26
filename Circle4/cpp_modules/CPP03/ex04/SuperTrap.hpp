#ifndef SUPERTRAP
#define SUPERTRAP

#include "NinjaTrap.hpp"
#include "FragTrap.hpp"

class SuperTrap : public FragTrap, public NinjaTrap
{
public:
    SuperTrap();
    SuperTrap(const std::string &name);
    SuperTrap(const SuperTrap &superTrap);
    ~SuperTrap();

    SuperTrap &operator=(const SuperTrap &superTrap);
    unsigned int rangedAttack(const std::string &target);
    unsigned int meleeAttack(const std::string &target);
};

#endif