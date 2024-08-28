#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _name("Unknown"), _hitPoint(10), _energyPoint(10), _attackDamage(0)
{
    std::cout << " 🌟 Unknown created" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoint(10), _energyPoint(10), _attackDamage(0)
{
    std::cout << "🌟" << name << " Was created" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &cp) : _name(cp._name), _hitPoint(cp._hitPoint), _energyPoint(cp._energyPoint), _attackDamage(cp._attackDamage)
{
    std::cout << "Copy constructor called" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap &cp)
{
    std::cout << "Copy assignment operator called" << std::endl;

    this->_name = cp._name;
    this->_hitPoint = cp._hitPoint;
    this->_energyPoint = cp._energyPoint;
    this->_attackDamage = cp._attackDamage;
    return (*this);
}

ClapTrap::~ClapTrap(void)
{
    std::cout << "Destructor called" << std::endl;
}

void ClapTrap::attack(const std::string& target)
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

void ClapTrap::takeDamage(unsigned int amount)
{
    if (this->_hitPoint > amount)
        this->_hitPoint -= amount;
    else
        this->_hitPoint = 0;

    if (this->_hitPoint == 0)
        std::cout << "ClapTrap " << _name << " 😵 has no hit points left. Stop beating " << _name << ", he's dead 💀" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (this->_energyPoint > 0 && this->_hitPoint > 0 && this->_hitPoint + amount <= 10)
    {
        this->_hitPoint += amount;
        std::cout << "ClapTrap " << this->_name << " 💚 repairs itself, gaining " << amount << " hit points back." << std::endl;
        this->_energyPoint--;
    }
    else if (this->_energyPoint == 0)
        std::cout << "ClapTrap " << this->_name << "  💔 is not able to repair itself because he doesn't have enough energy points." << std::endl;
    else if (this->_hitPoint == 0)
        std::cout << "ClapTrap " << this->_name << " 💔 is not able to repair itself because he doesn't have enough hit points." << std::endl;
    else
        std::cout << "ClapTrap " << this->_name << " can't have more than 10 hit points." << std::endl;
}