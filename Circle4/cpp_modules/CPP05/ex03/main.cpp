#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"
#include "Intern.hpp"

int main(void)
{
    Bureaucrat tom("Thomas Shelby", 1);
    Bureaucrat arthur("Arthur Shelby", 30);
    Bureaucrat polly("Elizabeth \"Polly\" Gray", 30);
    Bureaucrat john("John \"Johnny\" Shelby", 60);
    Bureaucrat finn("Finn Shelby", 146);

    Intern intern;
    Form *form;

    try
    {
        form = intern.makeForm("PresidentialPardon", "Winston Churchill");
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }

    tom.signForm(*form);
    tom.executeForm(*form);

    try
    {
        form = intern.makeForm("FakeForm", "Winston Churchill");
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
}