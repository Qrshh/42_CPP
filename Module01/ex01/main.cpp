#include "Zombie.hpp"

int main(void)
{
    Zombie *zombies;
    int nb_zombies = 12;
    std::string name = "Zombie";

    zombies = zombieHorde(nb_zombies, name);
    for(int i = 0; i < nb_zombies; i++)
        zombies[i].announce();

    delete [] zombies;
    return (0);
}