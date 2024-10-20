#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
    try {
        // Test case 1: Creating a Form with valid grade range
        Form form1("Form1", false ,3, 5);
        std::cout << "Test case 1: Creating a valid form (Form1)" << std::endl;
        std::cout << form1 << std::endl; // Print form details
        std::cout << "Expected: Unsigned form with signing grade 3 and execution grade 5." << std::endl;

        // Test case 2: Creating a Form with grade too high
        try {
            Form form2("Form2", false, 0, 5);
            std::cout << "Test case 2: Failed" << std::endl;  // Should not reach here
        } catch (const Form::GradeTooHighException &e) {
            std::cout << "Test case 2: Creating a form with grade too high (Form2)" << std::endl;
            std::cout << "Expected: GradeTooHighException caught" << std::endl;
        }

        // Test case 3: Creating a Form with grade too low
        try {
            Form form3("Form3", false, 151, 5);
            std::cout << "Test case 3: Failed" << std::endl;  // Should not reach here
        } catch (const Form::GradeTooLowException &e) {
            std::cout << "Test case 3: Creating a form with grade too low (Form3)" << std::endl;
            std::cout << "Expected: GradeTooLowException caught" << std::endl;
        }

        // Test case 4: Bureaucrat signs a form with a valid grade
        Bureaucrat bureaucrat1("Alice", 3);
        Form form4("Form4", false, 4, 5);
        std::cout << "Test case 4: Bureaucrat (Alice, grade 3) tries to sign Form4 (required grade: 4)" << std::endl;
        bureaucrat1.signForm(form4);  // Should sign successfully
        std::cout << form4 << std::endl;  // Print form details
        std::cout << "Expected: Form4 is now signed by Alice." << std::endl;

        // Test case 5: Bureaucrat tries to sign a form with too low grade
        Bureaucrat bureaucrat2("Bob", 5);
        Form form5("Form5",false ,3, 5);
        std::cout << "Test case 5: Bureaucrat (Bob, grade 5) tries to sign Form5 (required grade: 3)" << std::endl;
        bureaucrat2.signForm(form5);  // Should fail to sign
        std::cout << form5 << std::endl;  // Print form details
        std::cout << "Expected: Form5 is not signed, as Bob's grade is too low." << std::endl;
        // Test case 7: Printing form info using overloaded << operator
        std::cout << "Test case 7: Printing Form1 using overloaded << operator" << std::endl;
        std::cout << form1 << std::endl;
        std::cout << "Expected: Unsigned form with signing grade 3 and execution grade 5." << std::endl;

    } catch (const std::exception &e) {
        std::cout << "Unexpected exception: " << e.what() << std::endl;
    }

    return 0;
}