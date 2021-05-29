// TODO : remake main

#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"
#include "Intern.hpp"

int main(void)
{
    Intern intern;
    Form *form;

    form = intern.makeForm("PresidentialPardon", "Rock");

    Bureaucrat jack("jack", 30);
    jack.signForm(*form);
    jack.executeForm(*form);
}