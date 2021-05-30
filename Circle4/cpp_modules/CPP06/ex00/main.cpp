#include "Convert.hpp"

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        std::cout << "Error: bad arguments" << std::endl;
        return 1;
    }

    std::string value = argv[1];
    convertAll(value);

    return 0;
}