#ifndef WRONGCat_HPP
#define WRONGCat_HPP

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
    public:
        WrongCat();
        WrongCat(const WrongCat &copy);
        WrongCat &operator=(const WrongCat &copy);
        virtual ~WrongCat();
        void makeSound(void) const;
};

#endif