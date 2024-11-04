#ifndef MUTANTSTACK
#define MUTANTSTACK

#include <iostream>
#include <exception>
#include <stack>

template <typename T>
class MutantStack : public std::stack<T>
{
    public:
        typedef typename std::deque<T>::iterator iterator;
        typedef typename std::deque<T>::const_iterator const_iterator;

        MutantStack()
        {
            std::cout << "Default constructor" << std::endl;
        }
        MutantStack(const MutantStack &copy) : std::stack<T>(copy)
        {
            std::cout << "Copy constructor" << std::endl;
        }
        MutantStack &operator=(const MutantStack &copy)
        {
            std::cout << "Copy assignment" << std::endl;
            if (this != &copy)
            {
                std::stack<T>::operator=(copy);
            }
            return (*this);
        }
        ~MutantStack()
        {
            std::cout << "Mutant stack destroyed :((" << std::endl;
        }
        iterator begin()
        {
            return (this->c.begin());
        }
        iterator end()
        {
            return (this->c.end());
        }
        const_iterator begin() const
        {
            return (this->c.begin());
        }
        const_iterator end() const
        {
            return (this->c.end());
        }
};

#endif