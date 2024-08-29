#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"
#include <cmath>

class Point
{
    private:
        Fixed _x;
        Fixed _y;
    public:
        Point();
        Point(Fixed x, Fixed y);
        Point(const Point &point);
        Point &operator=(const Point &point);
        ~Point();
        Fixed getX() const;
        Fixed getY() const;
};

#endif