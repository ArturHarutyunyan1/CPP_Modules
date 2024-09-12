#include "Bureaucrat.hpp"

int main()
{
    try
    {
        std::cout << "Creating bureaucrat with default constructor:" << std::endl;
        Bureaucrat b1;
        std::cout << b1 << std::endl;

        std::cout << "Creating bureaucrat with name and valid grade:" << std::endl;
        Bureaucrat b2("Alice", 42);
        std::cout << b2 << std::endl;

        std::cout << "Attempting to increment grade:" << std::endl;
        b2.incrementGrade();
        std::cout << b2 << std::endl;

        std::cout << "Attempting to decrement grade:" << std::endl;
        b2.decrementGrade();
        std::cout << b2 << std::endl;

        std::cout << "Creating bureaucrat with copy constructor:" << std::endl;
        Bureaucrat b3(b2);
        std::cout << b3 << std::endl;

        std::cout << "Testing invalid grade (too high):" << std::endl;
        Bureaucrat b4("Charlie", 0); // Should throw GradeTooHighException
        std::cout << b4 << std::endl;
    }
    catch (const Bureaucrat::GradeTooHighException &e)
    {
        std::cerr << e.what() << std::endl;
    }
    catch (const Bureaucrat::GradeTooLowException &e)
    {
        std::cerr << e.what() << std::endl;
    }

    try
    {
        std::cout << "Testing invalid grade (too low):" << std::endl;
        Bureaucrat b5("Dave", 151); // Should throw GradeTooLowException
        std::cout << b5 << std::endl;
    }
    catch (const Bureaucrat::GradeTooHighException &e)
    {
        std::cerr << e.what() << std::endl;
    }
    catch (const Bureaucrat::GradeTooLowException &e)
    {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}