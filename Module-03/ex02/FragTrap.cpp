#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
    std::cout << "FragTrap: Default was created" << std::endl;
    this->_hitPoints = 100;
    this->_energyPoints = 100;
    this->_attackDamage = 30;
}

FragTrap::FragTrap(const std::string &name) : ClapTrap(name)
{
    std::cout << "FragTrap: " << name << "was created" << std::endl;
    this->_name = name;
    this->_hitPoints = 100;
    this->_energyPoints = 100;
    this->_attackDamage = 30;
}

FragTrap::FragTrap(const FragTrap &copy) : ClapTrap(copy)
{
    std::cout << "FragTrap: " << copy._name << " was copied" << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &copy)
{
    if (this != &copy)
    {
        this->_name = copy._name;
        this->_hitPoints = copy._hitPoints;
        this->_energyPoints = copy._energyPoints;
        this->_attackDamage = copy._attackDamage;
    }
    return (*this);
}

FragTrap::~FragTrap(void)
{
    std::cout << "FragTrap: " << this->_name << " was destroyed :((" << std::endl;
}

void FragTrap::highFivesGuys(void)
{
    std::cout << "FragTrap: " << this->_name << " Want's to high five? Awesome! high five 🚀 If you’re ready for more, just let me know!" << std::endl;
}