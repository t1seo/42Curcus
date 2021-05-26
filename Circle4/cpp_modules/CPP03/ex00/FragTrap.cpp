#include "FragTrap.hpp"

std::string FragTrap::mAttackList[5] = {"Honey Fist 👊", "Water 💧", "Ice ❄️", "Fire 🔥", "Electricity ⚡️"};
int FragTrap::mAttackEnergy[5] = {10, 20, 30, 40, 50};
int FragTrap::mAttackDamage[5] = {10, 20, 30, 40, 50};

static void printCurrentSituation(std::string name, std::string status)
{
    std::cout << ANSI_COLOR_GREEN
              << "The FR4G-TP "
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
              << "The FR4G-TP "
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

// constructor
FragTrap::FragTrap(void) : mName("No name"),
                           mHitPoint(100), mMaxHitPoint(100),
                           mEnergyPoint(100), mMaxEnergyPoint(100), mLevel(1),
                           mMeleeAttackDamage(30), mRangedAttackDamage(20), mArmorDamageReduction(5)
{
    srand(time(NULL));
    printCurrentSituation(mName, " has been created.");
}

// constructor
FragTrap::FragTrap(const std::string &name) : mName(name), mHitPoint(100), mMaxHitPoint(100),
                                              mEnergyPoint(100), mMaxEnergyPoint(100), mLevel(1),
                                              mMeleeAttackDamage(30), mRangedAttackDamage(20), mArmorDamageReduction(5)
{
    srand(time(NULL));
    printCurrentSituation(mName, " has been created.");
}

// copy constructor
FragTrap::FragTrap(const FragTrap &fragTrap)
{
    srand(time(NULL));
    *this = fragTrap;
    printCurrentSituation(mName, " has been copied.");
}

// destructor
FragTrap::~FragTrap()
{
    printCurrentSituation(mName, " has been destroyed.");
}

// assignation operator overloading
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
    std::cout << ANSI_COLOR_RED << "ASSIGNMENT" << ANSI_COLOR_RESET << std::endl;
    return (*this);
}

unsigned int FragTrap::rangedAttack(std::string const &target)
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

unsigned int FragTrap::meleeAttack(std::string const &target)
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

void FragTrap::takeDamage(unsigned int amount)
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
            printCurrentSituation(mName, "has been destroyed.");
        }
    }
    else
    {
        printCurrentSituation(mName, " has already been destroyed.");
    }
}

void FragTrap::beRepaired(unsigned int amount)
{
    mHitPoint += amount;
    mEnergyPoint += amount;
    if (mHitPoint > mMaxHitPoint)
        mHitPoint = mMaxHitPoint;
    if (mEnergyPoint > mMaxEnergyPoint)
        mEnergyPoint = mMaxEnergyPoint;

    printCurrentSituation(mName, " has been repaired.");
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
                printAttackSituation(mName, target, randAttack, randDamage);
                return randDamage;
            }
            else
            {
                printCurrentSituation(mName, " has not enough energy.");
                return 0;
            }
        }
        else
        {
            printCurrentSituation(mName, " has not enough energy.");
            return 0;
        }
    }
    else
    {
        printCurrentSituation(mName, " has already been destroyed.");
        return 0;
    }
}

int FragTrap::getHitPoint() const
{
    return (mHitPoint);
}

int FragTrap::getEnergyPoint() const
{
    return (mEnergyPoint);
}

std::string FragTrap::getName() const
{
    return (mName);
}

void FragTrap::showStatus()
{
    std::cout << ANSI_COLOR_BLUE
              << "-----------------" << std::endl
              << "Name: " << mName << std::endl
              << "HP: " << mHitPoint << std::endl
              << "EP: " << mEnergyPoint << std::endl
              << "-----------------"
              << ANSI_COLOR_RESET << std::endl;
}
