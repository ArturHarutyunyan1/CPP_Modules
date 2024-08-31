#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _name("Default"), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
    std::cout << "ClapTrap: Default constructor was called" << std::endl;
}

ClapTrap::ClapTrap(const std::string &name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
    std::cout << "ClapTrap: " << name << " was created" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &copy) : _name(copy._name), _hitPoints(copy._hitPoints), _energyPoints(copy._energyPoints), _attackDamage(copy._attackDamage)
{
    std::cout << "ClapTrap: " << copy._name << " was copied" << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &copy)
{
    std::cout << "ClapTrap: Assignment operator for " << copy._name << " was called" << std::endl;
    if (this != &copy)
    {
        this->_name = copy.getName();
        this->_hitPoints = copy.getHitPoints();
        this->_energyPoints = copy.getEnergyPoints();
        this->_attackDamage = copy.getAttackDamage();
    }
    return (*this);
}

ClapTrap::~ClapTrap(void)
{
    std::cout << "ClapTrap: " << this->_name << " was destroyed :((" << std::endl;
}

std::string ClapTrap::getName(void) const
{
    return (this->_name);
}

unsigned int ClapTrap::getHitPoints(void) const
{
    return (this->_hitPoints);
}

unsigned int ClapTrap::getEnergyPoints(void) const
{
    return (this->_energyPoints);
}

unsigned int ClapTrap::getAttackDamage(void) const
{
    return (this->_attackDamage);
}

void ClapTrap::setName(const std::string &name)
{
    this->_name = name;
}

void ClapTrap::setHitPoints(const unsigned int hitPoints)
{
    this->_hitPoints = hitPoints;
}

void ClapTrap::setEnergyPoints(const unsigned int energyPoints)
{
    this->_energyPoints = energyPoints;
}

void ClapTrap::setAttackDamage(const unsigned int attackDamage)
{
    this->_attackDamage = attackDamage;
}

void ClapTrap::attack(const std::string &target)
{
    if (this->_hitPoints > 0 && this->_energyPoints > 0)
    {
        std::cout << "ClapTrap: " << this->_name << " attacks " << target << " causing to lose " << this->_attackDamage << " point(s) of damage" << std::endl;
        this->_energyPoints--;
    }
    else if (this->_hitPoints == 0)
        std::cout << "ClapTrap: " << this->_name << " was unable to attack " << target << " because he's out of hit points" << std::endl;
    else
        std::cout << "ClapTrap: " << this->_name << " was unable to attack " << target << " because he's out of energy points" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (this->_hitPoints > amount)
    {
        std::cout << "ClapTrap: " << this->_name << " takes " << amount << " point(s) of damage" << std::endl;
        this->_hitPoints -= amount;
    }
    else
        this->_hitPoints = 0;
    if (this->_hitPoints == 0)
        std::cout << "ClapTrap: Stop beating " << this->_name << " he's dead :(" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (this->_energyPoints > 0 && this->_hitPoints > 0)
    {
        std::cout << "ClapTrap: " << this->_name << " repaired itself and gained " << amount << " of hit point(s) back" << std::endl;
        this->_hitPoints += amount;
        this->_energyPoints--;
    }
    else if (this->_hitPoints == 0)
        std::cout << "ClapTrap: " << this->_name << " can't repair itself because he's dead :(" << std::endl;
    else
        std::cout << "ClapTrap: " << this->_name << " can't repair itself because he's out of energy points" << std::endl;
}