#include "HumanB.hpp"


HumanB::HumanB(std::string name) : name(name){
    return ;
}

HumanB::~HumanB(void)
{
    return ;
}

void HumanB::setWeapon(Weapon &wp)
{
    this->wp = &wp;
    return ;
}

void HumanB::attack()
{
    std::cout << this->name << " attacks with their ";
    if(this->wp)
        std::cout <<this->wp->getType() << std::endl;
    else 
        std::cout << "hands" << std::endl;
    return ;
}

