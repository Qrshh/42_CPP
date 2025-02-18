#ifndef HUMANA_HPP
#define HUMANA_HPP

#include "Weapon.hpp"

class HumanA
{
    private:
        std::string name;
        Weapon &wp; //reference car c'est lie des l'initialisation 
                    //car l'arme ne peut pas etre null
    public:
        HumanA(std::string name, Weapon &wp);
        ~HumanA();
        void attack();
};

#endif