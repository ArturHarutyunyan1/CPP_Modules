#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"


class Dog : public Animal
{
    private:
        Brain *_brain;
    public:
        Dog();
        Dog(const Dog &copy);
        Dog &operator=(const Dog &copy);
        virtual ~Dog();
        void makeSound(void) const;
        void getIdeas(void) const;
        void setIdea(size_t i, std::string idea) const;
};

#endif