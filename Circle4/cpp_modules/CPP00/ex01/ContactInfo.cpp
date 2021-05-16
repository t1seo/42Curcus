#include "ContactInfo.hpp"

std::string ContactInfo::mContactFields[INFO_NUM] =
    {
        "First Name", "Last Name", "Nickname",
        "Login", "Postal Address", "Email Address",
        "Phone Number", "Birthday Date", "Favorite Meal",
        "Underwear Color", "Darkest Secret"};

void ContactInfo::SetInfo(void)
{
    for (int i = 0; i < INFO_NUM; ++i)
    {
        std::cout.setf(std::ios::left);
        std::cout << std::setw(16) << mContactFields[i] << ": ";
        if (std::getline(std::cin, mContactInfo[i]).eof())
        {
            std::cout << ANSI_COLOR_RED << std::endl
                      << "Exit Program"
                      << ANSI_COLOR_RESET << std::endl;
            exit(0);
        }
    }
    std::cout << std::endl;
}

void ContactInfo::GetInfo(void) const
{
    for (int i = 0; i < INFO_NUM; ++i)
    {
        std::cout << std::setw(16) << mContactFields[i] << ": ";
        std::cout << mContactInfo[i] << std::endl;
    }
}

std::string ContactInfo::GetInfoByIndex(int index) const
{
    return mContactInfo[index];
}