#include "Character.hpp"
#include "PlasmaRifle.hpp"
#include "PowerFist.hpp"
#include "RadScorpion.hpp"
#include "SuperMutant.hpp"

int main()
{
    Character *buzz = new Character("Buzz Lightyear");

    std::cout << *buzz;

    Enemy *b = new SuperMutant();
    b->setType("Emperor Zurg");

    AWeapon *pr = new PlasmaRifle();
    AWeapon *pf = new PowerFist();

    buzz->equip(pr);
    std::cout << *buzz;
    buzz->equip(pf);

    buzz->attack(b);
    std::cout << *buzz;
    buzz->equip(pr);
    std::cout << *buzz;
    buzz->attack(b);
    std::cout << *buzz;
    buzz->attack(b);
    std::cout << *buzz;
    buzz->recoverAP();
    buzz->attack(b);
    std::cout << *buzz;
    buzz->attack(b);
    std::cout << *buzz;
    buzz->recoverAP();
    buzz->attack(b);
    std::cout << *buzz;
    buzz->recoverAP();
    buzz->attack(b);
    std::cout << *buzz;
    buzz->recoverAP();
    buzz->attack(b);
    std::cout << *buzz;
    buzz->recoverAP();
    buzz->attack(b);
    std::cout << *buzz;

    delete buzz;
    delete b;
    delete pr;
    delete pf;

    return 0;
}