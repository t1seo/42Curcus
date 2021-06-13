#include "Squad.hpp"

Squad::Squad()
    : mCount(0), mUnits(NULL)
{
}

Squad::Squad(const Squad &squad)
    : mCount(0), mUnits(NULL)
{
    for (int i = 0; i < squad.getCount(); ++i)
        push(squad.getUnit(i)->clone());
}

Squad::~Squad()
{
    if (mUnits)
    {
        for (int i = 0; i < mCount; ++i)
            delete mUnits[i];
        delete[] mUnits;
    }
}

Squad &Squad::operator=(const Squad &squad)
{
    if (mUnits)
    {
        for (int i = 0; i < mCount; ++i)
            delete mUnits[i];
        delete[] mUnits;
        mUnits = nullptr;
    }
    mCount = 0;
    // deep copy
    for (int i = 0; i < squad.getCount(); ++i)
    {
        push(squad.getUnit(i)->clone());
    }
    return (*this);
}

int Squad::getCount() const
{
    return mCount;
}

ISpaceMarine *Squad::getUnit(int idx) const
{
    if (mCount > 0 && idx >= 0 && idx < mCount)
        return mUnits[idx];
    else
        return nullptr;
}

int Squad::push(ISpaceMarine *marine)
{
    if (marine)
    {
        for (int i = 0; i < mCount; ++i)
            if (mUnits[i] == marine)
                return (mCount);

        ISpaceMarine **tmp = new ISpaceMarine *[mCount + 1];
        for (int i = 0; i < mCount; ++i)
            tmp[i] = mUnits[i];
        tmp[mCount] = marine;

        delete[] mUnits;
        mUnits = tmp;
        mCount++;
    }
    return (mCount);
}
