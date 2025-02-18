#include "sed.hpp"

int main(int ac, char **av)
{
    (void)av;
    if(ac == 4)
        sed(av);
    else 
        std::cout << "Arguments Needed !!" << std::endl;
    return(0);
}