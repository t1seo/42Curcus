#include "Bureaucrat.hpp"

int main(void)
{
    Bureaucrat tom("Thomas Shelby", 1);
    Bureaucrat arthur("Arthur Shelby", 30);
    Bureaucrat polly("Elizabeth \"Polly\" Gray", 30);
    Bureaucrat john("John \"Johnny\" Shelby", 60);
    Bureaucrat finn("Finn Shelby", 150);

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

    Bureaucrat *michael;
    try
    {
        michael = new Bureaucrat("Michel Grey", 151); // exception
    }
    catch (const std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    try
    {
        finn.decrementGrade(); // exception
    }
    catch (const std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << arthur;
    try
    {
        arthur.incrementGrade(); // exception
    }
    catch (const std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    std::cout << arthur;
    return 0;
}