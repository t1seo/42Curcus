#include "ScavTrap.hpp"

std::string ScavTrap::mChllangeList[5] = {"Honey Challenge 👊", "Water Challenge 💧",
                                          "Ice Challenge ❄️", "Fire Challenge 🔥",
                                          "Electricity Challnge ⚡️"};

ScavTrap::ScavTrap(void) : ClapTrap()
{
    srand(time(NULL));
    mType = "SC4V-TP";
    mEnergyPoint = 50;
    mMaxEnergyPoint = 50;
    mRangedAttackDamage = 15;
    mArmorDamageReduction = 3;
    printCurrentSituation("has been created.");
}

ScavTrap::ScavTrap(const std::string &name) : ClapTrap(name)
{
    srand(time(NULL));
    mType = "SC4V-TP";
    mEnergyPoint = 50;
    mMaxEnergyPoint = 50;
    mRangedAttackDamage = 15;
    mArmorDamageReduction = 3;
    printCurrentSituation("has been created.");
}

ScavTrap::ScavTrap(const ScavTrap &scavTrap) : ClapTrap(scavTrap)
{
    srand(time(NULL));
    *this = scavTrap;
    mType = "SC4V-TP";
    printCurrentSituation("has been created.");
}

ScavTrap::~ScavTrap()
{
    printCurrentSituation("has been destroyed");
}

ScavTrap &ScavTrap::operator=(const ScavTrap &scavTrap)
{
    mName = scavTrap.mName;
    mHitPoint = scavTrap.mHitPoint;
    mEnergyPoint = scavTrap.mEnergyPoint;
    mMaxHitPoint = scavTrap.mMaxEnergyPoint;
    mMaxEnergyPoint = scavTrap.mMaxEnergyPoint;
    mLevel = scavTrap.mLevel;
    mMeleeAttackDamage = scavTrap.mMeleeAttackDamage;
    mRangedAttackDamage = scavTrap.mRangedAttackDamage;
    mArmorDamageReduction = scavTrap.mArmorDamageReduction;
    return (*this);
}

void ScavTrap::challengeNewcomer()
{
    int randIdx = rand() % 5;

    std::cout << ANSI_COLOR_GREEN
              << "The SC4V-TP "
              << ANSI_COLOR_YELLOW
              << mName
              << ANSI_COLOR_GREEN
              << " challenges "
              << ANSI_COLOR_YELLOW
              << mChllangeList[randIdx]
              << ANSI_COLOR_RESET
              << std::endl;
}
