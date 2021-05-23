#include <fstream>
#include <iostream>
#include <string>

#define ANSI_COLOR_RED "\x1b[31m"
#define ANSI_COLOR_GREEN "\x1b[32m"
#define ANSI_COLOR_YELLOW "\x1b[33m"
#define ANSI_COLOR_BLUE "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN "\x1b[36m"
#define ANSI_COLOR_RESET "\x1b[0m"

static void printError(const std::string &error)
{
    std::cout << ANSI_COLOR_RED
              << error
              << ANSI_COLOR_RESET << std::endl;
}

static void replaceString(std::string &line, std::string s1, std::string s2)
{
    std::string::size_type pos = 0;
    while (true)
    {
        pos = line.find(s1, pos);
        if (pos == std::string::npos)
            return;
        line.replace(pos, s1.length(), s2);
        pos += s2.length();
    }
}

int main(int argc, char *argv[])
{
    if (argc != 4)
    {
        printError("Error: Invalid Arguments.");
        return -1;
    }

    std::string fileName(argv[1]);
    std::string s1(argv[2]);
    std::string s2(argv[3]);

    if (s1.empty() || s2.empty())
    {
        printError("Error: String is empty.");
        return -1;
    }

    std::ifstream ifs(fileName);
    std::ofstream ofs(fileName + ".replace");

    if (!ifs.is_open() || !ofs.is_open())
    {
        printError("Error: File Open Failed.");
        ifs.close();
        ofs.close();
        return -1;
    }

    while (ifs)
    {
        std::string line;
        getline(ifs, line);
        replaceString(line, s1, s2);
        ofs << line;
        if (!ifs.eof())
            ofs << '\n';
    }

    ifs.close();
    ofs.close();
    return 0;
}