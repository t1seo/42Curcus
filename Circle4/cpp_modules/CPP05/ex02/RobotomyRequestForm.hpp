#ifndef ROBOTOMYREQUESTFORM
#define ROBOTOMYREQUESTFORM

#include "Form.hpp"

class RobotomyRequestForm : public Form
{
public:
    RobotomyRequestForm(const std::string &target);
    RobotomyRequestForm(const RobotomyRequestForm &rrForm);
    ~RobotomyRequestForm();
    RobotomyRequestForm &operator=(const RobotomyRequestForm &rrForm);

    void execute(Bureaucrat const &Bureaucrat) const;

private:
    std::string mTarget;
    RobotomyRequestForm();
};

#endif