#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
    private:
        int _fixedPoint;
        static const int _num;
    public:
        Fixed();
        Fixed(const Fixed &f);
        Fixed(const int arg);
        Fixed(const float arg);
        Fixed& operator=(const Fixed &f);
        ~Fixed();
        float toFloat( void ) const;
        int toInt( void ) const;
        int getRawBits( void ) const;
        void setRawBits( int const raw );
};
std::ostream& operator<<(std::ostream &o, Fixed const &fixed);
#endif