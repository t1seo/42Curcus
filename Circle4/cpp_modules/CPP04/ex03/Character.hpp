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

    const std::string &getName() const;
    void equip(AMateria *m);
    void unequip(int idx);
    void use(int idx, ICharacter &target);

private:
    Character();
    std::string mName;
    int mCount;
    AMateria *mInventory[4];
};

#endif