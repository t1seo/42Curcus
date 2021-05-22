#include <iostream>
#include <string.h>

void memoryLeak(void)
{
    std::string *panther = new std::string("String panther");
    std::cout << *panther << std::endl;
    delete panther; // added delete
}

int main(void)
{
    memoryLeak();
}