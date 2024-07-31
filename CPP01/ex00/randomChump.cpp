#include "Zombie.hpp"


//cree un zombie temporaire sur le tas et l'annonce
void randomChump(std::string name)
{
    return(Zombie(name).announce());
}