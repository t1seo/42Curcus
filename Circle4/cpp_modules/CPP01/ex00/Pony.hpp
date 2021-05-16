#ifndef PONY
#define PONY

#include <string>
#include <iostream>

class Pony
{
public:
    Pony(const std::string &name);
    ~Pony();
    void Eat(void) const;
    void Run(void) const;
    void Sleep(void) const;

private:
    std::string mName;
};

#endif