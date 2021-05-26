#ifndef FIXED
#define FIXED

#include <iostream>

class Fixed
{
public:
    Fixed();
    ~Fixed();
    Fixed(const Fixed &value);
    Fixed &operator=(Fixed const &value);

    int getRawBits(void) const;
    void setRawBits(int const raw);

private:
    int mValue;
    static const int bits = 8;
};

#endif