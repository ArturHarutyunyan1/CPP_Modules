#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(): ClapTrap("default_clap_trap")
{
    std::cout << "DiamondTrap: Default was created" << std::endl;
	this->_name = "default";
	this->_hitPoints = FragTrap::_hitPoints;
    this->_energyPoints = ScavTrap::_energyPoints;
    this->_attackDamage = FragTrap::_attackDamage;
}

DiamondTrap::DiamondTrap(const std::string &name) : ClapTrap(name + "_clap_trap")
{
    std::cout << "DiamondTrap: " << name << " was created" << std::endl;
    this->_name = name;
	this->_hitPoints = FragTrap::_hitPoints;
    this->_energyPoints = ScavTrap::_energyPoints;
    this->_attackDamage = FragTrap::_attackDamage;
}

DiamondTrap::DiamondTrap(const DiamondTrap &copy) : ClapTrap(copy)
{
    std::cout << "DiamondTrap: " << copy._name << " was copied" << std::endl;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &copy)
{
    std::cout << "DiamondTrap: Assignment operator for " << copy._name << " was called" << std::endl;
    if (this != &copy)
    {
        this->_name = copy._name;
        this->_hitPoints = copy._hitPoints;
        this->_energyPoints = copy._energyPoints;
        this->_attackDamage = copy._attackDamage;
    }
    return (*this);
}

DiamondTrap::~DiamondTrap(void)
{
    std::cout << "DiamondTrap: " << this->_name << " was destroyed :((" << std::endl;
}

void DiamondTrap::attack(const std::string &target)
{
    ClapTrap::attack(target);
}

void DiamondTrap::whoAmI(void)
{
    std::cout << "My DiamondTrap name is " << this->_name << " but my ClapTrap name is " << ClapTrap::_name << std::endl;
}