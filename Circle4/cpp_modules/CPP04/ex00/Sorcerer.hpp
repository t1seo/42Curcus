#ifndef SORCERER
#define SORCERER

#include "Victim.hpp"

#define ANSI_COLOR_RED "\x1b[31m"
#define ANSI_COLOR_GREEN "\x1b[32m"
#define ANSI_COLOR_YELLOW "\x1b[33m"
#define ANSI_COLOR_BLUE "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN "\x1b[36m"
#define ANSI_COLOR_RESET "\x1b[0m"

class Sorcerer
{
public:
    Sorcerer();
    Sorcerer(const std::string &name, const std::string &title);
    Sorcerer(const Sorcerer &sorcerer);
    ~Sorcerer();

    Sorcerer &operator=(const Sorcerer &sorcerer);

    std::string getName() const;
    std::string getTitle() const;
    void polymorph(const Victim &victim) const;

private:
    std::string mName;
    std::string mTitle;
};

std::ostream &operator<<(std::ostream &os, const Sorcerer &sorcerer);

#endif