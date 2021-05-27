#ifndef VICTIM
#define VICTIM

#include <iostream>

#define ANSI_COLOR_RED "\x1b[31m"
#define ANSI_COLOR_GREEN "\x1b[32m"
#define ANSI_COLOR_YELLOW "\x1b[33m"
#define ANSI_COLOR_BLUE "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN "\x1b[36m"
#define ANSI_COLOR_RESET "\x1b[0m"

class Victim
{
public:
    Victim();
    Victim(const std::string &name);
    Victim(const Victim &victim);
    virtual ~Victim();

    Victim &operator=(const Victim &victim);

    const std::string &getName() const;
    void setName(const std::string &name);
    virtual void getPolymorphed() const; // virtual function

private:
    std::string mName;
};

std::ostream &operator<<(std::ostream &os, const Victim &victim);

#endif