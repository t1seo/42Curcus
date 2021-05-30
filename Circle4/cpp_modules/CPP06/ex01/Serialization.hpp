#ifndef SERIALIZATION
#define SERIALIZATION

#include <iostream>

struct Data
{
    std::string s1;
    int n;
    std::string s2;
};

void *serialize();
Data *deserialize(void *raw);

#endif
