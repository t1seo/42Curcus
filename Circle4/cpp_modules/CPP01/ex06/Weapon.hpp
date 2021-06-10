#ifndef WEAPON
#define WEAPON

#include <iostream>

class Weapon
{
public:
    Weapon(const std::string &type);
    void setType(const std::string &type);
    std::string getType() const;

private:
    std::string type;
};

#endif