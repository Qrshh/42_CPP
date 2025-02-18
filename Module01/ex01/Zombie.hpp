#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>

class Zombie
{
    private:
        std::string name;

    public:
        Zombie();
        Zombie(std::string name); //constructeur avec parametre
        ~Zombie(); //DESTRUCTEUR
        void announce(void);

        //SETTER
        void setZombieName(std::string name);
        //GETTER
        std::string getZombieName(void);
};

Zombie *zombieHorde(int N, std::string name);

#endif