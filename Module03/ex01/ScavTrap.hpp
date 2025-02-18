#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP


#include <iostream>
#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
    private:
        bool gateKeeperMode;
    
    public:
        /*Default Constructor*/
        ScavTrap();

        /*Constructor*/
        ScavTrap(const std::string name);

        /*Copy constructor*/
        ScavTrap(const ScavTrap &other);

        /*Operator overload*/
        ScavTrap &operator=(const ScavTrap &copy);

        /*Destructor*/
        ~ScavTrap();

        void guardGate();
        void attack(const std::string &target);
};


#endif