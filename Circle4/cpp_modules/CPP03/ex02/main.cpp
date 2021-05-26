#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int main(void)
{
    // FragTrap alpha("alpha");
    // FragTrap beta("beta");
    // FragTrap theta(alpha);

    // beta.showStatus();
    // beta.takeDamage(alpha.meleeAttack(beta.getName()));
    // beta.showStatus();
    // beta.beRepaired(200);
    // beta.showStatus();

    // for (int i = 0; i < 3; i++)
    // {
    //     theta.takeDamage(beta.vaulthunter_dot_exe(theta.getName()));
    // }
    // theta.showStatus();
    // beta.showStatus();

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
}