#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int main(void)
{
    ScavTrap alpha("alpha");
    ScavTrap beta("beta");

    FragTrap frag1("Frag-1");
    FragTrap frag2("Frag-2");

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

    // random attack(vaulthuner_dot_exe)
    for (int i = 0; i < 3; i++)
    {
        frag2.takeDamage(frag1.vaulthunter_dot_exe(frag2.getName()));
        frag1.showStatus();
        frag2.showStatus();
    }
    return (0);
}