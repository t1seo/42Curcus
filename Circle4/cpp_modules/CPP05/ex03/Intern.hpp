#ifndef INTERN
#define INTERN

#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern
{
public:
    Intern();
    Intern(const Intern &intern);
    ~Intern();
    Intern &operator=(const Intern &intern);

    Form *makeForm(const std::string &form, const std::string &target);

    class InvalidFormException : public std::exception
    {
    public:
        virtual const char *what() const throw();
    };

private:
    static const std::string mForms[3];
    typedef enum eForm
    {
        PRESIDENTIAL_PARDON,
        ROBOTOMY_REQUEST,
        SHRUBBERY_CREATION
    } tForm;
};

#endif