#include <iostream>
#include <string>
#include <sstream>

class Foo
{
public:
    std::string identify() const
    {
        std::stringstream ss;

        ss << intptr_t(this);
        return (ss.str());
    }
};

int main(void)
{
    Foo bob;
    std::cout << bob.identify() << std::endl;
}
