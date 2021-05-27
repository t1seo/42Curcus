#include "Enemy.hpp"

Enemy::Enemy(int hp, const std::string &type)
    : mHP(hp), mType(type)
{
}

Enemy::Enemy(const Enemy &enemy)
{
    *this = enemy;
}

Enemy::~Enemy()
{
}

Enemy &Enemy::operator=(const Enemy &enemy)
{
    mHP = enemy.mHP;
    mType = enemy.mType;
    return (*this);
}

std::string Enemy::getType() const
{
    return mType;
}

int Enemy::getHP() const
{
    return mHP;
}

void Enemy::setType(const std::string &type)
{
    mType = type;
}

void Enemy::setHP(const int hp)
{
    mHP = hp;
}

void Enemy::takeDamage(int damage)
{
    if (damage < 0)
        return;
    else
    {
        mHP -= damage;
        if (mHP < 0)
            mHP = 0;
    }
}
