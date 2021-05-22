#include "ZombieEvent.hpp"

int main(void)
{
    Zombie king("Zombie King", "🧟");
    king.announce();
    std::cout << ANSI_COLOR_RED
              << "The zombie king was born."
              << ANSI_COLOR_RESET << std::endl;

    ZombieEvent event;

    event.setZombieType("Beatles 🎸");
    Zombie *beatles[4];
    for (int i = 0; i < 4; i++)
    {
        beatles[i] = event.randomChump();
    }

    std::cout << ANSI_COLOR_RED
              << Zombie::mZombieNum
              << " zombies have created."
              << ANSI_COLOR_RESET << std::endl;

    event.setZombieType("Animal 🐈");
    Zombie *cat = event.newZombie("Kitty");
    cat->announce();

    std::cout << ANSI_COLOR_RED
              << "The mighty cat zombie has created. "
              << "There are "
              << Zombie::mZombieNum
              << " zombies."
              << ANSI_COLOR_RESET << std::endl;

    // delete zombies
    std::cout << ANSI_COLOR_YELLOW << "Holy Delete !!!" << std::endl;
    for (int i = 0; i < 4; i++)
    {
        delete beatles[i];
    }
    delete cat;

    std::cout << ANSI_COLOR_RED
              << "Every zombie is dead except "
              << Zombie::mZombieNum
              << " zombie king."
              << ANSI_COLOR_RESET << std::endl;

    return 0;
}
