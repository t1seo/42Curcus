#include "Sorcerer.hpp"
#include "Peasant.hpp"
#include "Peon.hpp"

int main(void)
{
    Sorcerer robert("Robert", "the Magnificent");

    Victim jim("Jimmy");
    Peon joe("Joe");

    std::cout << robert << jim << joe;

    robert.polymorph(jim); // Victim
    robert.polymorph(joe); // Peon

    // Peasant jack("Jack");
    // robert.polymorph(jack);

    return 0;
}
