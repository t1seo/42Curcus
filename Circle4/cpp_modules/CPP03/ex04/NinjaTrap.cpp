#include "NinjaTrap.hpp"

NinjaTrap::NinjaTrap() : ClapTrap()
{
    srand(time(NULL));
    mHitPoint = 60;
    mMaxHitPoint = 60;
    mEnergyPoint = 120;
    mMaxEnergyPoint = 120;
    mMeleeAttackDamage = 60;
    mRangedAttackDamage = 5;
    mArmorDamageReduction = 0;
    mType = "Ninja-TP";
    printCurrentSituation("has been created.");
}

NinjaTrap::NinjaTrap(std::string name) : ClapTrap(name)
{
    srand(time(NULL));
    mHitPoint = 60;
    mMaxHitPoint = 60;
    mEnergyPoint = 120;
    mMaxEnergyPoint = 120;
    mMeleeAttackDamage = 60;
    mRangedAttackDamage = 5;
    mArmorDamageReduction = 0;
    mType = "Ninja-TP";
    printCurrentSituation("has been created.");
}

NinjaTrap::NinjaTrap(const NinjaTrap &NinjaTrap) : ClapTrap(NinjaTrap)
{
    srand(time(NULL));
    mType = "Ninja-TP";
    *this = NinjaTrap;
    printCurrentSituation("has been created.");
}

NinjaTrap::~NinjaTrap()
{
    std::cout << ANSI_COLOR_GREEN << "The Ninja-Tp "
              << ANSI_COLOR_YELLOW << mName
              << ANSI_COLOR_GREEN << " has been destroyed!"
              << ANSI_COLOR_RESET << std::endl;
}

NinjaTrap &NinjaTrap::operator=(const NinjaTrap &NinjaTrap)
{
    mName = NinjaTrap.mName;
    mHitPoint = NinjaTrap.mHitPoint;
    mEnergyPoint = NinjaTrap.mEnergyPoint;
    mMaxHitPoint = NinjaTrap.mMaxEnergyPoint;
    mMaxEnergyPoint = NinjaTrap.mMaxEnergyPoint;
    mLevel = NinjaTrap.mLevel;
    mMeleeAttackDamage = NinjaTrap.mMeleeAttackDamage;
    mRangedAttackDamage = NinjaTrap.mRangedAttackDamage;
    mArmorDamageReduction = NinjaTrap.mArmorDamageReduction;
    return (*this);
}

unsigned int NinjaTrap::ninjaShoebox(const FragTrap &FragTrap)
{
    if (getHitPoint() > 0)
    {
        printAttackSituation(FragTrap.getName(), "Nike", 10);
        return 10;
    }
    else
    {
        printCurrentSituation("has already been destroyed.");
        return 0;
    }
}

unsigned int NinjaTrap::ninjaShoebox(const ScavTrap &ScavTrap)
{
    if (getHitPoint() > 0)
    {
        printAttackSituation(ScavTrap.getName(), "Adidas", 10);
        return 10;
    }
    else
    {
        printCurrentSituation("has already been destroyed.");
        return 0;
    }
}

unsigned int NinjaTrap::ninjaShoebox(const NinjaTrap &NinjaTrap)
{
    if (getHitPoint() > 0)
    {
        printAttackSituation(NinjaTrap.getName(), "New Balance", 10);
        return 10;
    }
    else
    {
        printCurrentSituation("has already been destroyed.");
        return 0;
    }
}

unsigned int NinjaTrap::ninjaShoebox(const ClapTrap &ClapTrap)
{
    if (getHitPoint() > 0)
    {
        printAttackSituation(ClapTrap.getName(), "Asics", 10);
        return 10;
    }
    else
    {
        printCurrentSituation("has already been destroyed.");
        return 0;
    }
}
