#include "Cat.hpp"

Cat::Cat() : Animal()
{
    std::cout << "Cat constructor called" << std::endl;
    this->type = "Cat";
    this->_brain = new Brain();
    if (!this->_brain)
    {
        std::cout << "Allocation failure" << std::endl;
        exit(1);
    }
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
    {
        this->type = copy.type;
        this->_brain = new Brain();
        if (!this->_brain)
        {
            std::cout << "Allocation failure" << std::endl;
            exit(1);
        }
        *this->_brain = *copy._brain;
    }
    return (*this);
}

Cat::~Cat(void)
{
    delete (this->_brain);
    std::cout << "Cat was destroyed :((" << std::endl;
}

void Cat::makeSound(void) const
{
    std::cout << this->getType() << " says: MEOW" << std::endl;
}

void Cat::getIdeas(void) const
{
    for (int i = 0; i < 4; i++)
    {
        std::cout << "Cat idea " << i << " " << this->_brain->getIdea(i) << std::endl;
    }
}

void Cat::setIdea(size_t i, std::string idea) const
{
    this->_brain->setIdea(i, idea);
}