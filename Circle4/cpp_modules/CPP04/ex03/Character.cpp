#include "Character.hpp"

Character::Character(const std::string &name)
    : mName(name), mCount(0)
{
    for (int i = 0; i < 4; ++i)
        mInventory[i] = NULL;
}

Character::Character(const Character &character)
{
    *this = character;
}

Character::~Character()
{
    for (int i = 0; i < mCount; ++i)
    {
        delete mInventory[i];
        mInventory[i] = NULL;
    }
}

Character &Character::operator=(const Character &character)
{
    mName = character.mName;

    for (int i = 0; i < mCount; ++i)
    {
        delete mInventory[i];
        mInventory[i] = NULL;
    }

    mCount = 0;
    for (int i = 0; i < character.mCount; ++i)
    {
        equip(character.mInventory[i]->clone());
    }
    return (*this);
}

const std::string &Character::getName() const
{
    return mName;
}

void Character::equip(AMateria *m)
{
    if (m && mCount < 4)
    {
        for (int i = 0; i < mCount; ++i)
        {
            if (mInventory[i] == m)
                return;
        }

        mInventory[mCount] = m;
        mCount++;
    }
}

void Character::unequip(int idx)
{
    if (0 <= idx && idx <= mCount && mInventory[idx])
    {
        while (idx < 3)
        {
            mInventory[idx] = mInventory[idx + 1];
            idx++;
        }
        mInventory[idx] = NULL;
        mCount--;
    }
}

void Character::use(int idx, ICharacter &target)
{
    if (0 <= idx && idx <= mCount && mInventory[idx])
        mInventory[idx]->use(target);
}
