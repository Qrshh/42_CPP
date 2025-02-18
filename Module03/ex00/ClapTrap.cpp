#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : name("Default"), hitPoints(10), energyPoints(10), attackDamage(0)
{
    std::cout << "Default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : name(name), hitPoints(10), energyPoints(10), attackDamage(0)
{
    std::cout << "Constructor called" << std::endl;
}

ClapTrap::~ClapTrap()
{
    std::cout << "Destructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = other;
}

ClapTrap &ClapTrap::operator=(ClapTrap const &copy)
{
    if(this != &copy)
    {
        this->name = copy.name;
        this->hitPoints = copy.hitPoints;
        this->energyPoints = copy.energyPoints;
        this->attackDamage = copy.attackDamage;
    }
    return *this;
}

void ClapTrap::attack(const std::string &target)
{
    if(this->energyPoints > 0 && this->hitPoints > 0)
    {
        this->energyPoints--;
        std::cout << "ClapTrap " << this->name << " attacks " << target << ", causing " << this->attackDamage << " points of damage !" << std::endl;

    }
    else 
        std::cout << "ClapTrap " << this->name <<" doesn't have enought hit points or energy points" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if(this->hitPoints <= 0)
    {
        std::cout << "ClapTrap " << this->name << " doesn't have any hit points" << std::endl;
        return ;
    }
    if(this->hitPoints > amount)
        this->hitPoints -= amount;
    else 
        this->hitPoints = 0;

    if(amount > 1)
        std::cout << "ClapTrap " << this->name << " takes " << amount << " points of damage" << std::endl;
    else if (amount == 1)
        std::cout << "ClapTrap " << this->name << " takes " << amount << " point of damage" << std::endl;
    else if (amount == 0)
        std::cout << "ClapTrap " << this->name << " is invincible because he takes " << amount << "point of damage" << std::endl;

    std::cout << "Hit points left : " << this->hitPoints << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if(this->energyPoints > 0 && this->hitPoints > 0)
    {
        this->hitPoints += amount;
        std::cout << "ClapTrap " << this->name << " recovered " << amount << " hit points " << std::endl;
        std::cout << "ClapTrap " << this->name << " hit points : " << this->hitPoints << std::endl;
        this->energyPoints--;
    }
    else
        std::cout << "ClapTrap " << this->name << " can't do nothing :( " << std::endl;

}

