#include "Point.hpp"

float area(const Point &a, const Point &b, const Point &c)
{
    float areaValue = (a.getX().toFloat() * (b.getY().toFloat() - c.getY().toFloat()) +
                       b.getX().toFloat() * (c.getY().toFloat() - a.getY().toFloat()) +
                       c.getX().toFloat() * (a.getY().toFloat() - b.getY().toFloat())) / 2;
    return (areaValue);
}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
    float areaABC = area(a, b, c);
    float areaPAB = area(point, a, b);
    float areaPBC = area(point, b, c);
    float areaPCA = area(point, c, a);

    bool ret = false;

    if (areaPAB > 0 && areaPBC > 0 && areaPCA > 0 && areaPAB + areaPBC + areaPCA == areaABC)
        ret = true;
    else
        ret = false;
    return (ret);
}