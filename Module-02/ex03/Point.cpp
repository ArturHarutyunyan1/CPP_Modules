#include "Point.hpp"

Point::Point() : _x(0), _y(0)
{
    // std::cout << "Default constructor called" << std::endl;
}

Point::Point(Fixed x, Fixed y) : _x(x), _y(y)
{
    // std::cout << "Parametreized constructor called" << std::endl;
}

Point::Point(const Point &point) : _x(point._x), _y(point._y)
{
    // std::cout << "Copy constructor called" << std::endl;
}

Point &Point::operator=(const Point &point)
{
    // std::cout << "Copy assignment called" << std::endl;
    if (this != &point)
    {
        _x = point._x;
        _y = point._y;
    }
    return (*this);
}

Point::~Point(void)
{
    // std::cout << "Destructor called" << std::endl;
}

Fixed Point::getX() const
{
    return (_x);
}

Fixed Point::getY() const
{
    return (_y);
}