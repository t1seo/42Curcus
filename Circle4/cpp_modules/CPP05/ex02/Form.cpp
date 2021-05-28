#include "Form.hpp"

Form::Form(const std::string &name, const int signGrade, const int executeGrade)
    : mName(name), mSigned(false), mSignedGrade(signGrade), mExecuteGrade(executeGrade)
{
    if (mSignedGrade < 1 || mExecuteGrade < 1)
        throw Form::GradeTooHighException();
    else if (mSignedGrade > 150 || mExecuteGrade > 150)
        throw Form::GradeTooLowException();
}

Form::Form(const Form &form)
    : mName(form.getName()), mSignedGrade(form.getSignGrade()), mExecuteGrade(form.getExecuteGrade())
{
    if (mSignedGrade < 1 || mExecuteGrade < 1)
        throw Form::GradeTooHighException();
    else if (mSignedGrade > 150 || mExecuteGrade > 150)
        throw Form::GradeTooLowException();
}

std::ostream &operator<<(std::ostream &os, const Form &form)
{
    return (os << ANSI_COLOR_GREEN
               << "Bureaucrat "
               << ANSI_COLOR_YELLOW
               << form.getName()
               << ANSI_COLOR_GREEN
               << "'s grade is "
               << ANSI_COLOR_YELLOW
               << form.getSignGrade()
               << ANSI_COLOR_GREEN
               << ", sign status is "
               << ANSI_COLOR_YELLOW
               << form.getSigned()
               << ANSI_COLOR_GREEN
               << ", execute grade is "
               << ANSI_COLOR_YELLOW
               << form.getExecuteGrade()
               << ANSI_COLOR_GREEN
               << "."
               << ANSI_COLOR_RESET
               << std::endl);
}

Form::~Form()
{
}

Form &Form::operator=(const Form &form)
{
    mSigned = form.mSigned;
    return (*this);
}

const std::string &Form::getName() const
{
    return mName;
}

bool Form::getSigned() const
{
    return mSigned;
}

int Form::getSignGrade() const
{
    return mSignedGrade;
}

int Form::getExecuteGrade() const
{
    return mExecuteGrade;
}

void Form::beSigned(const Bureaucrat &bureaucrat)
{
    if (mSignedGrade > bureaucrat.getGrade())
        mSigned = true;
    else
        throw Form::GradeTooLowException();
}

const char *Form::GradeTooHighException::what() const throw()
{
    return (ANSI_COLOR_RED "FormException: Grade too high" ANSI_COLOR_RESET);
}

const char *Form::GradeTooLowException::what() const throw()
{
    return (ANSI_COLOR_RED "FormException: Grade too low" ANSI_COLOR_RESET);
}

const char *Form::NotSignedException::what() const throw()
{
    return (ANSI_COLOR_RED "FormException: Not signed" ANSI_COLOR_RESET);
}