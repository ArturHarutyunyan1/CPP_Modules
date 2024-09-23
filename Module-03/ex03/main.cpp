#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int main()
{
    std::cout << "Constructing\n-------------------------" << std::endl;
    DiamondTrap a("Harry Potter");
    DiamondTrap c("Albus Dumbledore");
    DiamondTrap copy(c);
    std::cout << "Epic battle starts\n-------------------------" << std::endl;
    a.highFivesGuys();
    a.attack("Albus Dumbledore");
    c.guardGate();
    c.takeDamage(30);
    c.attack("Harry Potter");
    a.takeDamage(30);
    c.whoAmI();
    a.beRepaired(30);
    c.guardGate();
    c.attack("Harry Potter");
    a.takeDamage(30);
    a.whoAmI();
    a.highFivesGuys();
    while (c.getHitPoints() != 0)
        c.takeDamage(30);
    std::cout << "Epic battle end\n-------------------------" << std::endl;
}