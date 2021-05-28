#ifndef SQUAD
#define SQUAD

#include <iostream>
#include "ISquad.hpp"

class Squad : public ISquad
{
public:
    Squad();
    Squad(const Squad &squad);
    virtual ~Squad();
    Squad &operator=(const Squad &squad);

    int getCount() const;
    ISpaceMarine *getUnit(int idx) const;
    int push(ISpaceMarine *marine);

private:
    int mCount;
    ISpaceMarine **mUnits;
};

#endif