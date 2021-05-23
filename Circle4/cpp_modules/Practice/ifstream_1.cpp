#include <iostream>
#include <fstream>

int main(void)
{
    std::string str;
    std::ifstream in;
    char buf[100];

    in.open("text.txt");

    while (in)
    {
        in.getline(buf, 100);
        std::cout << buf << std::endl;
    }
    in.close();
}