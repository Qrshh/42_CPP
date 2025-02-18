#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &wp) : name(name), wp(wp){
    return ;
}


HumanA::~HumanA(void)
{
    return ;
}

void HumanA::attack()
{
    std::cout << this->name << " attacks with their " << this->wp.getType() << std::endl;
    return ;
}

