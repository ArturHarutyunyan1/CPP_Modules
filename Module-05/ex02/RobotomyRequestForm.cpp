#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("Default", false, 72, 45), _target("Default")
{
    std::cout << "Default constructor" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm(target, false, 72, 45), _target(target)
{
    std::cout << "Constructor for " << target << " called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copy) : AForm(copy), _target(copy._target)
{
    std::cout << "Robotomy copy constructor called" << std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &copy)
{
    std::cout << "Robotomy copy assignment called" << std::endl;
    if (this != &copy)
    {
        AForm::operator=(copy);
        _target = copy._target;
    }
    return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm()
{
    std::cout << "Robotomy destroyed ::((" << std::endl;
}

void RobotomyRequestForm::execute(const Bureaucrat &executor) const
{
    AForm::execute(executor);
    std::cout << "DRrrrrrrrrRRRrrrRRRRRrrrRRRRRrrrRRR" << std::endl;
    if ((std::rand() % 2) == 0)
        std::cout << _target << " has been robotomized successfully" << std::endl;
    else
        std::cout << "Robotomy failed for " << _target << std::endl;
}