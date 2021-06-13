#ifndef TACTICALMARINE
#define TACTICALMARINE

#include <iostream>
#include "ISpaceMarine.hpp"

class TacticalMarine : public ISpaceMarine
{
public:
    TacticalMarine();
    TacticalMarine(const TacticalMarine &tacticalMarine);
    virtual ~TacticalMarine();
    TacticalMarine &operator=(const TacticalMarine &tacticalMarine);

    virtual TacticalMarine *clone() const;
    virtual void battleCry() const;
    virtual void rangedAttack() const;
    virtual void meleeAttack() const;
};

#endif