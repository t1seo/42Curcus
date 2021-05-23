#include "Human.hpp"

Human::Human()
{
}

Human::~Human()
{
}

const Brain &Human::getBrain() const
{
    return this->mBrain;
}

std::string Human::identify() const
{
    return this->mBrain.identify();
}
