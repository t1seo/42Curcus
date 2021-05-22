#include <iostream>
#include <string>
#include <sstream>
#include <vector>

int main(void)
{
    std::vector<std::string> input(3, ""); // given input
    input[0] = "1 Kim 89";
    input[1] = "2 Moon 100";
    input[2] = "3 Chan 78";

    for (int i = 0; i < input.size(); i++)
    {
        int num, score;
        std::string name;

        std::stringstream ss;
        ss.str(input[i]);

        ss >> num;
        ss >> name;
        ss >> score;

        std::cout << num << " " << name << " " << score << std::endl;
    }

    return 0;
}