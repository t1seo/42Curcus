#ifndef BRAIN
#define BRAIN

#include <iostream>
#include <sstream>

class Brain
{
public:
    Brain();
    ~Brain();
    std::string identify() const;
    void SetThink(std::string think);
    void GetThink() const;

private:
    std::string mDeepThink;
};

#endif