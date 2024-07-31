#include "Zombie.hpp"

int main(void)
{
    Zombie *Z;

    Z = newZombie("Zombie1");
    Z->announce();
    delete Z; //supprime le zombie cree auparavant pour eviter les leaks

    randomChump("Zombie2"); //cree un zombie temporaire et annonce
    return(0);
}