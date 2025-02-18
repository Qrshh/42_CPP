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
};

Zombie *newZombie(std::string name);
void randomChump(std::string name);

#endif