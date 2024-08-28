#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
    std::cout << "ScavTrap default constructor called" << std::endl;
    this->_hitPoint = 100;
    this->_energyPoint = 50;
    this->_attackDamage = 20;
    this->_gate = false;
}

ScavTrap::ScavTrap(const ScavTrap &cp): ClapTrap(cp)
{
    this->_gate = cp._gate;
    std::cout << "ScavTrap Copy constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
    this->_hitPoint = 100;
    this->_energyPoint = 50;
    this->_attackDamage = 20;
    this->_gate = false;
    std::cout << "ScavTrap constructor for " << name << " called" << std::endl; 
}

ScavTrap::~ScavTrap(void)
{
    std::cout << "ScavTrap " << this->_name << " was destroyed" << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &st)
{
    std::cout << "Copy assignment operator called for" << this->_name << std::endl;
    this->_name = st._name;
    this->_hitPoint = st._hitPoint;
    this->_energyPoint = st._energyPoint;
    this->_attackDamage = st._attackDamage;
    this->_gate = st._gate;
    return (*this);
}

void ScavTrap::attack(const std::string& target)
{
    if (this->_energyPoint > 0 && this->_hitPoint > 0)
    {
        std::cout << "ClapTrap " << _name << " 💥 attacks " << target << ", causing " << _attackDamage << " points of damage!" << std::endl;
        this->_energyPoint--;
    }
    else if (this->_energyPoint == 0)
        std::cout << "ClapTrap " << _name << " is not able to attack " << target << " because he doesn't have enough energy points." << std::endl;
    else
        std::cout << "ClapTrap " << _name << " is not able to attack " << target << " because he doesn't have enough hit points." << std::endl;
}

void ScavTrap::guardGate(void)
{
    if (this->_gate == false)
    {
        this->_gate = true;
        std::cout << "ScavTrap " << this->_name <<  " is in Gate Guard mode now" << std::endl;
    }
    else
        std::cout << "ScavTrap " << this->_name <<  " is already in Gate Guard mode" << std::endl;
}