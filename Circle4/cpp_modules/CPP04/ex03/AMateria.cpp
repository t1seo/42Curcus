#include "AMateria.hpp"

AMateria::AMateria()
    : mType("No Type"), mXP(0)
{
}

AMateria::AMateria(const std::string &type)
    : mType(type), mXP(0)
{
}

AMateria::AMateria(const AMateria &amateria)
{
    *this = amateria;
}

AMateria::~AMateria()
{
}

AMateria &AMateria::operator=(const AMateria &amateria)
{
    mType = amateria.mType;
    mXP = amateria.mXP;
    return (*this);
}

const std::string &AMateria::getType() const
{
    return mType;
}

unsigned int AMateria::getXP() const
{
    return mXP;
}

void AMateria::setType(const std::string &type)
{
    mType = type;
}

void AMateria::setXP(const int xp)
{
    mXP = xp;
}

void AMateria::use(ICharacter &target)
{
    (void)target;
    mXP += 10;
}
