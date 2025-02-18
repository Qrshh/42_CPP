#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"
//en virtual comme ca ClapTrap apparait qu'une fois dans DiamondTrap
class FragTrap : virtual public ClapTrap
{
    public:
        FragTrap();
        FragTrap(const std::string name);
        FragTrap(const FragTrap &other);

        FragTrap &operator=(const FragTrap &other);

        ~FragTrap();

        void highFivesGuys(void);
};

#endif