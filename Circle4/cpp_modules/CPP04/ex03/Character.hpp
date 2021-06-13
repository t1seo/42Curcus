#ifndef CHARACTER
#define CHARACTER

#include "ICharacter.hpp"

class Character : public ICharacter
{
public:
    Character(const std::string &name);
    Character(const Character &character);
    virtual ~Character();
    Character &operator=(const Character &character);

    virtual const std::string &getName() const;
    virtual void equip(AMateria *m);
    virtual void unequip(int idx);
    virtual void use(int idx, ICharacter &target);

private:
    Character();
    std::string mName;
    int mCount;
    AMateria *mInventory[4];
};

#endif