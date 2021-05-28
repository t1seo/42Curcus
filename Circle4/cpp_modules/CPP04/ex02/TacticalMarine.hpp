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

    TacticalMarine *clone() const;
    void battleCry() const;
    void rangedAttack() const;
    void meleeAttack() const;
};

#endif