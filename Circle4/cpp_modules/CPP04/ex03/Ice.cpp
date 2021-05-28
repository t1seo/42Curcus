#include "Ice.hpp"

Ice::Ice()
    : AMateria("ice")
{
}

Ice::Ice(const Ice &ice)
    : AMateria(ice)
{
    *this = ice;
}

Ice::~Ice()
{
}

Ice &Ice::operator=(const Ice &ice)
{
    setType(ice.getType());
    setXP(ice.getXP());
    return (*this);
}

Ice *Ice::clone() const
{
    return (new Ice(*this));
}

void Ice::use(ICharacter &target)
{
    AMateria::use(target);
    std::cout << ANSI_COLOR_GREEN
              << "* shoots an ice bolt at "
              << ANSI_COLOR_YELLOW
              << target.getName()
              << ANSI_COLOR_GREEN
              << " *"
              << std::endl;
}
