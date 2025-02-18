#include "Weapon.hpp"

Weapon::Weapon(void)
{
    return ;
}

Weapon::Weapon(std::string type)
{
    this->type = type;
    return ;
}

Weapon::~Weapon(void)
{
    return ;
}

const std::string &Weapon::getType(void) const
{
    return (this->type);
}

void Weapon::setType(const std::string &newType)
{
    this->type = newType;
    return ;
}