#include "Character.hpp"
#include "PlasmaRifle.hpp"
#include "PowerFist.hpp"
#include "RadScorpion.hpp"
#include "SuperMutant.hpp"

int main()
{
    Character *buzz = new Character("Buzz Lightyear");

    std::cout << *buzz;

    Enemy *enemy = new SuperMutant();
    // Enemy *enemy = new RadScorpion();
    enemy->setType("Emperor Zurg");

    AWeapon *pr = new PlasmaRifle();
    AWeapon *pf = new PowerFist();

    buzz->equip(pr);
    std::cout << *buzz;
    buzz->equip(pf);

    buzz->attack(enemy);
    std::cout << *buzz;
    buzz->equip(pr);
    std::cout << *buzz;
    buzz->attack(enemy);
    std::cout << *buzz;
    buzz->attack(enemy);
    std::cout << *buzz;
    // buzz->attack(enemy);
    // std::cout << *buzz;
    // buzz->attack(enemy);
    // std::cout << *buzz;
    // buzz->attack(enemy);
    // std::cout << *buzz;
    // buzz->attack(enemy);
    // std::cout << *buzz;
    // buzz->attack(enemy);
    // std::cout << *buzz;
    // buzz->attack(enemy);
    // std::cout << *buzz;
    // buzz->attack(enemy);
    // std::cout << *buzz;
    // buzz->attack(enemy);
    // std::cout << *buzz;
    buzz->recoverAP();
    buzz->attack(enemy);
    std::cout << *buzz;
    buzz->attack(enemy);
    std::cout << *buzz;
    buzz->recoverAP();
    buzz->attack(enemy);
    std::cout << *buzz;
    buzz->recoverAP();
    buzz->attack(enemy);
    std::cout << *buzz;
    buzz->recoverAP();
    buzz->attack(enemy);
    std::cout << *buzz;
    buzz->recoverAP();
    buzz->attack(enemy); // enemy alread dead
    std::cout << *buzz;

    delete buzz;
    delete enemy;
    delete pr;
    delete pf;

    return 0;
}