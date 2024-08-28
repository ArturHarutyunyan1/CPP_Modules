#include "Fixed.hpp"

const int Fixed::_num = 8;

Fixed::Fixed(void) : _fixedPoint(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int arg)
{
    std::cout << "Int constructor called" << std::endl;
    this->_fixedPoint = arg << _num;
}

Fixed::Fixed(const float arg)
{
    std::cout << "Float constructor called" << std::endl;
    this->_fixedPoint = roundf(arg * (1 << this->_num));
}

Fixed::Fixed(const Fixed &f) : _fixedPoint(f._fixedPoint)
{
    std::cout << "Copy constructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed &f)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &f)
        _fixedPoint = f.getRawBits();
    return (*this);
}

Fixed::~Fixed(void)
{
    std::cout << "Destructor called" << std::endl;
}

float Fixed::toFloat( void ) const
{
    return ((float)this->_fixedPoint / (float)(1 << this->_num));
}

int Fixed::toInt( void ) const
{
    return (this->_fixedPoint >> this->_num);
}

int Fixed::getRawBits( void ) const
{
    // std::cout << "getRawBits member function called" << std::endl;
    return (this->_fixedPoint);
}

void Fixed::setRawBits(int const raw)
{
    // std::cout << "setRawBits member function called" << std::endl;
    this->_fixedPoint = raw;
}

std::ostream& operator<<(std::ostream &o, Fixed const &fixed)
{
    o << fixed.toFloat();
    return (o);
}