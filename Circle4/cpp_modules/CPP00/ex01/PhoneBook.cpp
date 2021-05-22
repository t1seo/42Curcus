#include "PhoneBook.hpp"

void PrintError(const std::string message)
{
    std::cout << ANSI_COLOR_RED
              << message
              << ANSI_COLOR_RESET
              << std::endl;
}

PhoneBook::PhoneBook() : mInfoIndex(0)
{
}

void PhoneBook::PrintSearchMenu(void)
{
    std::cout << ANSI_COLOR_GREEN;
    std::cout << "|-------------------------------------------|" << std::endl;
    std::cout << "|                 PHONE BOOK                |" << std::endl;
    std::cout << "|-------------------------------------------|" << std::endl;
    std::cout << "|  INDEX   |FIRST NAME| LAST NAME| NICKNAME |" << std::endl;
    std::cout << "|-------------------------------------------|" << std::endl;
    for (int i = 0; i < mInfoIndex; ++i)
    {
        std::cout << "|";
        std::cout.setf(std::ios::right);
        std::cout << std::setw(10) << i + 1 << "|";
        for (int j = 0; j < 3; ++j)
        {
            std::string tempInfo(mInfo[i].GetInfoByIndex(j));
            if (tempInfo.length() > 10)
            {
                tempInfo = tempInfo.substr(0, 9) + ".";
            }
            std::cout << std::setw(10) << tempInfo << "|";
        }
        std::cout << std::endl;
    }
    std::cout << "|-------------------------------------------|" << std::endl;
    std::cout << ANSI_COLOR_RESET;
}

void PhoneBook::AddContact(void)
{
    if (mInfoIndex >= 8)
        PrintError("Error: Phonebook is full");
    else
    {
        mInfo[mInfoIndex].SetInfo();
        mInfoIndex++;
    }
}

void PhoneBook::SearchContact(void)
{
    if (mInfoIndex == 0)
        PrintError("Error: No Data");
    else
    {
        PrintSearchMenu();
        int inputNum;
        while (1)
        {
            std::cout << "Index Num >> ";
            std::cin >> inputNum;
            if (std::cin.eof())
            {
                PrintError("Exit Program");
                exit(0);
            }
            if (inputNum >= 1 && inputNum - 1 < mInfoIndex)
            {
                mInfo[inputNum - 1].GetInfo();
                std::cin.ignore();
                break;
            }
            else
            {
                PrintError("Error: Wrong Index");
                std::cin.clear();
                std::cin.ignore();
            }
        }
    }
}