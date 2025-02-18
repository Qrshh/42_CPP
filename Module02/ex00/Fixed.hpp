#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

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
        //OVERLOAD
        Fixed &operator=( const Fixed &other);
        //Destructeur
        ~Fixed();

        int getRawBits(void) const;

        void setRawBits( int const raw) ;
};



#endif

Fixed a;
Fixed b;

a();
