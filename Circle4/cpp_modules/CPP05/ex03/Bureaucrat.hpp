#ifndef BUREAUCRAT
#define BUREAUCRAT

#include <iostream>
#include "Form.hpp"

#define ANSI_COLOR_RED "\x1b[31m"
#define ANSI_COLOR_GREEN "\x1b[32m"
#define ANSI_COLOR_YELLOW "\x1b[33m"
#define ANSI_COLOR_BLUE "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN "\x1b[36m"
#define ANSI_COLOR_RESET "\x1b[0m"

class Form;

class Bureaucrat
{
public:
    Bureaucrat(const std::string &name, int grade);
    Bureaucrat(const Bureaucrat &bureaucrat);
    ~Bureaucrat();
    Bureaucrat &operator=(const Bureaucrat &bureaucrat);

    const std::string &getName() const;
    int getGrade() const;
    void incrementGrade();
    void decrementGrade();
    void signForm(Form &form) const;
    void executeForm(const Form &form);

    class GradeTooHightException : public std::exception
    {
        virtual const char *what() const throw();
    };

    class GradeTooLowException : public std::exception
    {
        virtual const char *what() const throw();
    };

private:
    Bureaucrat();

    const std::string mName;
    int mGrade;
};

std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat);

#endif