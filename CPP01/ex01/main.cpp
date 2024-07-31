#include "Zombie.hpp"

int main(void)
{
    std::string name = "Zombie";
    int N = 5;

    Zombie *Z = zombieHorde(N, name);
    for(int i = 0; i < N; i++)
        Z[i].announce();
    

    //free le tableau de zombie
    delete [] Z;
    return (0);
}