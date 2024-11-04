#include "Span.hpp"

int main() {
    srand(time(0));
    try {
        // Test case 1: Basic functionality with 5 elements
        Span sp1(5);
        sp1.addNumber(6);
        sp1.addNumber(3);
        sp1.addNumber(17);
        sp1.addNumber(9);
        sp1.addNumber(11);
        
        std::cout << "Shortest span: " << sp1.shortestSpan() << std::endl; // Expected output: 2
        std::cout << "Longest span: " << sp1.longestSpan() << std::endl;   // Expected output: 14

        // Test case 2: Attempting to add more than N elements
        try {
            sp1.addNumber(20); // Should throw an exception
        } catch (const std::exception &e) {
            std::cout << "Exception: " << e.what() << std::endl; // Expect a message indicating capacity reached
        }

        // Test case 3: Testing with fewer than 2 numbers
        Span sp2(2);
        try {
            std::cout << sp2.shortestSpan() << std::endl; // Should throw an exception
        } catch (const std::exception &e) {
            std::cout << "Exception: " << e.what() << std::endl; // Expect a message indicating not enough elements
        }

        // Test case 4: Adding only 1 number
        sp2.addNumber(5);
        try {
            std::cout << sp2.shortestSpan() << std::endl; // Should throw an exception
        } catch (const std::exception &e) {
            std::cout << "Exception: " << e.what() << std::endl; // Expect a message indicating not enough elements
        }

        // Test case 5: Filling Span with a range of iterators
        Span sp3(10000);
        std::vector<int> numbers;
        for (int i = 0; i < 10; ++i) {
            numbers.push_back(rand() % 999999 + 1); // Random numbers between 0 and 99999
        }
        sp3.addRange(numbers.begin(), numbers.end());
        
        // Test spans
        std::cout << "Shortest span after filling with 10000 random numbers: " << sp3.shortestSpan() << std::endl;
        std::cout << "Longest span after filling with 10000 random numbers: " << sp3.longestSpan() << std::endl;

        // Test case 6: Edge case with negative values
        Span sp4(3);
        sp4.addNumber(-5);
        sp4.addNumber(-1);
        sp4.addNumber(-8);
        
        std::cout << "Shortest span with negative values: " << sp4.shortestSpan() << std::endl; // Expected output: 2
        std::cout << "Longest span with negative values: " << sp4.longestSpan() << std::endl;   // Expected output: 7

    } catch (const std::exception &e) {
        std::cout << "Unhandled exception: " << e.what() << std::endl;
    }
    
    return 0;
}
