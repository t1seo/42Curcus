#ifndef SHRUBBERYCREATIONFORM
#define SHRUBBERYCREATIONFORM

#include <fstream>
#include "Form.hpp"

class ShrubberyCreationForm : public Form
{
public:
    ShrubberyCreationForm(const std::string &target);
    ShrubberyCreationForm(const ShrubberyCreationForm &scForm);
    ~ShrubberyCreationForm();
    ShrubberyCreationForm &operator=(const ShrubberyCreationForm &scForm);

    void execute(const Bureaucrat &bureaucrat) const;

    class FileOpenException : public std::exception
    {
        virtual const char *what(void) const throw();
    };

private:
    ShrubberyCreationForm();
    std::string mTarget;
    static const std::string mAsciiTree;
};

#endif