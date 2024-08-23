#include "HumanB.hpp"

HumanB::HumanB(std::string name): _name(name), _weapon(nullptr)
{
    std::cout << "HumanB " << name << " created" << std::endl;
}

HumanB::~HumanB(void)
{
    std::cout << "HumanB " << this->_name << " destroyed" << std::endl;
}

void HumanB::attack(void)
{
    std::cout << this->_name << " attacks with their " << this->_weapon->getType() << std::endl;
}

void HumanB::setWeapon(Weapon &weapon)
{
    this->_weapon = &weapon;
}
