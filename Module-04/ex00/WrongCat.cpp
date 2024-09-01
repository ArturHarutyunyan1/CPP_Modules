#include "WrongCat.hpp"

WrongCat::WrongCat()
{
    std::cout << "WrongCat constructor called" << std::endl;
    this->type = "WrongCat";
}

WrongCat::WrongCat(const WrongCat &copy)
{
    std::cout << "WrongCat Copy constructor called" << std::endl;
    *this = copy;
}

WrongCat &WrongCat::operator=(const WrongCat &copy)
{
    std::cout << "WrongCat copy assignment called" << std::endl;

    if (this != &copy)
        this->type = copy.type;
    return (*this);
}

WrongCat::~WrongCat(void)
{
    std::cout << "WrongCat was destroyed :((" << std::endl;
}

void WrongCat::makeSound(void) const
{
    std::cout << this->getType() << " says: MEOW" << std::endl;
}