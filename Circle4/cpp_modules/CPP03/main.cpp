#include "FragTrap.hpp"

int main(void)
{
    FragTrap alpha("Alpha");
    FragTrap beta("Beta");
    FragTrap alphaCopy(alpha); // copy constructor
    FragTrap theta;

    theta.showStatus();
    theta.takeDamage(10);
    theta = alpha; // assignment
    theta.showStatus();

    return (0);
}