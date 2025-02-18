#include "Zombie.hpp"

Zombie::Zombie(void)
{
    return ;
}

Zombie::Zombie(std::string name) //initialise avec le nom
{
    this->name = name;
    return ;
}

Zombie::~Zombie(void) //destructeur qui print un message
{
    std::cout << name << " destroyed " << std::endl;
    return ;
}

void Zombie::announce(void) //methode pour annoncer
{
    std::cout << name << ":  BraiiiiiiinnnzzzZ..." << std::endl;
    return ;
}