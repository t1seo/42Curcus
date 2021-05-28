#include "Cure.hpp"

Cure::Cure()
    : AMateria("cure")
{
}

Cure::Cure(const Cure &cure)
    : AMateria(cure)
{
    *this = cure;
}

Cure::~Cure()
{
}

Cure &Cure::operator=(const Cure &cure)
{
    setType(cure.getType());
    setXP(cure.getXP());
    return (*this);
}

Cure *Cure::clone() const
{
    return (new Cure(*this));
}

void Cure::use(ICharacter &target)
{
    AMateria::use(target);

    std::cout << ANSI_COLOR_GREEN
              << "* heals "
              << ANSI_COLOR_YELLOW
              << target.getName()
              << ANSI_COLOR_GREEN
              << "'s wounds *"
              << ANSI_COLOR_RESET
              << std::endl;
}
