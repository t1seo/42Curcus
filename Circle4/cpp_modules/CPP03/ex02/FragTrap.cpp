#include "FragTrap.hpp"

std::string FragTrap::mAttackList[5] = {"Honey Fist 👊", "Water 💧", "Ice ❄️", "Fire 🔥", "Electricity ⚡️"};
int FragTrap::mAttackEnergy[5] = {10, 20, 30, 40, 50};
int FragTrap::mAttackDamage[5] = {10, 20, 30, 40, 50};

FragTrap::FragTrap()
    : ClapTrap()
{
    srand(time(NULL));
    mType = "FR4G-TP";
    printCurrentSituation("has been created.");
}

FragTrap::FragTrap(const std::string &name)
    : ClapTrap(name)
{
    srand(time(NULL));
    mType = "FR4G-TP";
    printCurrentSituation("has been created.");
}

FragTrap::FragTrap(const FragTrap &fragTrap)
    : ClapTrap(fragTrap)
{
    srand(time(NULL));
    mType = "FR4G-TP";
    *this = fragTrap;
    printCurrentSituation("has been created.");
}

FragTrap::~FragTrap()
{
    printCurrentSituation("has been destroyed");
}

FragTrap &FragTrap::operator=(const FragTrap &fragTrap)
{
    mName = fragTrap.mName;
    mHitPoint = fragTrap.mHitPoint;
    mEnergyPoint = fragTrap.mEnergyPoint;
    mMaxHitPoint = fragTrap.mMaxEnergyPoint;
    mMaxEnergyPoint = fragTrap.mMaxEnergyPoint;
    mLevel = fragTrap.mLevel;
    mMeleeAttackDamage = fragTrap.mMeleeAttackDamage;
    mRangedAttackDamage = fragTrap.mRangedAttackDamage;
    mArmorDamageReduction = fragTrap.mArmorDamageReduction;
    return (*this);
}

unsigned int FragTrap::vaulthunter_dot_exe(std::string const &target)
{
    if (getHitPoint() > 0)
    {
        if (getEnergyPoint() > 0)
        {
            int randIdx = rand() % 5;
            std::string randAttack = mAttackList[randIdx];
            int randEnergy = mAttackEnergy[randIdx];
            int randDamage = mAttackDamage[randIdx];

            if (getEnergyPoint() - randEnergy > 0)
            {
                mEnergyPoint -= randEnergy;
                printAttackSituation(target, randAttack, randDamage);
                return randDamage;
            }
            else
            {
                printCurrentSituation("has not enough energy.");
                return 0;
            }
        }
        else
        {
            printCurrentSituation("has not enough energy.");
            return 0;
        }
    }
    else
    {
        printCurrentSituation("has already been destroyed.");
        return 0;
    }
}
