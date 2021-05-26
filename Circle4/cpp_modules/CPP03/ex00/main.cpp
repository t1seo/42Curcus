#include "FragTrap.hpp"

int main(void)
{
    FragTrap alpha("Alpha");
    FragTrap beta("Beta");
    FragTrap theta(alpha); // copy constructor

    // ranged and melee attack
    beta.takeDamage(alpha.rangedAttack(beta.getName()));
    beta.showStatus();
    alpha.takeDamage(beta.meleeAttack(alpha.getName()));
    alpha.showStatus();

    // get repaired
    alpha.beRepaired(100);
    beta.beRepaired(100);
    alpha.showStatus();
    beta.showStatus();

    // random attack
    for (int i = 0; i < 3; i++)
    {
        theta.takeDamage(beta.vaulthunter_dot_exe(theta.getName()));
        theta.showStatus();
        beta.showStatus();
    }

    return (0);
}