#include "Fixed.hpp"

//DEFAULT
Fixed::Fixed( void ) : value(0)
{
    std::cout << "Default constructor called " << std::endl;
}

//NEW CONSTRUCTORS
Fixed::Fixed( const int para)
{
    std::cout << "Int constructor called" << std::endl;
    this->value = para << Fixed::fractional_bits;
}

Fixed::Fixed(const float para)
{
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
{  //divise la valeur entiere par 2^8 pour retrouver la valeur float
    return (float)this->value / (float)(1 << this->fractional_bits);
}

//OVERLOAD OPERATOR 
std::ostream &operator<<(std::ostream &op, Fixed const &f)
{ //Permet d'afficher un objet Fixed avec cout
    return op << f.toFloat();
}

//COMPARISONS
bool Fixed::operator>(const Fixed &other) const
{
    return this->value > other.value;
}

bool Fixed::operator<(const Fixed &other)const 
{
    return this->value < other.value;
}

bool Fixed::operator>=(const Fixed &other)const 
{
    return this->value >= other.value;
}

bool Fixed::operator<=(const Fixed &other)const 
{
    return this->value <= other.value;
}

bool Fixed::operator==(const Fixed &other)const 
{
    return this->value == other.value;
}

bool Fixed::operator!=(const Fixed &other)const 
{
    return this->value != other.value;
}

//ARITHMETICS
Fixed Fixed::operator+(const Fixed &other)const
{
    Fixed res;

    res.setRawBits(this->value + other.value);
    return res;
}

Fixed Fixed::operator-(const Fixed &other)const 
{
    Fixed res;

    res.setRawBits(this->value - other.value);
    return res;
}

Fixed Fixed::operator*(const Fixed &other)const 
{   //Multiplie valeur entiere puis decale le resultat de 8 bits pour eviter le decalage des bits fractionnaires
    Fixed res;

    res.setRawBits((this->value * other.value) >> this->fractional_bits);
    return res;
}

Fixed Fixed::operator/(const Fixed &other)const 
{ //Decale value de 8 bits puis divise par l'autre valeur
    Fixed res;

    res.setRawBits((this->value << this->fractional_bits) / other.value);
    return res;
}

Fixed &Fixed::operator++()
{ //pre incrementation (pour a = 0.0 on fait + 1/256 donc a = 0.00390625)
    this->value++;
    return *this;
}

Fixed Fixed::operator++(int)
{ //post incrementation
    Fixed temp(*this); //cree une copie
    this->value++; //incremente
    return temp; //retourne la copie
}

Fixed &Fixed::operator--()
{
    this->value--;
    return *this;
}

Fixed Fixed::operator--( int )
{
    Fixed temp(*this);
    this->value--;
    return temp;
}


//MIN AND MAX FUNCTIONS

const Fixed &Fixed::min(Fixed const &a, Fixed const &b){return a < b ? a : b; }

Fixed &Fixed::min(Fixed &a, Fixed &b) {return a < b ? a : b; }

const Fixed &Fixed::max(Fixed const &a, Fixed const &b) {return a > b ? a : b; }

Fixed &Fixed::max(Fixed &a, Fixed &b) {return a > b ? a : b; }