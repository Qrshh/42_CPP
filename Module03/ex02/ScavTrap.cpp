#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
    this->hitPoints = 100;
    this->energyPoints = 50;
    this->attackDamage = 20;
    this->gateKeeperMode = false;
    std::cout << "Default ScavTrap constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
    this->hitPoints = 100;
    this->energyPoints = 50;
    this->attackDamage = 20;
    this->gateKeeperMode = false;
    std::cout << "Constructor ScavTrap created : " << this->name << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other)
{
    std::cout << "ScavTrap copy constructor called " << std::endl;
    this->gateKeeperMode = other.gateKeeperMode;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &other)
{
    std::cout << "ScavTrap overload operator = called" << std::endl;
    if(this != &other)
    {
        this->name = other.name;
        this->hitPoints = other.hitPoints;
        this->attackDamage = other.attackDamage;
        this->energyPoints = other.energyPoints;
        this->gateKeeperMode = other.gateKeeperMode;
    }
    //ON PEUT FAIRE AUSSI : ClapTrap::operator=(other);
    return *this;
}

ScavTrap::~ScavTrap()
{
    std::cout << "Destructor of ScavTrap " << this->name << " called" << std::endl;
}

void ScavTrap::guardGate()
{
    std::cout << "ScavTrap " << this->name << " gate keeper mode is ";
    if(this->gateKeeperMode)
        std::cout << "activated" << std::endl;
    else
    {
        this->gateKeeperMode = true;
        std::cout << "now activated" << std::endl;
    } 

}

void ScavTrap::attack(const std::string &target)
{
    if(this->energyPoints > 0 && this->hitPoints > 0)
    {
        this->energyPoints--;
        std::cout << "ScavTrap " << this->name << " IS ATTACKING : " << target << " CAUSING " << this->attackDamage << " damages" << std::endl;
    }
    else 
        std::cout << "ScavTrap " << this->name << " doesn't have enought hit points or energy points" << std::endl;
}