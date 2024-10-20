#include "Form.hpp"

Form::Form() : _name("Default"), _isSigned(false), _sign(75), _exec(75)
{
    std::cout << "Default constructor called" << std::endl;
}

Form::Form(const std::string name, bool isSigned, const int sign, const int exec) : _name(name), _isSigned(isSigned), _sign(sign), _exec(exec)
{
    std::cout << "Constructor for " << name << " called" << std::endl;
    if (sign < 1 || exec < 1)
        throw Form::GradeTooHighException();
    else if (sign > 150 || exec > 150)
        throw Form::GradeTooLowException();
}

Form::Form(const Form &copy) : _name(copy._name), _isSigned(copy._isSigned), _sign(copy._sign), _exec(copy._exec)
{
    std::cout << "Copy constructor for " << this->getName() << " called" << std::endl;
}

Form &Form::operator=(const Form &copy)
{
    std::cout << "Copy assignment for " << this->getName() << " called" << std::endl;
    if (this != &copy)
        this->_isSigned = copy._isSigned;
    return (*this);
}

Form::~Form()
{
    std::cout << this->getName() << " is destroyed :(((" << std::endl;
}

std::string Form::getName() const
{
    return (this->_name);
}

bool Form::getStatus() const
{
    return (this->_isSigned);
}

int Form::getSign() const
{
    return (this->_sign);
}

int Form::getExec() const
{
    return (this->_exec);
}

void Form::setStatus(bool status)
{
    this->_isSigned = status;
}

void Form::beSigned(Bureaucrat b)
{
    if (this->getStatus() == false)
    {
        if (b.getGrade() > this->getSign())
            throw Form::GradeTooLowException();
        else
            this->setStatus(true);
    }
    else
        std::cout << b.getName() << " couldn't sign form " << this->getName() << " because it's already signed" << std::endl;
}

const char *Form::GradeTooHighException::what(void) const throw()
{
    return ("Grade is too high!");
}

const char *Form::GradeTooLowException::what(void) const throw()
{
    return ("Grade is too low!");
}

std::ostream &operator<<(std::ostream &o, Form &f)
{
    std::cout << "Name: " << f.getName() << "\nStatus: " << f.getStatus() << "\nGrade to sign: " << f.getSign() << "\nGrade to execute: " << f.getExec() << std::endl;
    return (o);
}