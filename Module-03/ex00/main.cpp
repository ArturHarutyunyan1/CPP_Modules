#include "ClapTrap.hpp"

int main()
{
    std::cout << "Constructing\n-------------------------" << std::endl;
    ClapTrap a("Harry Potter");
    ClapTrap c("Albus Dumbledore");
    ClapTrap copy(c);
    std::cout << "Epic battle starts\n-------------------------" << std::endl;
    a.attack("Albus Dumbledore");
    c.takeDamage(20);
    c.attack("Harry Potter");
    a.takeDamage(20);
    a.beRepaired(5);
    c.attack("Harry Potter");
    a.takeDamage(20);
    while (c.getHitPoints() != 0)
        c.takeDamage(20);
    std::cout << "Epic battle end\n-------------------------" << std::endl;
}