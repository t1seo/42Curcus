#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(const std::string &target)
    : Form("RobotomyRequest", 72, 45), mTarget(target)
{
    srand(time(NULL));
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &rrForm)
    : Form(rrForm), mTarget(rrForm.mTarget)
{
    srand(time(NULL));
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &rrForm)
{
    mTarget = rrForm.mTarget;
    return (*this);
}

void RobotomyRequestForm::execute(Bureaucrat const &Bureaucrat) const
{
    if (Form::getSigned())
    {
        if (Bureaucrat.getGrade() <= Form::getExecuteGrade())
        {
            std::cout << ANSI_COLOR_CYAN
                      << "Transforming..."
                      << ANSI_COLOR_RESET
                      << std::endl;
            if (rand() % 2)
            {
                std::cout << ANSI_COLOR_YELLOW
                          << mTarget
                          << ANSI_COLOR_GREEN
                          << "has been robotomized successfully."
                          << ANSI_COLOR_RESET
                          << std::endl;
            }
            else
            {
                std::cout << ANSI_COLOR_YELLOW
                          << mTarget
                          << ANSI_COLOR_GREEN
                          << "has been robotomized successfully."
                          << "has been robotomized failed."
                          << ANSI_COLOR_RESET
                          << std::endl;
            }
        }
        else
            throw Form::GradeTooLowException();
    }
    else
        throw Form::NotSignedException();
}
