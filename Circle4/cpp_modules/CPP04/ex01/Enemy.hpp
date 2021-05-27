#ifndef ENEMY
#define ENEMY

#include <iostream>

#define ANSI_COLOR_RED "\x1b[31m"
#define ANSI_COLOR_GREEN "\x1b[32m"
#define ANSI_COLOR_YELLOW "\x1b[33m"
#define ANSI_COLOR_BLUE "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN "\x1b[36m"
#define ANSI_COLOR_RESET "\x1b[0m"

class Enemy
{
public:
    Enemy();
    Enemy(int hp, const std::string &type);
    Enemy(const Enemy &enemy);
    virtual ~Enemy();

    Enemy &operator=(const Enemy &enemy);

    std::string getType() const;
    int getHP() const;
    void setType(const std::string &type);
    void setHP(const int hp);

    virtual void takeDamage(int damage); // virtual function

private:
    int mHP;
    std::string mType;
};

#endif