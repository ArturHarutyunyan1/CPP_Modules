#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
    std::cout << "ScavTrap: Default was created" << std::endl;
    this->_hitPoints = 100;
    this->_energyPoints = 50;
    this->_attackDamage = 20;
    this->_guard = false;
}

ScavTrap::ScavTrap(const std::string &name) : ClapTrap(name)
{
    std::cout << "ScavTrap: " << name << " was created" << std::endl;
    this->_name = name;
    this->_hitPoints = 100;
    this->_energyPoints = 50;
    this->_attackDamage = 20;
    this->_guard = false;
}

ScavTrap::ScavTrap(const ScavTrap &copy) : ClapTrap(copy)
{
    std::cout << "ScavTrap: " << copy._name << " was copied" << std::endl;
    this->_guard = false;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &copy)
{
    std::cout << "ScavTrap: Assignment operator for " << copy._name << " was called" << std::endl;
    if (this != &copy)
    {
        this->_name = copy._name;
        this->_hitPoints = copy._hitPoints;
        this->_energyPoints = copy._energyPoints;
        this->_attackDamage = copy._attackDamage;
        this->_guard = copy._guard;
    }
    return (*this);
}

ScavTrap::~ScavTrap(void)
{
    std::cout << "ScavTrap: " << this->_name << " was destroyed :(" << std::endl;
}

void ScavTrap::attack(const std::string &target)
{
    if (this->_hitPoints > 0 && this->_energyPoints > 0)
    {
        std::cout << "ScavTrap: " << this->_name << " attacks " << target << " causing to lose " << this->_attackDamage << " point(s) of damage" << std::endl;
        this->_energyPoints--;
    }
    else if (this->_hitPoints == 0)
        std::cout << "ScavTrap: " << this->_name << " was unable to attack " << target << " because he's out of hit points" << std::endl;
    else
        std::cout << "ScavTrap: " << this->_name << " was unable to attack " << target << " because he's out of energy points" << std::endl;
}

void ScavTrap::guardGate(void)
{
    if (!this->_guard)
    {
        std::cout << "ScavTrap: " << this->_name << " is now in Gate Keeper mode" << std::endl;
        this->_guard = true;
        return;
    }
    else
    {
        std::cout << "ScavTrap: " << this->_name << " is already in Gate Keeper mode" << std::endl;
        return;
    }

}