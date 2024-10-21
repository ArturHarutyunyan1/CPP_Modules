#include "AForm.hpp"

AForm::AForm() : _name("Default"), _isSigned(false), _sign(75), _exec(75)
{
    std::cout << "Default constructor called" << std::endl;
}

AForm::AForm(const std::string name, bool isSigned, const int sign, const int exec) : _name(name), _isSigned(isSigned), _sign(sign), _exec(exec)
{
    std::cout << "Constructor for " << name << " called" << std::endl;
    if (sign < 1 || exec < 1)
        throw AForm::GradeTooHighException();
    else if (sign > 150 || exec > 150)
        throw AForm::GradeTooLowException();
}

AForm::AForm(const AForm &copy) : _name(copy._name), _isSigned(copy._isSigned), _sign(copy._sign), _exec(copy._exec)
{
    std::cout << "Copy constructor for " << this->getName() << " called" << std::endl;
}

AForm &AForm::operator=(const AForm &copy)
{
    std::cout << "Copy assignment for " << this->getName() << " called" << std::endl;
    if (this != &copy)
        this->_isSigned = copy._isSigned;
    return (*this);
}

AForm::~AForm()
{
    std::cout << this->getName() << " is destroyed :(((" << std::endl;
}

std::string AForm::getName() const
{
    return (this->_name);
}

bool AForm::getStatus() const
{
    return (this->_isSigned);
}

int AForm::getSign() const
{
    return (this->_sign);
}

int AForm::getExec() const
{
    return (this->_exec);
}

void AForm::setStatus(bool status)
{
    this->_isSigned = status;
}

void AForm::beSigned(Bureaucrat b)
{
    if (this->getStatus() == false)
    {
        if (b.getGrade() > this->getSign())
            throw AForm::GradeTooLowException();
        else
            this->setStatus(true);
    }
    else
        std::cout << b.getName() << " couldn't sign AForm " << this->getName() << " because it's already signed" << std::endl;
}

void AForm::execute(const Bureaucrat &executor) const
{
    if (this->getStatus() == false)
        throw AForm::UnsignedFormException();
    if (executor.getGrade() > getExec())
        throw AForm::GradeTooLowException();
}

const char *AForm::GradeTooHighException::what(void) const throw()
{
    return ("Grade is too high!");
}

const char *AForm::GradeTooLowException::what(void) const throw()
{
    return ("Grade is too low!");
}

const char *AForm::UnsignedFormException::what(void) const throw()
{
    return ("The form you're trying to sign is already signed");
}

std::ostream &operator<<(std::ostream &o, AForm &f)
{
    std::cout << "Name: " << f.getName() << "\nStatus: " << f.getStatus() << "\nGrade to sign: " << f.getSign() << "\nGrade to execute: " << f.getExec() << std::endl;
    return (o);
}