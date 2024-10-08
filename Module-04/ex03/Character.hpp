#ifndef CHARACTER_HPP
#define CHARACTER_HPP


#include <iostream>
#include "ICharacter.hpp"

class Character : public ICharacter
{
    private:
        std::string _name;
        AMateria *_inventory[4];
    public:
        Character();
        Character(const std::string &name);
        Character(const Character &copy);
        Character &operator=(const Character &copy);
        virtual ~Character();
        std::string const &getName() const;
        void equip(AMateria *materia);
        void unequip(int idx);
        void use (int idx, ICharacter &target);
};

#endif