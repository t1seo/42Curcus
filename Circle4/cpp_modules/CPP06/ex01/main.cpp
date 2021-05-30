#include "Serialization.hpp"

int main(void)
{

    void *raw = serialize();
    Data *data = deserialize(raw);

    std::cout << "s1: " << data->s1 << std::endl;
    std::cout << "n: " << data->n << std::endl;
    std::cout << "s2: " << data->s2 << std::endl;

    return 0;
}