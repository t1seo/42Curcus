#ifndef NINJATRAP
#define NINJATRAP

#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class NinjaTrap : virtual public ClapTrap
{
public:
    NinjaTrap();
    NinjaTrap(std::string name);
    NinjaTrap(const NinjaTrap &NinjaTrap);
    ~NinjaTrap();
    NinjaTrap &operator=(const NinjaTrap &NinjaTrap);

    unsigned int ninjaShoebox(const FragTrap &FragTrap);
    unsigned int ninjaShoebox(const ScavTrap &ScavTrap);
    unsigned int ninjaShoebox(const NinjaTrap &NinjaTrap);
    unsigned int ninjaShoebox(const ClapTrap &ClapTrap);
};

#endif