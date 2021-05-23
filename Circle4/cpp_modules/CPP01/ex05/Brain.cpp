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

void Brain::SetThink(std::string think)
{
    this->mDeepThink = think;
}

void Brain::GetThink() const
{
    std::cout << "I think " << mDeepThink << std::endl;
}
