#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main()
{
    FragTrap agatangexos("Agatangexos");
    FragTrap vaspurak("Vaspurak");
    FragTrap gaspar("Gasparcho");

    std::cout << "-------------------------------" << std::endl;

    agatangexos.attack("Gasparcho");
    agatangexos.attack("Vaspurak");
    gaspar.takeDamage(30);
    vaspurak.takeDamage(30);
    vaspurak.attack("Gasparcho");
    gaspar.takeDamage(30);
    agatangexos.highFivesGuys();
    agatangexos.attack("Gasparcho");
    gaspar.takeDamage(30);
    agatangexos.highFivesGuys();
    vaspurak.beRepaired(50);
    vaspurak.attack("Agatangexos");
    while(agatangexos.getHitPoints() > 0)
        agatangexos.takeDamage(30);
    vaspurak.highFivesGuys();
    std::cout << "-------------------------------" << std::endl;
}