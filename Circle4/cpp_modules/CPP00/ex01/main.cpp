#include "Colors.hpp"
#include "PhoneBook.hpp"

typedef enum Menu
{
    EXIT = 0,
    ADD,
    SEARCH,
    WRONG
} eMenu;

void ShowPrompt(void)
{
    std::cout << ANSI_COLOR_CYAN
              << "Select Menu (ADD | SEARCH | EXIT) >> "
              << ANSI_COLOR_RESET;
}

eMenu InputMenu(std::string cmd)
{
    if (!cmd.compare("EXIT"))
        return EXIT;
    else if (!cmd.compare("ADD"))
        return ADD;
    else if (!cmd.compare("SEARCH"))
        return SEARCH;
    else
        return WRONG;
}

void ExitProgram(void)
{
    std::cout << ANSI_COLOR_RED << std::endl
              << "Exit Program"
              << ANSI_COLOR_RESET << std::endl;
    exit(0);
}

void WrongInput(void)
{
    std::cout << ANSI_COLOR_RED << "Error: Wrong Input"
              << ANSI_COLOR_RESET << std::endl;
}

int main(void)
{
    PhoneBook phoneBook;
    std::string cmd;

    while (1)
    {
        ShowPrompt();
        if (std::getline(std::cin, cmd).eof())
            ExitProgram();
        eMenu input = InputMenu(cmd);
        switch (input)
        {
        case EXIT:
            ExitProgram();

        case ADD:
            phoneBook.AddContact();
            break;

        case SEARCH:
            phoneBook.SearchContact();
            break;

        default:
            WrongInput();
            break;
        }
    }
    return 0;
}