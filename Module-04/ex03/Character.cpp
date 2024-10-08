#include "Character.hpp"

Character::Character() : _name("Default")
{
    std::cout << "Default constructor called" << std::endl;
    for (int i = 0; i < 4; i++)
        _inventory[i] = NULL;
}

Character::Character(const std::string &name) : _name(name)
{
    std::cout << "Constructor called" << std::endl;
    for (int i = 0; i < 4; i++)
        _inventory[i] = NULL;
}

Character::Character(const Character &copy)
{
    std::cout << "Copy constructor called" << std::endl;
    _name = copy._name;
    for (int i = 0; i < 4; i++)
    {
        if (copy._inventory[i])
            _inventory[i] = copy._inventory[i]->clone();
        else
            _inventory[i] = NULL;
    }
}

Character &Character::operator=(const Character &copy)
{
    std::cout << "Copy assignment called" << std::endl;
    if (this != &copy)
    {
        _name = copy._name;
        for (int i = 0; i < 4; i++)
        {
            if (_inventory[i])
                delete _inventory[i];
            if (copy._inventory[i])
                _inventory[i] = copy._inventory[i]->clone();
            else
                _inventory[i] = NULL;
        }
    }
    return (*this);
}

Character::~Character(void)
{
    std::cout << "Character destroyed" << std::endl;
    for (int i = 0; i < 4; i++)
    {
        if (_inventory[i])
            delete _inventory[i];
    }
}

std::string const &Character::getName(void) const
{
    return (_name);
}

void Character::equip(AMateria *materia)
{
    for (int i = 0; i < 4; i++)
    {
        if (!_inventory[i])
        {
            _inventory[i] = materia;
            break;
        }
    }
}

void Character::unequip(int idx)
{
    if (idx >= 0 && idx < 4 && _inventory[idx])
        _inventory[idx] = NULL;
}

void Character::use(int idx, ICharacter &target)
{
        if (idx >= 0 && idx < 4 && _inventory[idx])
        _inventory[idx]->use(target);
}