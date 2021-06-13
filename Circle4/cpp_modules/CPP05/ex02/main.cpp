/*
ShrubberyCreationForm
- sign : over 145
- execute : over 137

RobotomyRequestForm
- sign : over 72
- execute : over 45

PresidentialPardonForm
- sign : over 25
- execute : over 5

*/

#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"

int main(void)
{
    Bureaucrat tom("Thomas Shelby", 1);
    Bureaucrat arthur("Arthur Shelby", 30);
    Bureaucrat polly("Elizabeth \"Polly\" Gray", 30);
    Bureaucrat john("John \"Johnny\" Shelby", 60);
    Bureaucrat finn("Finn Shelby", 146);

    std::cout << tom;
    std::cout << polly;
    std::cout << arthur;
    std::cout << john;
    std::cout << finn;

    std::cout << std::endl;

    // Shrubbery
    ShrubberyCreationForm sf("Rose");
    try
    {
        // finn.signForm(sf); // exception
        john.signForm(sf);
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    try
    {
        // finn.signForm(sf); // exception
        john.executeForm(sf);
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    // Robot
    RobotomyRequestForm rf("Peaky Blinders");
    try
    {
        john.signForm(rf);
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    try
    {
        // john.executeForm(rf);
        polly.executeForm(rf);
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    // President
    PresidentialPardonForm tf("Winston Churchill");
    try
    {
        // arthur.signForm(tf);
        tom.signForm(tf);
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    try
    {
        // arthur.executeForm(tf);
        tom.executeForm(tf);
    }
    catch (const std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    return (0);
}