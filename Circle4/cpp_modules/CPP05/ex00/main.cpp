// TODO: 다시 작성
#include "Bureaucrat.hpp"

int main(void)
{
    Bureaucrat A("A", 1);

    std::cout << A;
    try
    {
        A.incrementGrade();
    }
    catch (const std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    Bureaucrat *B;
    try
    {
        B = new Bureaucrat("B", 151);
    }
    catch (const std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    return 0;
}