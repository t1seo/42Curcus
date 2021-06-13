#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void)
{
    Bureaucrat tom("Thomas Shelby", 1);
    Bureaucrat arthur("Arthur Shelby", 10);
    Bureaucrat polly("Elizabeth \"Polly\" Gray", 20);
    Bureaucrat john("John \"Johnny\" Shelby", 60);
    Bureaucrat finn("Finn Shelby", 150);

    std::cout << tom;
    std::cout << polly;
    std::cout << arthur;
    std::cout << john;
    std::cout << finn;

    // Form(const std::string &name, const int signGrade, const int executeGrade);
    Form *merge;
    try
    {
        merge = new Form("f1", 0, 10); // exception
    }
    catch (const std::exception &e)
    {
        std::cout << e.what() << '\n';
    }

    Form attack("ATTACK SOLOMON", 5, 20);
    try
    {
        tom.signForm(attack);
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    try
    {
        arthur.signForm(attack);
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}