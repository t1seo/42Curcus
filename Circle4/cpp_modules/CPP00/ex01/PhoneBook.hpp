#ifndef PHONE_BOOK
#define PHONE_BOOK

#include <iostream>
#include <iomanip>

#include "Colors.hpp"
#include "ContactInfo.hpp"

const int CONTACT_NUM = 8;

class PhoneBook
{
public:
    PhoneBook();

    void AddContact(void);
    void SearchContact(void);
    void PrintSearchMenu(void);

private:
    int mInfoIndex;
    ContactInfo mInfo[CONTACT_NUM];
};

#endif