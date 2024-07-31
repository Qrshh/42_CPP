#include "Zombie.hpp"

Zombie::Zombie(void)
{
    return ;
}

Zombie::Zombie(std::string name) //initialise l'objet avec son nom
{
    this->name = name;
    return ;
}

Zombie::~Zombie(void) //affiche un message comme quoi le zombie est detruit
{
    std::cout << name << " destroyed" << std::endl;
    return ;
}

void Zombie::announce(void) //affiche le message avec son blase de con
{
    std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
    return ;
}

std::string Zombie::getName(void)
{
    return name;
}

void Zombie::setName(std::string name)
{
    this->name = name;
    return ;
}