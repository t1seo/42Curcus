#ifndef PEASANT
#define PEASANT

#include "Victim.hpp"

class Peasant : public Victim
{
public:
    Peasant();
    Peasant(const std::string &name);
    Peasant(const Peasant &peasant);
    virtual ~Peasant();

    Peasant &operator=(const Peasant &peasant);

private:
    virtual void getPolymorphed() const;
};

#endif