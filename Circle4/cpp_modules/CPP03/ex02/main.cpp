#include "FragTrap.hpp"

int main(void)
{
    FragTrap alpha("alpha");
    FragTrap beta("beta");
    FragTrap theta(alpha);

    beta.showStatus();
    beta.takeDamage(alpha.meleeAttack(beta.getName()));
    beta.showStatus();
    beta.beRepaired(200);
    beta.showStatus();

    for (int i = 0; i < 3; i++)
    {
        theta.takeDamage(beta.vaulthunter_dot_exe(theta.getName()));
    }
    theta.showStatus();
    beta.showStatus();
}