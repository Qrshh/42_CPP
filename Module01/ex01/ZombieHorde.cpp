#include "Zombie.hpp"

//creation d'un tableau de Zombie pour se mettre bien
Zombie* zombieHorde(int N, std::string name)
{
    Zombie *zombieHorde = new Zombie[N];

    for(int i = 0; i < N; i++)
        zombieHorde[i].setZombieName(name); //on set name de chaque zombie
    return zombieHorde;
}