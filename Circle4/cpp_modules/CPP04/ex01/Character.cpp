#include "Character.hpp"

Character::Character(const std::string &name)
    : mName(name), mAP(40), mWeapon(NULL)
{
}

Character::Character(const Character &character)
{
    *this = character;
}

Character::~Character()
{
}

Character &Character::operator=(const Character &character)
{
    mName = character.mName;
    mAP = character.mAP;
    mWeapon = character.mWeapon;
    return (*this);
}

std::string Character::getName() const
{
    return mName;
}

int Character::getAP() const
{
    return mAP;
}

AWeapon *Character::getWeapon() const
{
    return mWeapon;
}

void Character::recoverAP()
{
    mAP += 10;
    if (mAP > 40)
        mAP = 40;
}

void Character::equip(AWeapon *weapon)
{
    mWeapon = weapon;
}

void Character::attack(Enemy *enemy)
{
    if (mWeapon && mAP >= mWeapon->getAPCost() && enemy)
    {
        std::cout << ANSI_COLOR_YELLOW
                  << mName
                  << ANSI_COLOR_GREEN
                  << " attacks "
                  << ANSI_COLOR_YELLOW
                  << enemy->getType()
                  << ANSI_COLOR_GREEN
                  << " with a "
                  << ANSI_COLOR_YELLOW
                  << mWeapon->getName()
                  << ANSI_COLOR_RESET
                  << std::endl;

        if (enemy->getHP() <= 0)
        {
            std::cout << ANSI_COLOR_GREEN
                      << "The enemy is already dead"
                      << ANSI_COLOR_RESET
                      << std::endl;
        }
        else
        {
            mWeapon->attack();
            mAP -= mWeapon->getAPCost();
            enemy->takeDamage(mWeapon->getDamage());

            if (enemy && enemy->getHP() <= 0)
            {
                // delete enemy;
                enemy->~Enemy();
                // enemy = NULL;
            }
        }
    }
}

std::ostream &operator<<(std::ostream &os, const Character &character)
{
    if (character.getWeapon())
    {
        os << ANSI_COLOR_YELLOW
           << character.getName()
           << ANSI_COLOR_GREEN
           << " has "
           << ANSI_COLOR_YELLOW
           << character.getAP()
           << ANSI_COLOR_GREEN
           << " AP and wields a "
           << ANSI_COLOR_YELLOW
           << character.getWeapon()->getName()
           << ANSI_COLOR_RESET
           << std::endl;

        return os;
    }
    else
    {
        os << ANSI_COLOR_YELLOW
           << character.getName()
           << ANSI_COLOR_GREEN
           << " has "
           << ANSI_COLOR_YELLOW
           << character.getAP()
           << ANSI_COLOR_GREEN
           << " AP and is unarmed"
           << ANSI_COLOR_RESET
           << std::endl;

        return os;
    }
}
