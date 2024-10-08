#include "Dog.hpp"

Dog::Dog()
{
    std::cout << "Dog constructor called" << std::endl;
    this->type = "Dog";
    this->_brain = new Brain();
    if (!this->_brain)
    {
        std::cout << "Allocation failure" << std::endl;
        exit(1);
    }
}

Dog::Dog(const Dog &copy) : Animal(copy)
{
    std::cout << "Dog Copy constructor called" << std::endl;
    _brain = new Brain(*copy._brain);
}

Dog &Dog::operator=(const Dog &copy)
{
    std::cout << "Dog copy assignment called" << std::endl;

    if (this != &copy)
    {
        delete this->_brain;
        this->_brain = new Brain();
        if (!this->_brain)
        {
            std::cout << "Allocation failure" << std::endl;
            exit(1);
        }
        *this->_brain = *copy._brain;
        this->type = copy.type;
    }
    return (*this);
}

Dog::~Dog(void)
{
    delete (this->_brain);
    std::cout << "Dog was destroyed :((" << std::endl;
}

void Dog::makeSound(void) const
{
    std::cout << this->getType() << " says: WOOOF" << std::endl;
}

void Dog::getIdeas(void) const
{
    for (int i = 0; i < 4; i++)
    {
        std::cout << "Dog idea " << i << " " << this->_brain->getIdea(i) << std::endl;
    }
}

void Dog::setIdea(size_t i, std::string idea) const
{
    this->_brain->setIdea(i, idea);
}