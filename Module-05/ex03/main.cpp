#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {
    try {
        // Bureaucrats for signing and executing forms
        Bureaucrat boss("The Boss", 1);
        Bureaucrat employee("Average Joe", 75);
        
        // Intern that will create the forms
        Intern someRandomIntern;

        // Test 1: Create and execute ShrubberyCreationForm
        std::cout << "Test 1: Shrubbery Creation\n";
        AForm* shrubForm = someRandomIntern.makeForm("shrubbery creation", "Home");
        if (shrubForm) {
            boss.signForm(*shrubForm);
            boss.executeForm(*shrubForm);
        }
        std::cout << std::endl;

        // Test 2: Create and execute RobotomyRequestForm
        std::cout << "Test 2: Robotomy Request\n";
        AForm* robotForm = someRandomIntern.makeForm("robotomy request", "Bender");
        if (robotForm) {
            employee.signForm(*robotForm);
            boss.executeForm(*robotForm);  // Boss has high enough grade to execute
        }
        std::cout << std::endl;

        // Test 3: Create and execute PresidentialPardonForm
        std::cout << "Test 3: Presidential Pardon\n";
        AForm* pardonForm = someRandomIntern.makeForm("presidential pardon", "Criminal");
        if (pardonForm) {
            boss.signForm(*pardonForm);
            boss.executeForm(*pardonForm);  // Boss has high enough grade to sign and execute
        }
        std::cout << std::endl;

        // Test 4: Try to create a form that doesn't exist
        std::cout << "Test 4: Unknown Form\n";
        AForm* unknownForm = someRandomIntern.makeForm("unknown form", "Nobody");
        if (unknownForm == nullptr) {
            std::cout << "Failed to create unknown form." << std::endl;
        }
        std::cout << std::endl;

        // Clean up dynamically allocated memory
        delete shrubForm;
        delete robotForm;
        delete pardonForm;

    } catch (std::exception &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}