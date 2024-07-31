#include <iostream>

/*
Pointeur (stringPTR) : 
Stocke l'adresse d'une variable et permet l'accès indirect 
à cette variable en utilisant l'opérateur de déréférencement (*).

Référence (stringREF) : Un alias pour une variable existante, 
permettant l'accès direct à cette variable sans nécessiter 
d'opérateur spécial pour la déréférencer.
*/

int main(void)
{
    std::string origin = "HI THIS IS BRAIN";
    std::string *stringPTR = &origin;
    std::string &stringREF = origin;

    std::cout << "Origin memory adress : " << &origin << std::endl;
    std::cout << "stringPTR memory adress : " << stringPTR << std::endl;
    std::cout << "stringREF memory adress : " << &stringREF << std::endl;

    std::cout << "origin value : " << origin << std::endl;
    std::cout << "stringPTR value : " << *stringPTR << std::endl;
    std::cout << "stringREF value : " << stringREF << std::endl;

    return 0;
}