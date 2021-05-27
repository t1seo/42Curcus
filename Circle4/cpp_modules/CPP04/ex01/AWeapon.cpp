#include "AWeapon.hpp"

AWeapon::AWeapon(const std::string &name, int apcost, int damage)
    : mName(name), mAPCost(apcost), mDamage(damage)
{
}

AWeapon::AWeapon(const AWeapon &aWeapon)
{
    *this = aWeapon;
}

AWeapon::~AWeapon()
{
}

AWeapon &AWeapon::operator=(const AWeapon &aWeapon)
{
    mName = aWeapon.mName;
    mAPCost = aWeapon.mAPCost;
    mDamage = aWeapon.mDamage;
    return (*this);
}

std::string AWeapon::getName() const
{
    return mName;
}

int AWeapon::getAPCost() const
{
    return mAPCost;
}

int AWeapon::getDamage() const
{
    return mDamage;
}

void AWeapon::setName(const std::string &name)
{
    mName = name;
}

void AWeapon::setAPCost(const int apCost)
{
    mAPCost = apCost;
}

void AWeapon::setDamage(const int damage)
{
    mDamage = damage;
}
