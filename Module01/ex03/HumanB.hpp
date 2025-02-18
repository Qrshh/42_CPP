#ifndef HUMANB_HPP
#define HUMANB_HPP

#include "Weapon.hpp"

class HumanB
{
    private:
        std::string name;
        Weapon *wp; //ptr car ca peut etre null
    public:
        HumanB(std::string name);
        ~HumanB();
        void setWeapon(Weapon &wp);
        void attack();
};


#endif