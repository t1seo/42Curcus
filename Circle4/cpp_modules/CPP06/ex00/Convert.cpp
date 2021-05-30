#include "Convert.hpp"

void convertChar(const std::string &value)
{
    std::cout << "char: ";
    try
    {
        int num = stoi(value);
        if (isprint(num))
            std::cout << "'" << static_cast<char>(num) << "'" << std::endl;
        else
            std::cerr << "Non displayable" << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << "impossible" << std::endl;
    }
}

void convertInt(const std::string &value)
{
    std::cout << "int: ";
    try
    {
        int num = stoi(value);
        std::cout << num << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << "impossible" << std::endl;
    }
}

void convertFloat(const std::string &value)
{
    std::cout << "float: ";
    try
    {
        float num = stof(value);
        if (num - static_cast<int>(num) == 0)
        {
            if (num < 1000000)
                std::cout << num << ".0f" << std::endl;
            else
                std::cout << num << "f" << std::endl;
        }
        else
        {
            std::cout << num << "f" << std::endl;
        }
    }
    catch (const std::out_of_range &e)
    {
        std::cerr << "inff" << std::endl;
    }
    catch (const std::invalid_argument &e)
    {
        std::cerr << "nanf" << std::endl;
    }
}

void convertDouble(const std::string &value)
{
    std::cout << "double: ";
    try
    {
        double num = stod(value);
        if (num - static_cast<int>(num) == 0)
        {
            if (num < 1000000)
                std::cout << num << ".0" << std::endl;
            else
                std::cout << num << std::endl;
        }
        else
        {
            std::cout << num << std::endl;
        }
    }
    catch (const std::out_of_range &e)
    {
        std::cerr << "inf" << std::endl;
    }
    catch (const std::invalid_argument &e)
    {
        std::cerr << "nan" << std::endl;
    }
}

void convertAll(const std::string &value)
{
    convertChar(value);
    convertInt(value);
    convertFloat(value);
    convertDouble(value);
}
