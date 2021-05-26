#include "ScavTrap.hpp"

std::string ScavTrap::mChllangeList[5] = {"Honey Challenge 👊", "Water Challenge 💧",
                                          "Ice Challenge ❄️", "Fire Challenge 🔥",
                                          "Electricity Challnge ⚡️"};

static void printCurrentSituation(std::string name, std::string status)
{
    std::cout << ANSI_COLOR_GREEN
              << "The SC4V-TP "
              << ANSI_COLOR_YELLOW
              << name
              << ANSI_COLOR_GREEN
              << status
              << ANSI_COLOR_RESET
              << std::endl;
}

static void printAttackSituation(std::string name, std::string target, std::string attack, int damage)
{
    std::cout << ANSI_COLOR_GREEN
              << "The SC4V-TP "
              << ANSI_COLOR_YELLOW
              << name
              << ANSI_COLOR_GREEN
              << " attacks "
              << ANSI_COLOR_YELLOW
              << target
              << ANSI_COLOR_GREEN
              << " at"
              << ANSI_COLOR_YELLOW
              << " "
              << attack
              << ANSI_COLOR_GREEN
              << ", causing "
              << ANSI_COLOR_YELLOW
              << damage
              << ANSI_COLOR_GREEN
              << " points of damage!"
              << ANSI_COLOR_RESET
              << std::endl;
}
ScavTrap::ScavTrap(void) : mName("No name"),
                           mHitPoint(100), mMaxHitPoint(100),
                           mEnergyPoint(50), mMaxEnergyPoint(50), mLevel(1),
                           mMeleeAttackDamage(20), mRangedAttackDamage(15), mArmorDamageReduction(3)
{
    srand(time(NULL));
    printCurrentSituation(mName, " has created.");
}

ScavTrap::ScavTrap(const std::string &name) : mName(name),
                                              mHitPoint(100), mMaxHitPoint(100),
                                              mEnergyPoint(50), mMaxEnergyPoint(50), mLevel(1),
                                              mMeleeAttackDamage(20), mRangedAttackDamage(15), mArmorDamageReduction(3)
{
    srand(time(NULL));
    printCurrentSituation(mName, " has created.");
}

ScavTrap::ScavTrap(const ScavTrap &scavTrap)
{
    srand(time(NULL));
    *this = scavTrap;
    printCurrentSituation(mName, " has copied.");
}

ScavTrap::~ScavTrap()
{
    printCurrentSituation(mName, " has destroyed.");
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

unsigned int ScavTrap::rangedAttack(std::string const &target)
{
    if (getHitPoint() > 0)
    {
        printAttackSituation(mName, target, "range", mRangedAttackDamage);
        return mRangedAttackDamage;
    }
    else
    {
        printCurrentSituation(mName, "has already been destroyed.");
        return 0;
    }
}

unsigned int ScavTrap::meleeAttack(std::string const &target)
{
    if (getHitPoint() > 0)
    {
        printAttackSituation(mName, target, "melee", mMeleeAttackDamage);
        return mMeleeAttackDamage;
    }
    else
    {
        printCurrentSituation(mName, "has already been destroyed.");
        return 0;
    }
}

void ScavTrap::takeDamage(unsigned int amount)
{
    if (getHitPoint() > 0)
    {
        int damage = amount - mArmorDamageReduction;
        if (damage < 0)
            damage = 0;
        mHitPoint -= damage;
        if (mHitPoint > 0)
        {
            std::cout << ANSI_COLOR_YELLOW
                      << mName
                      << ANSI_COLOR_GREEN
                      << " takes "
                      << ANSI_COLOR_YELLOW
                      << damage
                      << ANSI_COLOR_GREEN
                      << " damage."
                      << ANSI_COLOR_RESET
                      << std::endl;
        }
        else
        {
            mHitPoint = 0;
            printCurrentSituation(mName, "has destroyed.");
        }
    }
    else
    {
        printCurrentSituation(mName, " has already been destroyed.");
    }
}

void ScavTrap::beRepaired(unsigned int amount)
{
    mHitPoint += amount;
    mEnergyPoint += amount;
    if (mHitPoint > mMaxHitPoint)
        mHitPoint = mMaxHitPoint;
    if (mEnergyPoint > mMaxEnergyPoint)
        mEnergyPoint = mMaxEnergyPoint;

    printCurrentSituation(mName, " has been repaired.");
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

int ScavTrap::getHitPoint() const
{
    return (mHitPoint);
}

int ScavTrap::getEnergyPoint() const
{
    return (mEnergyPoint);
}

std::string ScavTrap::getName() const
{
    return (mName);
}

void ScavTrap::showStatus()
{
    std::cout << ANSI_COLOR_BLUE
              << "-----SC4V-TP-----" << std::endl
              << "Name: " << mName << std::endl
              << "HP: " << mHitPoint << std::endl
              << "EP: " << mEnergyPoint << std::endl
              << "-----------------"
              << ANSI_COLOR_RESET << std::endl;
}
