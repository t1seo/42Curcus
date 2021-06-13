#ifndef MATRIASOURCE
#define MATRIASOURCE

#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
public:
    MateriaSource();
    MateriaSource(const MateriaSource &matriaSource);
    virtual ~MateriaSource();
    MateriaSource &operator=(const MateriaSource &materiaSource);

    virtual void learnMateria(AMateria *m);
    virtual AMateria *createMateria(const std::string &type);

private:
    int mCount;
    AMateria *mMateria[4];
};

#endif