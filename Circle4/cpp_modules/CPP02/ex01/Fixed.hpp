#ifndef FIXED
#define FIXED

#include <cmath>
#include <iostream>

class Fixed
{
public:
    Fixed();
    Fixed(const int value);
    Fixed(const float value);
    Fixed(const Fixed &value);
    ~Fixed();
    Fixed &operator=(Fixed const &value);

    int getRawBits(void) const;
    void setRawBits(int const raw);
    float toFloat(void) const;
    int toInt(void) const;

private:
    int mValue;
    static const int bits = 8;
};

std::ostream &operator<<(std::ostream &os, const Fixed &ref);

#endif