#ifndef AWEAPON
#define AWEAPON

#include <iostream>

#define ANSI_COLOR_RED "\x1b[31m"
#define ANSI_COLOR_GREEN "\x1b[32m"
#define ANSI_COLOR_YELLOW "\x1b[33m"
#define ANSI_COLOR_BLUE "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN "\x1b[36m"
#define ANSI_COLOR_RESET "\x1b[0m"

class AWeapon
{
public:
    AWeapon();
    AWeapon(const std::string &name, int apcost, int damage);
    AWeapon(const AWeapon &aWeapon);
    virtual ~AWeapon();

    AWeapon &operator=(const AWeapon &aWeapon);

    std::string getName() const;
    int getAPCost() const;
    int getDamage() const;
    void setName(const std::string &name);
    void setAPCost(const int apCost);
    void setDamage(const int damage);

    virtual void attack() const = 0; // pure virtual fuction

private:
    std::string mName;
    int mAPCost;
    int mDamage;
};

#endif