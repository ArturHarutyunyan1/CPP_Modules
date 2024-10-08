#include "Animal.hpp"

Animal::Animal() : type("Default")
{
    std::cout << "Animal Default constructor called" << std::endl;
}

Animal::Animal(const Animal &copy) : type(copy.type)
{
    std::cout << "Animal Copy constructor called" << std::endl;
}

Animal &Animal::operator=(const Animal &copy)
{
    std::cout << "Animal Copy assignment called" << std::endl;
    if (this != &copy)
        this->type = copy.type;
    return (*this);
}

Animal::~Animal(void)
{
    std::cout << "Animal was destroyed :((" << std::endl;
}

std::string Animal::getType(void) const
{
    return (this->type);
}
