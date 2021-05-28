#ifndef ASSAULTTERMINATOR
#define ASSAULTTERMINATOR

#include <iostream>
#include "ISpaceMarine.hpp"

class AssaultTerminator : public ISpaceMarine
{
public:
    AssaultTerminator();
    AssaultTerminator(const AssaultTerminator &assaultTerminator);
    virtual ~AssaultTerminator();
    AssaultTerminator &operator=(const AssaultTerminator &assaultTerminator);

    ISpaceMarine *clone() const;
    void battleCry() const;
    void rangedAttack() const;
    void meleeAttack() const;
};

#endif