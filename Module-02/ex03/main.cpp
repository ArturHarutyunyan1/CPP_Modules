#include "Fixed.hpp"
#include "Point.hpp"

bool bsp( Point const a, Point const b, Point const c, Point const point);

int main() {
    // Define triangle vertices
    Point a(Fixed(0), Fixed(0));
    Point b(Fixed(10), Fixed(0));
    Point c(Fixed(5), Fixed(10));

    // Points to test
    Point inside(Fixed(5), Fixed(5));
    Point outside(Fixed(15), Fixed(5));
    Point onEdge(Fixed(5), Fixed(0));
    Point vertex(Fixed(0), Fixed(0));
    Point farOutside(Fixed(-10), Fixed(-10));

    // Test if points are inside the triangle
    std::cout << "Point (5, 5) is inside triangle: " << (bsp(a, b, c, inside) ? "Yes" : "No") << std::endl;
    std::cout << "Point (15, 5) is inside triangle: " << (bsp(a, b, c, outside) ? "Yes" : "No") << std::endl;
    std::cout << "Point (5, 0) is inside triangle: " << (bsp(a, b, c, onEdge) ? "Yes" : "No") << std::endl;
    std::cout << "Point (0, 0) is inside triangle: " << (bsp(a, b, c, vertex) ? "Yes" : "No") << std::endl;
    std::cout << "Point (-10, -10) is inside triangle: " << (bsp(a, b, c, farOutside) ? "Yes" : "No") << std::endl;

    return 0;
}