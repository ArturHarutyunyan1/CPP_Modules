#include "Brain.hpp"

Brain::Brain()
{
    std::cout << "Brain constructor was called" << std::endl;
}

Brain::Brain(const Brain &copy)
{
    std::cout << "Brain copy constructor was called" << std::endl;
    for (int i = 0; i < 100; i++)
        this->_ideas[i] = copy._ideas[i];
}

Brain &Brain::operator=(const Brain &copy)
{
    if (this != &copy)
    {
        for (int i = 0; i < 100; i++)
            this->_ideas[i] = copy._ideas[i];
    }
    return (*this);
}

Brain::~Brain()
{
    std::cout << "Brain was destroyed :(((" << std::endl;
}

const std::string Brain::getIdea(size_t i)
{
    if (i < 100)
        return (this->_ideas[i]);
    else
        return ("100 ideas per brain!");
}

void Brain::setIdea(size_t i, std::string idea)
{
    if (i < 100)
        this->_ideas[i] = idea;
    else
        std::cout << "100 ideas per brain!" << std::endl;
}

