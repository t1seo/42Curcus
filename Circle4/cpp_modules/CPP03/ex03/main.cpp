#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include "NinjaTrap.hpp"

int main(void)
{
    NinjaTrap yasuo("Yasuo");
    NinjaTrap akali("Akali");

    ClapTrap c1("Clap");
    FragTrap f1("Frag");
    ScavTrap s1("Scav");

    yasuo.takeDamage(akali.ninjaShoebox(yasuo));
    yasuo.showStatus();
    c1.takeDamage(akali.ninjaShoebox(c1));
    c1.showStatus();
    f1.takeDamage(akali.ninjaShoebox(f1));
    f1.showStatus();
    s1.takeDamage(akali.ninjaShoebox(s1));
    s1.showStatus();
}