#include "Fixed.hpp"

int main() {
    Fixed a(42);          // Fixed-point representation of 42
    Fixed b(21.5f);      // Fixed-point representation of 21.5
    Fixed c(42.0f);      // Fixed-point representation of 42.0
    Fixed d(21.5f);      // Another Fixed with value 21.5

    // Testing Comparison Operators
    std::cout << "a - " << a << "\nb - " << b << "\nc - " << c << "\nd - " << d << std::endl;
    std::cout << "Testing Comparison Operators:" << std::endl;
    std::cout << (a > b) << " (a > b)" << std::endl; // Expect 1 (true)
    std::cout << (a < b) << " (a < b)" << std::endl; // Expect 0 (false)
    std::cout << (a >= c) << " (a >= c)" << std::endl; // Expect 1 (true)
    std::cout << (a <= c) << " (a <= c)" << std::endl; // Expect 1 (true)
    std::cout << (a == c) << " (a == c)" << std::endl; // Expect 1 (true)
    std::cout << (a != b) << " (a != b)" << std::endl; // Expect 1 (true)

    // Testing Arithmetic Operators
    std::cout << "\nTesting Arithmetic Operators:" << std::endl;
    Fixed sum = a + b;    // a + b
    Fixed difference = a - b; // a - b
    Fixed product = a * b; // a * b
    Fixed quotient = a / b; // a / b

    std::cout << "a + b = " << sum << std::endl;       // Expect 63.5
    std::cout << "a - b = " << difference << std::endl; // Expect 20.5
    std::cout << "a * b = " << product << std::endl;    // Expect 903.0
    std::cout << "a / b = " << quotient << std::endl;    // Expect ~1.953 (or similar)

    // Testing Increment/Decrement Operators
    std::cout << "\nTesting Increment/Decrement Operators:" << std::endl;
    std::cout << "Initial a: " << a << std::endl; // Expect 42
    std::cout << "a++: " << a++ << std::endl;      // Expect 42 (postfix increment)
    std::cout << "After a++, a: " << a << std::endl; // Expect 43
    std::cout << "--a: " << --a << std::endl;      // Expect 42 (prefix decrement)
    std::cout << "++a: " << ++a << std::endl;      // Expect 43 (prefix increment)

    // Testing Postfix Decrement
    std::cout << "a--: " << a-- << std::endl;      // Expect 43 (postfix decrement)
    std::cout << "After a--, a: " << a << std::endl; // Expect 42

    return 0;
}