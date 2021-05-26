#ifndef SCAVTRAP
#define SCAVTRAP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
public:
    ScavTrap(void);
    ScavTrap(const std::string &name);
    ScavTrap(const ScavTrap &scavTrap);
    ~ScavTrap();

    ScavTrap &operator=(const ScavTrap &scavTrap);
    void challengeNewcomer();

private:
    static std::string mChllangeList[5];
};

#endif