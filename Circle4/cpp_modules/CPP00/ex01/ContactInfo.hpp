#ifndef CONTACT_INFO
#define CONTACT_INFO

#include <iomanip>
#include <iostream>
#include <string>

#include "Colors.hpp"

const int INFO_NUM = 11;

class ContactInfo
{
public:
    void SetInfo(void);
    void GetInfo(void) const;
    std::string GetInfoByIndex(int index) const;

private:
    std::string mContactInfo[INFO_NUM];
    static std::string mContactFields[INFO_NUM];
};

#endif