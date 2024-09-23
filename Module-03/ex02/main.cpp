#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main()
{
    std::cout << "Constructing\n-------------------------" << std::endl;
    FragTrap a("Harry Potter");
    FragTrap c("Albus Dumbledore");
    FragTrap copy(c);
    std::cout << "Epic battle starts\n-------------------------" << std::endl;
    a.highFivesGuys();
    a.attack("Albus Dumbledore");
    c.takeDamage(30);
    c.attack("Harry Potter");
    a.takeDamage(30);
    a.beRepaired(30);
    c.attack("Harry Potter");
    a.takeDamage(30);
    a.highFivesGuys();
    while (c.getHitPoints() != 0)
        c.takeDamage(30);
    std::cout << "Epic battle end\n-------------------------" << std::endl;
}