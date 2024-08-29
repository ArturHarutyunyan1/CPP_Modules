#include "Fixed.hpp"

const int Fixed::_num = 8;

Fixed::Fixed(void) : _fixedPoint(0)
{
    // std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int arg)
{
    // std::cout << "Int constructor called" << std::endl;
    this->_fixedPoint = arg << _num;
}

Fixed::Fixed(const float arg)
{
    // std::cout << "Float constructor called" << std::endl;
    this->_fixedPoint = roundf(arg * (1 << this->_num));
}

Fixed::Fixed(const Fixed &f) : _fixedPoint(f._fixedPoint)
{
    // std::cout << "Copy constructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed &f)
{
    // std::cout << "Copy assignment operator called" << std::endl;
    if (this != &f)
        _fixedPoint = f.getRawBits();
    return (*this);
}

bool Fixed::operator>(const Fixed fixed)const
{
    return (this->toFloat() > fixed.toFloat());
}

bool Fixed::operator<(const Fixed fixed)const
{
    return (this->toFloat() < fixed.toFloat());
}

bool Fixed::operator>=(const Fixed fixed)const
{
    return (this->toFloat() >= fixed.toFloat());
}

bool Fixed::operator<=(const Fixed fixed)const
{
    return (this->toFloat() <= fixed.toFloat());
}

bool Fixed::operator==(const Fixed fixed)const
{
    return (this->toFloat() == fixed.toFloat());
}

bool Fixed::operator!=(const Fixed fixed)const
{
    return (this->toFloat() != fixed.toFloat());
}

float Fixed::operator+(Fixed fixed) const
{
    return (this->toFloat() + fixed.toFloat());
}

float Fixed::operator-(Fixed fixed) const
{
    return (this->toFloat() - fixed.toFloat());
}

float Fixed::operator/(Fixed fixed) const
{
    return (this->toFloat() / fixed.toFloat());
}

float Fixed::operator*(Fixed fixed) const
{
    return (this->toFloat() * fixed.toFloat());
}

Fixed Fixed::operator++(void)
{
    this->_fixedPoint++;
    return (*this);
}

Fixed Fixed::operator--(void)
{
    this->_fixedPoint--;
    return (*this);
}

Fixed Fixed::operator++(int)
{
    Fixed tmp = *this;
    ++this->_fixedPoint;
    return (tmp);
}

Fixed Fixed::operator--(int)
{
    Fixed tmp = *this;
    --this->_fixedPoint;
    return (tmp);
}


Fixed::~Fixed(void)
{
    // std::cout << "Destructor called" << std::endl;
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

Fixed Fixed::abs() const
{
    return (std::abs(_fixedPoint) / (1 << _num));
}

Fixed	&Fixed::min(Fixed &first, Fixed &second)
{
    if (first.toFloat() < second.toFloat())
        return (first);
    else
        return (second);
}

const Fixed	&Fixed::min(const Fixed &first, const Fixed &second)
{
    if (first.toFloat() < second.toFloat())
        return (first);
    else
        return (second);
}

Fixed	&Fixed::max(Fixed &first, Fixed &second)
{
    if (first.toFloat() > second.toFloat())
        return (first);
    else
        return (second);
}

const Fixed	&Fixed::max(const Fixed &first, const Fixed &second)
{
    if (first.toFloat() > second.toFloat())
        return (first);
    else
        return (second);
}

std::ostream& operator<<(std::ostream &o, Fixed const &fixed)
{
    o << fixed.toFloat();
    return (o);
}