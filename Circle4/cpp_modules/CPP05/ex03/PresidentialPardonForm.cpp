#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(const std::string &target)
    : Form("PresidentialPardon", 25, 5), mTarget(target)
{
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &ppForm)
    : Form(ppForm), mTarget(ppForm.mTarget)
{
}

PresidentialPardonForm::~PresidentialPardonForm()
{
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &ppForm)
{
    if (this == &ppForm)
        return (*this);
    Form::operator=(ppForm);
    return (*this);
}

void PresidentialPardonForm::execute(const Bureaucrat &executor) const
{
    if (Form::getSigned())
    {
        if (executor.getGrade() <= Form::getExecuteGrade())
        {
            std::cout << ANSI_COLOR_YELLOW
                      << mTarget
                      << ANSI_COLOR_GREEN
                      << " has been pardoned by Zafod Beeblebrox."
                      << ANSI_COLOR_RESET
                      << std::endl;
        }
        else
        {
            throw Form::GradeTooLowException();
        }
    }
    else
    {
        throw Form::NotSignedException();
    }
}
