#include "Fixed.hpp"

//DEFAULT
Fixed::Fixed( void ) : value(0)
{
    std::cout << "Default constructor called " << std::endl;
}

// COPY (copie la valeur d'un autre objet Fixed et 
// creer un nouvel objet qui est une copie)
Fixed::Fixed( const Fixed &other) : value(other.value)
{
    std::cout << "Copy constructor called" << std::endl;
}

//OVERLOAD (permet d'assigner la valeur d'un objet Fixed a un autre)
Fixed &Fixed::operator=(const Fixed &other)
{
    std::cout << "Copy assignment operator called " << std::endl;
    if(this != &other) // verifie si l'objet n'est pas assigne a lui meme
        this->value = other.getRawBits();
    return *this; //retourne une reference a l'objet actuel
}

//DESTRUCTOR
Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits() const
{ //retourne la valeur brute entiere stockee dans Fixed donc si value = 256, ca retourn 1.0
    //car 8 bits en partie fractionnaire
    std::cout << "getRawBits member function called" << std::endl;
    return this->value;
}

void Fixed::setRawBits(int const raw)
{ //si raw = 512 et qu'on fait a = setRawBits(512) bah a = 2.0
    std::cout << "setRawBits member function called" << std::endl;
    this->value = raw;
}