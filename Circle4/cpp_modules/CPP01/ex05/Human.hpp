#ifndef HUMAN
#define HUMAN

#include "Brain.hpp"

class Human
{
public:
    Human();
    ~Human();
    const Brain &getBrain() const;
    std::string identify() const;

    void getThink();

private:
    const Brain mBrain;
};

#endif