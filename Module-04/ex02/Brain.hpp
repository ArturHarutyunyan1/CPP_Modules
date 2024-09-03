#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>
#include <string>

class Brain
{
    private:
        std::string _ideas[100];
    public:
        Brain();
        Brain(const Brain &copy);
        Brain &operator=(const Brain &copy);
        virtual ~Brain();
        const std::string getIdea(size_t i);
        void setIdea(size_t i, std::string idea);
};

#endif