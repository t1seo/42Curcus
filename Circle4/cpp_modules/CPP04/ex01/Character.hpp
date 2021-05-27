#ifndef CHARACTER
#define CHARACTER

#include "AWeapon.hpp"
#include "Enemy.hpp"

#define ANSI_COLOR_RED "\x1b[31m"
#define ANSI_COLOR_GREEN "\x1b[32m"
#define ANSI_COLOR_YELLOW "\x1b[33m"
#define ANSI_COLOR_BLUE "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN "\x1b[36m"
#define ANSI_COLOR_RESET "\x1b[0m"

class Character
{
public:
    Character();
    Character(const std::string &name);
    Character(const Character &character);
    ~Character();

    Character &operator=(const Character &character);

    std::string getName() const;
    int getAP() const;
    AWeapon *getWeapon() const;

    void recoverAP();
    void equip(AWeapon *weapon);
    void attack(Enemy *enemy);

private:
    std::string mName;
    int mAP;
    AWeapon *mWeapon;
};

std::ostream &operator<<(std::ostream &os, const Character &character);

#endif