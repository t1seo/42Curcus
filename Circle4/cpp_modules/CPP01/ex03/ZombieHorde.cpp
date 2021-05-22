#include "ZombieHorde.hpp"

ZombieHorde::ZombieHorde(int size)
    : mSize(size)
{
    std::string namePool[] = {
        "John Lennon",
        "Paul McCartney",
        "George Harrison",
        "Ringo Starr"};

    std::string typePool[] = {
        "Guitar 🎸",
        "Keyboard 🎹",
        "Vocal ‍🎤",
        "Drum 🥁"};

    if (size <= 0)
    {
        std::cout << ANSI_COLOR_RED
                  << "Error: Size must be larger than 0."
                  << ANSI_COLOR_RESET
                  << std::endl;
    }
    else
    {
        std::srand(std::time(NULL));

        mHorde = new Zombie[mSize];
        int nameSize = sizeof(namePool) / sizeof(std::string);
        int typeSize = sizeof(typePool) / sizeof(std::string);
        for (int i = 0; i < mSize; ++i)
        {
            std::string name = namePool[rand() % nameSize];
            std::string type = typePool[rand() % typeSize];
            mHorde[i].setName(name);
            mHorde[i].setType(type);
        }
    }
}

ZombieHorde::~ZombieHorde()
{
    delete[] mHorde;
}

void ZombieHorde::announce() const
{
    for (int i = 0; i < mSize; i++)
    {
        mHorde[i].announce();
    }
}