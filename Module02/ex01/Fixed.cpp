#include "Fixed.hpp"

//DEFAULT
Fixed::Fixed( void ) : value(0)
{
    std::cout << "Default constructor called " << std::endl;
}

//NEW CONSTRUCTORS
Fixed::Fixed( const int para)
{ //admetons Fixed a(5)
    // 5 << 8 = 5 * 256 = 1280
    std::cout << "Int constructor called" << std::endl;
    this->value = para << Fixed::fractional_bits;
}

Fixed::Fixed(const float para)
{
    //admettons Fixed a(5.05f)
    //on a : 5.05 * 256 = 1292.8
    // roundf(1292.8) = 1293
    std::cout << "Float constructor called" << std::endl;
    this->value = roundf(para * (1 << this->fractional_bits));
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
{
    std::cout << "getRawBits member function called" << std::endl;
    return this->value;
}

void Fixed::setRawBits(int const raw)
{
    std::cout << "setRawBits member function called" << std::endl;
    this->value = raw;
}

int Fixed::toInt(void)const
{
    return this->value >> this->fractional_bits; // Décale les bits pour obtenir la partie entière
}

float Fixed::toFloat(void) const
{
    return (float)this->value / (float)(1 << this->fractional_bits);
}

//OVERLOAD OPERATOR 
std::ostream &operator<<(std::ostream &op, Fixed const &f)
{
    return op << f.toFloat();
}