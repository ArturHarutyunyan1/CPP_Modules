#include "Bureaucrat.hpp"

int main() {
    // Test 1: Valid Bureaucrat creation
    try {
        Bureaucrat b1("Alice", 75);
        std::cout << b1 << std::endl;
    } catch (std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    // Test 2: Grade too high (exception case)
    try {
        Bureaucrat b2("Bob", 0);
        std::cout << b2 << std::endl;
    } catch (std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    // Test 3: Grade too low (exception case)
    try {
        Bureaucrat b3("Charlie", 151);
        std::cout << b3 << std::endl;
    } catch (std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    // Test 4: Increment and decrement within valid ranges
    try {
        Bureaucrat b4("David", 2);
        std::cout << "Before increment: " << b4 << std::endl;
        b4.incrementGrade();
        std::cout << "After increment: " << b4 << std::endl;

        Bureaucrat b5("Eve", 149);
        std::cout << "Before decrement: " << b5 << std::endl;
        b5.decrementGrade();
        std::cout << "After decrement: " << b5 << std::endl;
    } catch (std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    // Test 5: Increment beyond range (GradeTooHighException)
    try {
        Bureaucrat b6("Frank", 1);
        std::cout << "Before increment: " << b6 << std::endl;
        b6.incrementGrade(); // Should throw exception
        std::cout << "After increment: " << b6 << std::endl;
    } catch (std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    // Test 6: Decrement beyond range (GradeTooLowException)
    try {
        Bureaucrat b7("Grace", 150);
        std::cout << "Before decrement: " << b7 << std::endl;
        b7.decrementGrade();
        std::cout << "After decrement: " << b7 << std::endl;
    } catch (std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}