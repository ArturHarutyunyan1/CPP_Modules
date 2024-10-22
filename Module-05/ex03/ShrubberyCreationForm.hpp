#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include <fstream>

class Bureaucrat;
class AForm;

class ShrubberyCreationForm : public AForm
{
    private:
        std::string _target;
        static std::string tree;
    public:
        ShrubberyCreationForm();
        ShrubberyCreationForm(std::string target);
        ShrubberyCreationForm(const ShrubberyCreationForm &copy);
        ShrubberyCreationForm &operator=(const ShrubberyCreationForm &copy);
        ~ShrubberyCreationForm();
        void execute(Bureaucrat const &excecutor) const;
};

#endif