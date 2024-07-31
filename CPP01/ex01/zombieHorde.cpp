#include "Zombie.hpp"

//declare un tableau de Zombie pour tout allouer et ensuite on setName
Zombie*     zombieHorde(int N, std::string name)
{
    Zombie *zombieHorde = new Zombie[N];

    for(int i = 0; i < N; i++)
        zombieHorde[i].setName(name);
    return zombieHorde;
}