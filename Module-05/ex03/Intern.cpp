#include "Intern.hpp"

Intern::Intern()
{
    std::cout << "Intern constructor" << std::endl;
}

Intern::Intern(const Intern &copy)
{
    (void)copy;
    std::cout << "Intern copy constructor" << std::endl;
}

Intern &Intern::operator=(const Intern &copy)
{
    std::cout << "Intern copy assignment" << std::endl;
    (void)copy;
    return (*this);
}

Intern::~Intern()
{
    std::cout << "Intern was destroyed ::((" << std::endl;
}

std::string Intern::ft_toupper(std::string str)
{
    for (int i = 0; str[i]; i++)
    {
        if (str[i] >= 'a' && str[i] <= 'z')
            str[i] = (char)std::toupper(str[i]);
    }
    return (str);
}

AForm *Intern::makeForm(std::string name, std::string target)
{
    int i = 0;
    std::string forms[] = {"Presidential Pardon", "Robotomy Request", "Shrubbery Creation"};

    for (i = 0; i < 3; i++)
    {
        if (ft_toupper(forms[i]) == ft_toupper(name))
            break;
    }
    switch (i)
    {
    case 0:
        return (new PresidentialPardonForm(target));
    case 1:
        return (new RobotomyRequestForm(target));
    case 2:
        return (new ShrubberyCreationForm(target));
    default:
        std::cout << "Intern couldn't create form " << name << ".\nAvailable forms are\n1 - PresidentialPardonForm\n2 - RobotomyRequestForm\n3 - ShrubberyCreationForm" << std::endl;
        return (NULL);
    }
}