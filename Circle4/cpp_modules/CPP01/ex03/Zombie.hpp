#ifndef ZOMBIE
#define ZOMBIE

#include <iostream>
#include <string>

#define ANSI_COLOR_RED "\x1b[31m"
#define ANSI_COLOR_GREEN "\x1b[32m"
#define ANSI_COLOR_YELLOW "\x1b[33m"
#define ANSI_COLOR_BLUE "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN "\x1b[36m"
#define ANSI_COLOR_RESET "\x1b[0m"

class Zombie
{
public:
    Zombie();
    ~Zombie();
    Zombie(std::string name, std::string type);

    void setName(std::string name);
    void setType(std::string type);
    void announce() const;
    static int mZombieNum;

private:
    std::string name;
    std::string type;
};

#endif