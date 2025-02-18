#include "Harl.hpp"

Harl::Harl(){
    return ;
}

Harl::~Harl(){
    return ;
}

void Harl::debug(){
    std::cout << "[ DEBUG ]" << std::endl;
    std::cout << "DEBUG FONCTON CALLED" << std::endl;
    return ;
}

void Harl::info(){
    std::cout << "[ INFO ]" << std::endl;
    std::cout << "INFO FONCTON CALLED" << std::endl;
    return ;
}

void Harl::warning(){
    std::cout << "[ WARNING ]" << std::endl;
    std::cout << "WARNING FONCTON CALLED" << std::endl;
    return ;
}

void Harl::error(){
    std::cout << "[ ERROR ]" << std::endl;
    std::cout << "ERROR FONCTON CALLED" << std::endl;
    return ;
}

void Harl::complain(std::string level)
{
    void (Harl::*fn[])() = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};

    std::string levels[] = {
        "DEBUG",
        "INFO",
        "WARNING",
        "ERROR"
    };

    for(int i = 0; i < 4; i++)
    {
        if(levels[i] == level)
        {
            for(int y = i; y < 4; y ++)
            {
                (this->*fn[y])();
                if(y < 3)
                    std::cout << std::endl;
            }
            return ;
        }
    }
    std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
}

