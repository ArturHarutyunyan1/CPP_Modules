#ifndef INTERN_HPP
#define INTERN_HPP

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern
{
    public:
        Intern();
        Intern(const Intern &copy);
        Intern &operator=(const Intern &copy);
        ~Intern();
        std::string ft_toupper(std::string str);
        AForm *makeForm(std::string name, std::string target);
};

#endif