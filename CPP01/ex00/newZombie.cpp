#include "Zombie.hpp"


//cree un zombie sur le tas et renvoie un pointeur (alloue de la memoire dynamique (avec new))
Zombie *newZombie(std::string name)
{
    return(new Zombie(name));
}