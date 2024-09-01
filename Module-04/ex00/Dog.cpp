#include "Dog.hpp"

Dog::Dog()
{
    std::cout << "Dog constructor called" << std::endl;
    this->type = "Dog";
}

Dog::Dog(const Dog &copy)
{
    std::cout << "Dog Copy constructor called" << std::endl;
    *this = copy;
}

Dog &Dog::operator=(const Dog &copy)
{
    std::cout << "Dog copy assignment called" << std::endl;

    if (this != &copy)
        this->type = copy.type;
    return (*this);
}

Dog::~Dog(void)
{
    std::cout << "Dog was destroyed :((" << std::endl;
}

void Dog::makeSound(void) const
{
    std::cout << this->getType() << " says: WOOOF" << std::endl;
}