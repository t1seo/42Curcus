#include "Fixed.hpp"

Fixed::Fixed()
    : mValue(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed &value)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = value;
}

Fixed &Fixed::operator=(Fixed const &value)
{
    std::cout << "Assignation operator called" << std::endl;
    mValue = value.getRawBits();
    return (*this);
}

int Fixed::getRawBits(void) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return (mValue);
}

void Fixed::setRawBits(int const raw)
{
    std::cout << "setRawBits member function called" << std::endl;
    mValue = raw;
}
