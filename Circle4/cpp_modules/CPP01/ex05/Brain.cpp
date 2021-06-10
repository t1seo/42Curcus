#include "Brain.hpp"

Brain::Brain()
    : mDeepThink("Nothing")
{
}

Brain::~Brain()
{
}

std::string Brain::identify() const
{
    std::stringstream ss;

    ss << "0x" << std::uppercase << std::hex << intptr_t(this);
    return ss.str();
}

void Brain::GetThink() const
{
    std::cout << "I think " << mDeepThink << std::endl;
}
