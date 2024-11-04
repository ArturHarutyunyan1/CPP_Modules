#include "Span.hpp"

int main()
{
    // Default constructor
    try
    {
        std::cout << "------------------------------------------" << std::endl;
        std::cout << "Testing default constructor" << std::endl;
        std::cout << "------------------------------------------" << std::endl;
        Span s1 = Span();
    }
    catch(const std::exception& e)
    {
        std::cerr << "Exception caught: " << e.what() << '\n';
    }
    // Default constructor out of range
    try
    {
        std::cout << "------------------------------------------" << std::endl;
        std::cout << "Default constructor out of range exception" << std::endl;
        std::cout << "------------------------------------------" << std::endl;
        Span s2 = Span();
        s2.addNumber(1);
        s2.addNumber(5);
    }
    catch(const std::exception& e)
    {
        std::cerr << "Exception caught: " << e.what() << '\n';
    }
    // Test add number
    try
    {
        std::cout << "------------------------------------------" << std::endl;
        std::cout << "Test add number function" << std::endl;
        std::cout << "------------------------------------------" << std::endl;
        Span s3 = Span(10);

        s3.addNumber(4);
        s3.addNumber(213);
        s3.addNumber(1);
        s3.addNumber(99);
        s3.addNumber(-13);
        s3.addNumber(400);
        s3.addNumber(123);
        s3.addNumber(9889);
        s3.addNumber(31251);
        s3.addNumber(411);
        std::cout << "Shortest span - " << s3.shortestSpan() << "\nLargest span - " << s3.longestSpan() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }
    // Constructor with parameters out of range
    try
    {
        std::cout << "------------------------------------------" << std::endl;
        std::cout << "Test out of range exception" << std::endl;
        std::cout << "------------------------------------------" << std::endl;
        Span s4 = Span(3);

        s4.addNumber(1);
        s4.addNumber(1);
        s4.addNumber(1);
        s4.addNumber(1);
    }
    catch(const std::exception& e)
    {
        std::cerr << "Exception caught: " << e.what() << '\n';
    }
    // Add range of numbers using array of ints
    try
    {
        std::cout << "------------------------------------------" << std::endl;
        std::cout << "Test add range of numbers with array of ints" << std::endl;
        std::cout << "------------------------------------------" << std::endl;
        Span s5 = Span(10);

        int n[] = {200, -150, 50, 20, -5, 90};
        s5.addRange(n, n + 6);
        std::cout << "Shortest span - " << s5.shortestSpan() << "\nLargest span - " << s5.longestSpan() << std::endl;        
    }
    catch(const std::exception& e)
    {
        std::cerr << "Exception caught: " << e.what() << '\n';
    }
    // Add range of numbers using array of vectors
    try
    {
        std::cout << "------------------------------------------" << std::endl;
        std::cout << "Test add range of numbers with vector" << std::endl;
        std::cout << "------------------------------------------" << std::endl;        

        Span s6 = Span(10);
        std::vector<int> nums;

        nums.push_back(-999);
        nums.push_back(-500);
        nums.push_back(50);
        nums.push_back(500);
        nums.push_back(999);

        s6.addRange(nums.begin(), nums.end());
        std::cout << "Shortest span - " << s6.shortestSpan() << "\nLargest span - " << s6.longestSpan() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << "Exception caught: " << e.what() << '\n';
    }
    
    return 0;
}
