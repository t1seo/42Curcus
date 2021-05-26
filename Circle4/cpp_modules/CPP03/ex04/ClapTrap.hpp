#ifndef CLAPTRAP
#define CLAPTRAP

#include <iostream>
#include <string>

#define ANSI_COLOR_RED "\x1b[31m"
#define ANSI_COLOR_GREEN "\x1b[32m"
#define ANSI_COLOR_YELLOW "\x1b[33m"
#define ANSI_COLOR_BLUE "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN "\x1b[36m"
#define ANSI_COLOR_RESET "\x1b[0m"

class ClapTrap
{
public:
    ClapTrap();
    ClapTrap(const std::string &name);
    ClapTrap(const ClapTrap &clapTrap);
    virtual ~ClapTrap();

    ClapTrap &operator=(const ClapTrap &clapTrap);

    unsigned int rangedAttack(std::string const &target);
    unsigned int meleeAttack(std::string const &target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);

    int getHitPoint() const;
    int getEnergyPoint() const;
    std::string getName() const;
    void showStatus();

protected:
    std::string mName;
    std::string mType;

    int mHitPoint;
    int mMaxHitPoint;
    int mEnergyPoint;
    int mMaxEnergyPoint;
    int mLevel;
    int mMeleeAttackDamage;
    int mRangedAttackDamage;
    int mArmorDamageReduction;

    void printCurrentSituation(std::string status);
    void printAttackSituation(std::string target, std::string attack, int damage);
};

#endif