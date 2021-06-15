#include "Ice.hpp"
#include "Cure.hpp"
#include "MateriaSource.hpp"
#include "Character.hpp"

int main(void)
{
    IMateriaSource *src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());

    ICharacter *me = new Character("me");

    AMateria *tmp;
    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);

    ICharacter *bob = new Character("bob");
    // ICharacter *bob2(me);

    me->use(0, *bob);
    me->use(1, *bob);

    delete bob;
    delete me;
    delete src;

    // test
    // IMateriaSource *src2 = new MateriaSource();
    // src2->learnMateria(new Ice());
    // src2->learnMateria(new Ice()); // create only one

    // ICharacter *me2 = new Character("me2");

    // AMateria *tmp2;
    // tmp2 = src2->createMateria("ice");
    // me2->equip(tmp2);
    // tmp2 = src2->createMateria("ice2");
    // me2->equip(tmp2);

    // ICharacter *bob2 = new Character("bob2");

    // me2->use(0, *bob2);
    // me2->use(1, *bob2);

    // delete bob2;
    // delete me2;
    // delete src2;

    return (0);
}