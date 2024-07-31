#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>

class Zombie {
    Zombie();
    private :
        std::string name;

    public :
        Zombie(std::string name); //Constructeur avec parametre
        ~Zombie(void); //destructeur
        void announce(void);
        
};

Zombie *newZombie(std::string name);
void randomChump(std::string name);

#endif