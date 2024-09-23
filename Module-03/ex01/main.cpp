#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
    std::cout << "Constructing\n-------------------------" << std::endl;
    ScavTrap a("Harry Potter");
    ScavTrap c("Albus Dumbledore");
    ScavTrap copy(c);
    std::cout << "Epic battle starts\n-------------------------" << std::endl;
    a.guardGate();
    a.attack("Albus Dumbledore");
    c.takeDamage(20);
    c.attack("Harry Potter");
    a.takeDamage(20);
    a.beRepaired(5);
    c.attack("Harry Potter");
    a.takeDamage(20);
    a.guardGate();
    while (c.getHitPoints() != 0)
        c.takeDamage(20);
    std::cout << "Epic battle end\n-------------------------" << std::endl;
}