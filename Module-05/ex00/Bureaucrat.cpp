#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("Default"), _grade(150)
{
    std::cout << "Default constructor for " << _name << " called" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name), _grade(grade)
{
    if (grade > 150)
        throw Bureaucrat::GradeTooLowException();
    else if (grade < 1)
        throw Bureaucrat::GradeTooHighException();
    std::cout << "Default constructor for " << this->getName() << " called" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &copy) : _name(copy._name), _grade(copy._grade)
{
    std::cout << "Copy constructor for " << this->getName() << " called" << std::endl;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &copy)
{
    std::cout << "Copy assignment for " << this->getName() << " called" << std::endl;
    if (this != &copy)
        this->_grade = copy._grade;
    return (*this);
}

Bureaucrat::~Bureaucrat(void)
{
    std::cout << this->getName() << " was destroyed :(((" << std::endl;
}

std::string Bureaucrat::getName(void) const
{
    return (this->_name);
}

int Bureaucrat::getGrade(void) const
{
    return (this->_grade);
}

void Bureaucrat::setGrade(int grade)
{
    if (grade > 150)
        throw Bureaucrat::GradeTooLowException();
    else if (grade < 1)
        throw Bureaucrat::GradeTooHighException();
    else
        this->_grade = grade;
}

void Bureaucrat::incrementGrade(void)
{
    std::cout << "Incrementing grade for " << this->getName() << std::endl;
    this->setGrade(this->_grade - 1);
}

void Bureaucrat::decrementGrade(void)
{
    std::cout << "Decrementing grade for " << this->getName() << std::endl;
    this->setGrade(this->_grade + 1);
}

const char *Bureaucrat::GradeTooHighException::what(void) const throw()
{
    return ("Grade is too high !");
}

const char *Bureaucrat::GradeTooLowException::what(void) const throw()
{
    return ("Grade is too low !");
}

std::ostream &operator<<(std::ostream &o, Bureaucrat &b)
{
    o << b.getName() << ", bureaucrat grade " << b.getGrade() << std::endl;
    return (o);
}