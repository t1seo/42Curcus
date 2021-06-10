#include <iostream>
#include <unistd.h>

int main(void)
{
    std::cout << "hello";
    fflush(stdout);
    sleep(5);
    return 0;
}