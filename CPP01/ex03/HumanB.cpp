#include "HumanB.hpp"

HumanB::HumanB(std::string name) : name(name)
{
    return ;
}
void HumanB::setWeapon(Weapon &weapon)
{
    this->weapon = &weapon;
}

void HumanB::attack(void)
{
    std::cout << this->name << " attacks with their";
    if(this->weapon)
        std::cout <<this->weapon->getType() << std::endl;
    else 
        std::cout << "hands" << std::endl;
    return ;
}