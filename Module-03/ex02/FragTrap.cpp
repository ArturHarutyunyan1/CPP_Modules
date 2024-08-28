#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
    std::cout << "FragTrap default constructor called" << std::endl;
    this->_hitPoint = 100;
    this->_energyPoint = 100;
    this->_attackDamage = 30;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
    std::cout << "FragTrap constructor for " << name << " called" << std::endl;
    this->_hitPoint = 100;
    this->_energyPoint = 100;
    this->_attackDamage = 30;
}

FragTrap::FragTrap(const FragTrap &cp) : ClapTrap(cp)
{
    std::cout << "FragTrap Copy constructor called" << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &cp)
{
    std::cout << "FragTrap Copy assignment constructor for " << this->_name << " called" << std::endl;
    this->_name = cp._name;
    this->_hitPoint = cp._hitPoint;
    this->_energyPoint = cp._energyPoint;
    this->_attackDamage = cp._attackDamage;
    return (*this);
}

FragTrap::~FragTrap(void)
{
    std::cout << "Destructor for " << this->_name << " called" << std::endl;
}

void FragTrap::highFivesGuys(void)
{
    std::cout << "You wan't to high five? Awesome! high five 🚀 If you’re ready for more, just let me know!" << std::endl;
}