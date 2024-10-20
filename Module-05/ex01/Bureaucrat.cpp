#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("Default"), _grade(150)
{
    std::cout << "Default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string name, int grade) : _name(name)
{
    std::cout << "Parameterized constructor for " << this->getName() << " called" << std::endl;
    if (grade > 150)
        throw Bureaucrat::GradeTooLowException();
    else if (grade < 1)
        throw Bureaucrat::GradeTooHighException();
    else
        this->_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &copy) : _name(copy._name), _grade(copy._grade)
{
    std::cout << "Copy constructor for " << this->getName() << " called" << std::endl;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &copy)
{
    std::cout << "Copy assignment for " << this->getName() << " called" << std::endl;

    if (this != &copy)
        this->_grade = this->getGrade();
    return (*this);
}

Bureaucrat::~Bureaucrat()
{
    std::cout << "Destructor for " << this->getName() << " called" << std::endl;
}

std::string Bureaucrat::getName() const
{
    return (this->_name);
}

int Bureaucrat::getGrade() const
{
    return (this->_grade);
}

void Bureaucrat::incrementGrade()
{
    std::cout << "Incrementing grade for " << this->getName() << std::endl;
    if (--this->_grade < 1)
        throw Bureaucrat::GradeTooHighException();
}

void Bureaucrat::decrementGrade()
{
    std::cout << "Decrementing grade for " << this->getName() << std::endl;
    if (++this->_grade > 150)
        throw Bureaucrat::GradeTooLowException();
}

void Bureaucrat::signForm(Form &form)
{
    try
    {
        form.beSigned(*this);
        std::cout << this->getName() << " signed " << form.getName() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cout << this->getName() << " couldn't sign " << form.getName() << " because " << e.what() << std::endl;
    }
    
}

const char *Bureaucrat::GradeTooHighException::what(void) const throw()
{
    return ("Grade is too high!");
}

const char *Bureaucrat::GradeTooLowException::what(void) const throw()
{
    return ("Grade is too low!");
}

std::ostream &operator<<(std::ostream &o, Bureaucrat &Bureaucrat)
{
    o << Bureaucrat.getName() << ", bureaucrat grade " << Bureaucrat.getGrade() << std::endl;
    return (o);
}