#ifndef PEON
#define PEON

#include "Victim.hpp"

class Peon : public Victim
{
public:
    Peon();
    Peon(const std::string &name);
    Peon(const Peon &peon);
    virtual ~Peon();

    Peon &operator=(const Peon &peon);

private:
    void getPolymorphed() const;
};

#endif