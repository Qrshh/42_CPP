#include "Harl.hpp"

int main(int ac, char **av)
{
    if(ac == 2)
    {
        Harl harl;
        std::string level = av[1];
        harl.complain(level);
    }
    else
        std::cerr << "Log level needed !!" << std::endl;
    return(0);
}

