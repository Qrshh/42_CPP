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

        //OVERLOAD operator
        Fixed &operator=( const Fixed &other);

        //COMPARISONS 
        bool operator<(const Fixed &other)const;
        bool operator>(const Fixed &other)const;
        bool operator>=(const Fixed &other)const;
        bool operator<=(const Fixed &other)const;
        bool operator==(const Fixed &other)const;
        bool operator!=(const Fixed &other)const;

        //ARITHMETICS
        Fixed operator+(const Fixed &other)const;
        Fixed operator-(const Fixed &other)const;
        Fixed operator*(const Fixed &other)const;
        Fixed operator/(const Fixed &other)const;
        Fixed &operator++();
        Fixed operator++( int );
        Fixed &operator--();
        Fixed operator--( int );


        //MIN AND MAX FUNCTIONS
        static const Fixed &min( Fixed const &a, Fixed const &b);
        static Fixed &min(Fixed &a, Fixed &b);

        static const Fixed &max(Fixed const &a, Fixed const &b);
        static Fixed &max(Fixed &a, Fixed &b);

        //Destructeur
        ~Fixed();

        int getRawBits(void) const;

        void setRawBits( int const raw) ;

        int toInt( void ) const;
        float toFloat(void) const;
};

std::ostream &operator<<( std::ostream &op, Fixed const &f);


#endif