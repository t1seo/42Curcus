#include "ClapTrap.hpp"

void ClapTrap::printCurrentSituation(std::string status)
{
    std::cout << ANSI_COLOR_GREEN
              << "The "
              << mType
              << " "
              << ANSI_COLOR_YELLOW
              << mName
              << " "
              << ANSI_COLOR_GREEN
              << status
              << ANSI_COLOR_RESET
              << std::endl;
}

void ClapTrap::printAttackSituation(std::string target, std::string attack, int damage)
{
    std::cout << ANSI_COLOR_GREEN
              << "The "
              << mType
              << " "
              << ANSI_COLOR_YELLOW
              << mName
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

ClapTrap::ClapTrap() : mName("No name"),
                       mHitPoint(100), mMaxHitPoint(100),
                       mEnergyPoint(100), mMaxEnergyPoint(100), mLevel(1),
                       mMeleeAttackDamage(30), mRangedAttackDamage(20), mArmorDamageReduction(5),
                       mType("Claptrap")
{
    srand(time(NULL));
    printCurrentSituation("is ready!");
}

ClapTrap::ClapTrap(const std::string &name) : mName(name),
                                              mHitPoint(100), mMaxHitPoint(100),
                                              mEnergyPoint(100), mMaxEnergyPoint(100), mLevel(1),
                                              mMeleeAttackDamage(30), mRangedAttackDamage(20), mArmorDamageReduction(5),
                                              mType("Claptrap")
{
    srand(time(NULL));
    printCurrentSituation("is ready!");
}

ClapTrap::ClapTrap(const ClapTrap &clapTrap)
{
    srand(time(NULL));
    *this = clapTrap;
    std::cout << ANSI_COLOR_GREEN << "The Claptrap "
              << ANSI_COLOR_YELLOW << mName
              << ANSI_COLOR_GREEN << " has been copied!"
              << ANSI_COLOR_RESET << std::endl;
}

ClapTrap::~ClapTrap()
{
    std::cout << ANSI_COLOR_GREEN << "The Claptrap "
              << ANSI_COLOR_YELLOW << mName
              << ANSI_COLOR_GREEN << " says goodbye!"
              << ANSI_COLOR_RESET << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &clapTrap)
{
    mName = clapTrap.mName;
    mType = clapTrap.mType;
    mHitPoint = clapTrap.mHitPoint;
    mEnergyPoint = clapTrap.mEnergyPoint;
    mMaxHitPoint = clapTrap.mMaxEnergyPoint;
    mMaxEnergyPoint = clapTrap.mMaxEnergyPoint;
    mLevel = clapTrap.mLevel;
    mMeleeAttackDamage = clapTrap.mMeleeAttackDamage;
    mRangedAttackDamage = clapTrap.mRangedAttackDamage;
    mArmorDamageReduction = clapTrap.mArmorDamageReduction;
    return (*this);
}

unsigned int ClapTrap::rangedAttack(std::string const &target)
{
    if (getHitPoint() > 0)
    {
        printAttackSituation(target, "range", mRangedAttackDamage);
        return mRangedAttackDamage;
    }
    else
    {
        printCurrentSituation("has already been destroyed.");
        return 0;
    }
}

unsigned int ClapTrap::meleeAttack(std::string const &target)
{
    if (getHitPoint() > 0)
    {
        printAttackSituation(target, "melee", mMeleeAttackDamage);
        return mMeleeAttackDamage;
    }
    else
    {
        printCurrentSituation("has already been destroyed.");
        return 0;
    }
}

void ClapTrap::takeDamage(unsigned int amount)
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
            printCurrentSituation("has been destroyed.");
        }
    }
    else
    {
        printCurrentSituation("has already been destroyed.");
    }
}

void ClapTrap::beRepaired(unsigned int amount)
{
    mHitPoint += amount;
    mEnergyPoint += amount;
    if (mHitPoint > mMaxHitPoint)
        mHitPoint = mMaxHitPoint;
    if (mEnergyPoint > mMaxEnergyPoint)
        mEnergyPoint = mMaxEnergyPoint;

    printCurrentSituation(" has been repaired.");
}

int ClapTrap::getHitPoint() const
{
    return (mHitPoint);
}

int ClapTrap::getEnergyPoint() const
{
    return (mEnergyPoint);
}

std::string ClapTrap::getName() const
{
    return (mName);
}

void ClapTrap::showStatus()
{
    std::cout << ANSI_COLOR_BLUE
              << "-----" << mType << "-----" << std::endl
              << "Name: " << mName << std::endl
              << "HP: " << mHitPoint << std::endl
              << "EP: " << mEnergyPoint << std::endl
              << "-----------------"
              << ANSI_COLOR_RESET << std::endl;
}
