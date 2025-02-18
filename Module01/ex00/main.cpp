#include "Zombie.hpp"

int main(void)
{
    Zombie *Z;
    Zombie *Y;

    Z = newZombie("Zombie1");
    Z->announce();
    delete Z; //supprime le zombie cree juste avant pour les leaks
    Y = newZombie("Zombie2");
    Y->announce();
    delete Y;

    randomChump("Caca Boudingue de toi"); //cree un zombie temporairement
    return(0);
}