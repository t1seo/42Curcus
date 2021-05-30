#include "Serialization.hpp"

const std::string alnum = "0123456789abcdefghijklmnopqrstuvwxyz";

void *serialize()
{
    char *data = new char[sizeof(std::string) + sizeof(int) + sizeof(std::string)];

    std::string s1;
    std::string s2;
    int n;

    srand(time(NULL));

    n = rand();
    for (std::size_t i = 0; i < 8; ++i)
    {
        s1 += alnum[rand() % alnum.length()];
        s2 += alnum[rand() % alnum.length()];
    }

    *reinterpret_cast<std::string *>(data) = s1;
    *reinterpret_cast<int *>(data + sizeof(std::string)) = n;
    *reinterpret_cast<std::string *>(data + sizeof(std::string) + sizeof(int)) = s2;

    return reinterpret_cast<void *>(data);
}

Data *deserialize(void *raw)
{
    Data *data = new Data;

    data->s1 = *reinterpret_cast<std::string *>(raw);
    data->n = *reinterpret_cast<int *>(reinterpret_cast<char *>(raw) + sizeof(std::string));
    data->s2 = *reinterpret_cast<std::string *>(reinterpret_cast<char *>(raw) + sizeof(std::string) + sizeof(int));

    return data;
}
