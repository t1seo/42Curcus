#ifndef FRAGTRAP
#define FRAGTRAP

#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
public:
    FragTrap();
    FragTrap(const std::string &name);
    FragTrap(const FragTrap &fragTrap);
    ~FragTrap();
    FragTrap &operator=(const FragTrap &fragTrap);

    unsigned int vaulthunter_dot_exe(std::string const &target);

private:
    static std::string mAttackList[5];
    static int mAttackEnergy[5];
    static int mAttackDamage[5];
};

#endif