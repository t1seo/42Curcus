#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(const std::string &name, int grade)
    : mName(name), mGrade(grade)
{
    if (mGrade < 1)
        throw Bureaucrat::GradeTooHightException();
    else if (mGrade > 150)
        throw Bureaucrat::GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat &bureaucrat)
{
    *this = bureaucrat;
    if (mGrade < 1)
        throw Bureaucrat::GradeTooHightException();
    else if (mGrade > 150)
        throw Bureaucrat::GradeTooLowException();
}

Bureaucrat::~Bureaucrat()
{
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &bureaucrat)
{
    if (this == &bureaucrat)
        return (*this);

    mGrade = bureaucrat.getGrade();
    if (mGrade < 1)
        throw Bureaucrat::GradeTooHightException();
    else if (mGrade > 150)
        throw Bureaucrat::GradeTooLowException();
    return (*this);
}

const std::string &Bureaucrat::getName() const
{
    return mName;
}

int Bureaucrat::getGrade() const
{
    return mGrade;
}

void Bureaucrat::incrementGrade()
{
    if (mGrade - 1 <= 0)
        throw Bureaucrat::GradeTooHightException();
    else
        mGrade--;
}

void Bureaucrat::decrementGrade()
{
    if (mGrade + 1 > 150)
        throw Bureaucrat::GradeTooLowException();
    else
        mGrade++;
}

const char *Bureaucrat::GradeTooHightException::what() const throw()
{
    return (ANSI_COLOR_RED "BureaucratException: Grade is too high" ANSI_COLOR_RESET);
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
    return (ANSI_COLOR_RED "BureaucratException: Grade is too low" ANSI_COLOR_RESET);
}

std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat)
{
    return (os << ANSI_COLOR_GREEN
               << "Bureaucrat "
               << ANSI_COLOR_YELLOW
               << bureaucrat.getName()
               << ANSI_COLOR_GREEN
               << "'s grade is "
               << ANSI_COLOR_YELLOW
               << bureaucrat.getGrade()
               << ANSI_COLOR_GREEN
               << "."
               << ANSI_COLOR_RESET
               << std::endl);
}