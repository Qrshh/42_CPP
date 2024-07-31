#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon) : name(name), weapon(weapon)
{
    return ;
}


void HumanA::attack(void)
{
    std::cout << this->name << " attacks with their";
    std::cout << this->weapon.getType() << std::endl;
    return ;
}