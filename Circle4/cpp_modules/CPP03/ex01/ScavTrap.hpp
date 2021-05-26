#ifndef SCAVTRAP
#define SCAVTRAP

#include <iostream>
#include <string>

#define ANSI_COLOR_RED "\x1b[31m"
#define ANSI_COLOR_GREEN "\x1b[32m"
#define ANSI_COLOR_YELLOW "\x1b[33m"
#define ANSI_COLOR_BLUE "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN "\x1b[36m"
#define ANSI_COLOR_RESET "\x1b[0m"

class ScavTrap
{
public:
    ScavTrap(void);
    ScavTrap(const std::string &name);
    ScavTrap(const ScavTrap &scavTrap);
    ~ScavTrap();

    ScavTrap &operator=(const ScavTrap &scavTrap);

    unsigned int rangedAttack(std::string const &target);
    unsigned int meleeAttack(std::string const &target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);
    void challengeNewcomer();

    int getHitPoint() const;
    int getEnergyPoint() const;
    std::string getName() const;
    void showStatus();

private:
    std::string mName;
    int mHitPoint;
    int mMaxHitPoint;
    int mEnergyPoint;
    int mMaxEnergyPoint;
    int mLevel;
    int mMeleeAttackDamage;
    int mRangedAttackDamage;
    int mArmorDamageReduction;

    static std::string mChllangeList[5];
};

#endif