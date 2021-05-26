#include "SuperTrap.hpp"

SuperTrap::SuperTrap()
    : ClapTrap(), FragTrap(), NinjaTrap()
{
    srand(time(NULL));
    mHitPoint = 100;
    mMaxHitPoint = 100;
    mEnergyPoint = 120;
    mMaxEnergyPoint = 120;
    mMeleeAttackDamage = 60;
    mRangedAttackDamage = 20;
    mArmorDamageReduction = 5;
    mType = "Super-TP";
    printCurrentSituation("has been created.");
}

SuperTrap::SuperTrap(const std::string &name)
    : ClapTrap(name), FragTrap(name), NinjaTrap(name)
{
    srand(time(NULL));
    mHitPoint = 100;
    mMaxHitPoint = 100;
    mEnergyPoint = 120;
    mMaxEnergyPoint = 120;
    mMeleeAttackDamage = 60;
    mRangedAttackDamage = 20;
    mArmorDamageReduction = 5;
    mType = "Super-TP";
    printCurrentSituation("has been created.");
}

SuperTrap::SuperTrap(const SuperTrap &superTrap)
    : ClapTrap(superTrap), FragTrap(superTrap), NinjaTrap(superTrap)
{
    srand(time(NULL));
    mType = "Super-TP";
    *this = superTrap;
    printCurrentSituation("has been created.");
}

SuperTrap::~SuperTrap()
{
    printCurrentSituation("has been destroyed");
}

SuperTrap &SuperTrap::operator=(const SuperTrap &superTrap)
{
    mName = superTrap.mName;
    mHitPoint = superTrap.mHitPoint;
    mEnergyPoint = superTrap.mEnergyPoint;
    mMaxHitPoint = superTrap.mMaxEnergyPoint;
    mMaxEnergyPoint = superTrap.mMaxEnergyPoint;
    mLevel = superTrap.mLevel;
    mMeleeAttackDamage = superTrap.mMeleeAttackDamage;
    mRangedAttackDamage = superTrap.mRangedAttackDamage;
    mArmorDamageReduction = superTrap.mArmorDamageReduction;
    return (*this);
}

unsigned int SuperTrap::rangedAttack(const std::string &target)
{
    return FragTrap::rangedAttack(target);
}

unsigned int SuperTrap::meleeAttack(const std::string &target)
{
    return NinjaTrap::meleeAttack(target);
}
