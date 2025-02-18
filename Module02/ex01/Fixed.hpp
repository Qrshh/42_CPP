#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
    private:
        int value;
        static const int fractional_bits = 8;
    public:
        //DEFAULT
        Fixed();
        //COPY
        Fixed(const Fixed &other);

        //CONSTRUCTORS 
        Fixed( const int para);
        Fixed( const float para);

        //OVERLOAD
        Fixed &operator=( const Fixed &other);

        //Destructeur
        ~Fixed();

        int getRawBits(void) const;

        void setRawBits( int const raw) ;

        int toInt( void ) const;
        float toFloat(void) const;
};

std::ostream &operator<<( std::ostream &op, Fixed const &f);


#endif