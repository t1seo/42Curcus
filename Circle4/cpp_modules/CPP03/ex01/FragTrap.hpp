#ifndef FRAGTRAP
#define FRAGTRAP

#include <iostream>

#define ANSI_COLOR_RED "\x1b[31m"
#define ANSI_COLOR_GREEN "\x1b[32m"
#define ANSI_COLOR_YELLOW "\x1b[33m"
#define ANSI_COLOR_BLUE "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN "\x1b[36m"
#define ANSI_COLOR_RESET "\x1b[0m"

class FragTrap
{
public:
    FragTrap(void);
    FragTrap(const std::string &name);
    FragTrap(const FragTrap &fragTrap);
    ~FragTrap();

    FragTrap &operator=(const FragTrap &fragTrap);

    unsigned int rangedAttack(std::string const &target);
    unsigned int meleeAttack(std::string const &target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);
    unsigned int vaulthunter_dot_exe(std::string const &target);

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

    static std::string mAttackList[5];
    static int mAttackEnergy[5];
    static int mAttackDamage[5];
};

#endif