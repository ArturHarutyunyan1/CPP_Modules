#include "Ice.hpp"

Ice::Ice() : AMateria("ice")
{
    std::cout << "Ice constructor called" << std::endl;
}

Ice::Ice(const Ice &copy) : AMateria(copy)
{
    std::cout << "Copy constructor for Ice called" << std::endl;
}

Ice &Ice::operator=(const Ice &copy)
{
    std::cout << "Copy assignment for Ice called" << std::endl;

    if (this != &copy)
    {
        AMateria::operator=(copy);
    }
    return (*this);
}

AMateria *Ice::clone(void) const
{
    return (new Ice());
}

Ice::~Ice(void)
{
    std::cout << "Ice was destroyed" << std::endl;
}

void Ice::use(ICharacter &target)
{
    std::cout << "Ice: * shoots an ice bolt at " << target.getName() << " *" << std::endl;
}