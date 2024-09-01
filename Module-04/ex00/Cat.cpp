#include "Cat.hpp"

Cat::Cat()
{
    std::cout << "Cat constructor called" << std::endl;
    this->type = "Cat";
}

Cat::Cat(const Cat &copy)
{
    std::cout << "Cat Copy constructor called" << std::endl;
    *this = copy;
}

Cat &Cat::operator=(const Cat &copy)
{
    std::cout << "Cat copy assignment called" << std::endl;

    if (this != &copy)
        this->type = copy.type;
    return (*this);
}

Cat::~Cat(void)
{
    std::cout << "Cat was destroyed :((" << std::endl;
}

void Cat::makeSound(void) const
{
    std::cout << this->getType() << " says: MEOW" << std::endl;
}