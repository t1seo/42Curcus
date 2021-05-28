#ifndef AMATERIA
#define AMATERIA

#include <iostream>
#include "ICharacter.hpp"

class ICharacter;

class AMateria
{
public:
    AMateria();
    AMateria(const std::string &type);
    AMateria(const AMateria &amateria);
    virtual ~AMateria();
    AMateria &operator=(const AMateria &amateria);

    const std::string &getType() const;
    unsigned int getXP() const;
    void setType(const std::string &type);
    void setXP(const int xp);

    virtual AMateria *clone() const = 0; // pure virtual function
    virtual void use(ICharacter &target);

private:
    std::string mType;
    unsigned int mXP;
};

#endif