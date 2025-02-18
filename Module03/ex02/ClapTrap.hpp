#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>

class ClapTrap
{
    protected:
        std::string name;
        unsigned int hitPoints;
        unsigned int energyPoints;
        unsigned int attackDamage;
    
    public:
        /*Default*/
        ClapTrap();

        /*Constructor*/
        ClapTrap(std::string name);

        /*Copy*/
        ClapTrap(const ClapTrap &other);

        /*Destructor*/
        ~ClapTrap();

        /* Overload */
        ClapTrap &operator=(ClapTrap const &copy);

        void attack(const std::string &target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);

};



#endif