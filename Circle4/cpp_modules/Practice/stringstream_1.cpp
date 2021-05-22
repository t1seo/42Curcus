#include <iostream>
#include <string>
#include <sstream>

int main(void)
{
    float num;
    std::stringstream stream1;

    std::string str = "25 1 3 .235\n1111111\n22222absdaw";
    stream1.str(str);

    while (stream1 >> num)
        std::cout << "num: " << num << std::endl;

    return 0;
}