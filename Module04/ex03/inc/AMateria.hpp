#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <iostream>

#include <ICharacter.hpp>

class AMateria
{
    protected:
        std::string type;

    public:
        AMateria();
        AMateria(std::string const &type); //constructor

        AMateria(const AMateria &other); //copy constructor
        AMateria &operator=(const AMateria &other); //overload operator

        virtual ~AMateria();

        virtual AMateria *clone() const = 0;
        virtual void use(ICharacter &target); //sous entend une  classe ICharacter

        std::string const &getType() const; // Returns the Materia type
};



#endif