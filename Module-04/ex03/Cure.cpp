#include "Cure.hpp"

Cure::Cure() : AMateria("cure")
{
    std::cout << "Cure constructor called" << std::endl;
}

Cure::Cure(const Cure &copy) : AMateria(copy)
{
    std::cout << "Copy constructor for Cure called" << std::endl;
}

Cure &Cure::operator=(const Cure &copy)
{
    std::cout << "Copy assignment for Cure called" << std::endl;

    if (this != &copy)
    {
        AMateria::operator=(copy);
    }
    return (*this);
}

AMateria *Cure::clone(void) const
{
    return (new Cure());
}

Cure::~Cure(void)
{
    std::cout << "Cure was destroyed" << std::endl;
}

void Cure::use(ICharacter &target)
{
    std::cout << "Cure: * heals " << target.getName() << "'s wounds *" << std::endl;
}