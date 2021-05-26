#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int main(void)
{
    ScavTrap alpha("alpha");
    ScavTrap beta("beta");

    beta.takeDamage(alpha.meleeAttack(beta.getName()));
    beta.showStatus();
    beta.takeDamage(alpha.rangedAttack(beta.getName()));
    beta.showStatus();

    beta.beRepaired(100);
    beta.showStatus();

    // challenge
    for (int i = 0; i < 3; i++)
    {
        alpha.challengeNewcomer();
    }

    return (0);
}