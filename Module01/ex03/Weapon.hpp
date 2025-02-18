#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <iostream>

class Weapon
{
    private:
        std::string type;
    public:
        Weapon();
        Weapon(std::string type);
        ~Weapon();

        //GETTER
        const std::string &getType(void) const;
        //SETTER
        void setType(const std::string& newType);
};

#endif