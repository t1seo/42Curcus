#include <iostream>
#include <string>

int main(void)
{
    std::string str = "HI THIS IS BRAIN";
    std::string *ptr = &str;
    std::string &ref = str;

    std::cout << "str: " << str << std::endl;
    std::cout << "ptr: " << *ptr << std::endl;
    std::cout << "ref: " << ref << std::endl
              << std::endl;

    str = "NEW BRAIN";
    std::cout << "str: " << str << std::endl;
    std::cout << "ptr: " << *ptr << std::endl;
    std::cout << "ref: " << ref << std::endl
              << std::endl;

    ref = "ANOTHER BARIN";
    std::cout << "str: " << str << std::endl;
    std::cout << "ptr: " << *ptr << std::endl;
    std::cout << "ref: " << ref << std::endl
              << std::endl;

    return 0;
}