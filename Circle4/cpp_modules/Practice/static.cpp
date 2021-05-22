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
    void announce() const;

private:
    std::string name;
    std::string type;
    static int mZombieNum;
};

int Zombie::mZombieNum = 0;

Zombie::Zombie()
{
    mZombieNum++;
    name = "Zombie " + std::to_string(mZombieNum);
    type = "🧟";
}

Zombie::Zombie(std::string name, std::string type)
    : name(name), type(type)
{
    mZombieNum++;
}

Zombie::~Zombie()
{
    mZombieNum--;
}

void Zombie::announce(void) const
{
    std::cout << ANSI_COLOR_CYAN
              << "<" << name << " (" << type << ")>"
              << " Braiiiiiiinnnssss..."
              << ANSI_COLOR_RESET
              << std::endl;
}
int main(void)
{
    Zombie z1("zom", "normal");
    Zombie z2;

    z1.announce();
    z2.announce();
}