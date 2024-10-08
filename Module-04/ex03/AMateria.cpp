#include "AMateria.hpp"

AMateria::AMateria() : _type("default")
{
    std::cout << "AMateria default constructor called" << std::endl;
}

AMateria::AMateria(std::string const & type) : _type(type)
{
    std::cout << "AMateria constructor for " << type << " called" << std::endl;
}

AMateria::AMateria(const AMateria &copy) : _type(copy._type)
{
    std::cout << "AMateria copy constructor called for " << copy._type << std::endl;
}

AMateria &AMateria::operator=(const AMateria &copy)
{
    if (this != &copy)
    {
        this->_type = copy.getType();
    }
    return (*this);
}

AMateria::~AMateria(void)
{
    std::cout << "AMateria destructor called" << std::endl;
}

std::string const &AMateria::getType(void) const
{
    return (this->_type);
}

void AMateria::use(ICharacter &target)
{
    std::cout << "* AMateria use was called for " << target.getName() << " *" << std::endl;
}