#include "Bureaucrat.hpp"

int main(void)
{
    Bureaucrat tom("Thomas Shelby", 1);

    // Tom is a boss
    std::cout << tom;
    // std::cout << tom.getName() << " " << tom.getGrade() << std::endl;
    try
    {
        tom.incrementGrade(); // exception
    }
    catch (const std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    Bureaucrat *finn;
    try
    {
        finn = new Bureaucrat("Finn Shelby", 151);
    }
    catch (const std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    return 0;
}