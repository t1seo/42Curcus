#ifndef FORM
#define FORM

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
public:
    Form(const std::string &name, const int signGrade, const int executeGrade);
    Form(const Form &form);
    ~Form();
    Form &operator=(const Form &form);

    const std::string &getName() const;
    bool getSigned() const;
    int getSignGrade() const;
    int getExecuteGrade() const;

    void beSigned(const Bureaucrat &bureaucrat);

    class GradeTooHighException : public std::exception
    {
        virtual const char *what() const throw();
    };

    class GradeTooLowException : public std::exception
    {
        virtual const char *what() const throw();
    };

private:
    Form();
    const std::string mName;
    bool mSigned;
    const int mSignedGrade;
    const int mExecuteGrade;
};

std::ostream &operator<<(std::ostream &os, const Form &form);

#endif