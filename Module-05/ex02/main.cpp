#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {
    try {
        // Bureaucrats with different grades
        Bureaucrat highGradeBureaucrat("Alice", 1);     // Grade 1 (very high)
        Bureaucrat midGradeBureaucrat("Bob", 100);      // Grade 100 (mid-level)
        Bureaucrat lowGradeBureaucrat("Charlie", 150);  // Grade 150 (very low)

        // Forms
        ShrubberyCreationForm shrubberyForm("home");
        RobotomyRequestForm robotomyForm("target");
        PresidentialPardonForm pardonForm("criminal");

        // Test 1: Successfully sign and execute ShrubberyCreationForm
        std::cout << "Test 1: Shrubbery Creation (Success)\n";
        midGradeBureaucrat.signForm(shrubberyForm);
        midGradeBureaucrat.executeForm(shrubberyForm);  // Mid-level bureaucrat should pass both sign and execute
        std::cout << std::endl;

        // Test 2: Failed execution of RobotomyRequestForm due to insufficient grade
        std::cout << "Test 2: Robotomy Request (Failed Execution)\n";
        midGradeBureaucrat.signForm(robotomyForm);
        lowGradeBureaucrat.executeForm(robotomyForm);  // Low-grade bureaucrat cannot execute
        std::cout << std::endl;

        // Test 3: Successfully sign and execute RobotomyRequestForm with high-grade bureaucrat
        std::cout << "Test 3: Robotomy Request (Success)\n";
        highGradeBureaucrat.signForm(robotomyForm);
        highGradeBureaucrat.executeForm(robotomyForm);  // High-grade bureaucrat executes successfully
        std::cout << std::endl;

        // Test 4: Try to execute an unsigned PresidentialPardonForm
        std::cout << "Test 4: Presidential Pardon (Unsigned Form)\n";
        highGradeBureaucrat.executeForm(pardonForm);  // Form not signed, should throw an error
        std::cout << std::endl;

        // Test 5: Successfully sign and execute PresidentialPardonForm
        std::cout << "Test 5: Presidential Pardon (Success)\n";
        highGradeBureaucrat.signForm(pardonForm);
        highGradeBureaucrat.executeForm(pardonForm);  // High-grade bureaucrat executes successfully
        std::cout << std::endl;

    } catch (std::exception &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}