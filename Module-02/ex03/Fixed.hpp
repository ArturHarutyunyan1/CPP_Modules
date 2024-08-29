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
        bool operator>(Fixed fixed) const;
        bool operator<(Fixed fixed) const;
        bool operator>=(Fixed fixed) const;
        bool operator<=(Fixed fixed) const;
        bool operator==(Fixed fixed) const;
        bool operator!=(Fixed fixed) const;
        float operator+(Fixed fixed) const;
        float operator-(Fixed fixed) const;
        float operator*(Fixed fixed) const;
        float operator/(Fixed fixed) const;
        Fixed operator++();
        Fixed operator--();
        Fixed operator++(int);
        Fixed operator--(int);
        ~Fixed();
        float toFloat( void ) const;
        int toInt( void ) const;
        int getRawBits( void ) const;
        void setRawBits( int const raw );
        Fixed abs() const;
		static Fixed &min(Fixed &first, Fixed &second);
		static const Fixed &min(Fixed const &first, Fixed const &second);
		static Fixed &max(Fixed &first, Fixed &second);
		static const Fixed &max(Fixed const &first, Fixed const &second);
};
std::ostream& operator<<(std::ostream &o, Fixed const &fixed);
#endif