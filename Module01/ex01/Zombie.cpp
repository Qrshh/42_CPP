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

std::string Zombie::getZombieName(void)
{
    return name;
}

void Zombie::setZombieName(std::string name)
{
    this->name = name;
    return ;
}