#include "Intern.hpp"

const std::string Intern::mForms[3] =
    {
        "PresidentialPardon",
        "RobotomyRequest",
        "ShrubberyCreation",
};

Intern::Intern()
{
}

Intern::Intern(const Intern &intern)
{
    *this = intern;
}

Intern::~Intern()
{
}

Intern &Intern::operator=(const Intern &intern)
{
    if (this == &intern)
        return (*this);
    return (*this);
}

Form *Intern::makeForm(const std::string &form, const std::string &target)
{
    for (int i = 0; i < 3; ++i)
    {
        if (form == mForms[i])
        {
            std::cout << ANSI_COLOR_GREEN
                      << "Intern creates "
                      << ANSI_COLOR_YELLOW
                      << form
                      << ANSI_COLOR_RESET
                      << std::endl;
            switch (i)
            {
            case PRESIDENTIAL_PARDON:
                return (new PresidentialPardonForm(target));
                break;
            case ROBOTOMY_REQUEST:
                return (new RobotomyRequestForm(target));
                break;
            case SHRUBBERY_CREATION:
                return (new ShrubberyCreationForm(target));
                break;
            }
        }
    }
    throw Intern::InvalidFormException();
    return NULL;
}

const char *Intern::InvalidFormException::what() const throw()
{
    return (ANSI_COLOR_RED "InternException: Invalid Form Type" ANSI_COLOR_RESET);
}
