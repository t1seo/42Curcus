#include "SuperTrap.hpp"

int main(void)
{
    SuperTrap s1("Alpha");
    SuperTrap s2("Beta");
    FragTrap b1("Frag");

    s2.takeDamage(s1.meleeAttack(s2.getName()));
    s2.showStatus();
    s2.beRepaired(100);
    s2.showStatus();

    s2.takeDamage(s1.vaulthunter_dot_exe(s2.getName()));
    s2.showStatus();
    s2.beRepaired(100);

    s2.takeDamage(s1.ninjaShoebox(b1));
    b1.showStatus();
    return 0;
}