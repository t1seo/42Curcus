#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
    : mCount(0)
{
    for (int i = 0; i < 4; ++i)
        mMateria[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource &matriaSource)
{
    *this = matriaSource;
}

MateriaSource::~MateriaSource()
{
    for (int i = 0; i < mCount; ++i)
    {
        delete mMateria[i];
        mMateria[i] = NULL;
    }
}

MateriaSource &MateriaSource::operator=(const MateriaSource &materiaSource)
{
    for (int i = 0; i < mCount; ++i)
    {
        delete mMateria[i];
        mMateria[i] = NULL;
    }
    mCount = 0;
    for (int i = 0; i < materiaSource.mCount; ++i)
        learnMateria(materiaSource.mMateria[i]->clone());

    return (*this);
}

void MateriaSource::learnMateria(AMateria *m)
{
    if (m && mCount < 4)
    {
        for (int i = 0; i < mCount; ++i)
        {
            if (mMateria[i] == m)
                return;
        }
        mMateria[mCount] = m;
        mCount++;
    }
}

AMateria *MateriaSource::createMateria(const std::string &type)
{
    for (int i = 0; i < mCount; ++i)
    {
        if (mMateria[i]->getType() == type)
            return (mMateria[i]->clone());
    }
    return NULL;
}
