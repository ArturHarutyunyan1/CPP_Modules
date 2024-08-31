#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
    ScavTrap agatangexos("Agatangexos");
    ScavTrap vaspurak("Vaspurak");
    ScavTrap gaspar("Gasparcho");

    std::cout << "-------------------------------" << std::endl;

    agatangexos.attack("Gasparcho");
    agatangexos.attack("Vaspurak");
    gaspar.takeDamage(20);
    vaspurak.takeDamage(20);
    vaspurak.attack("Gasparcho");
    gaspar.takeDamage(20);
    agatangexos.guardGate();
    agatangexos.attack("Gasparcho");
    gaspar.takeDamage(20);
    agatangexos.guardGate();
    vaspurak.beRepaired(14);
    vaspurak.attack("Agatangexos");
    vaspurak.guardGate();
    while(agatangexos.getHitPoints() != 0)
        agatangexos.takeDamage(20);
    vaspurak.guardGate();
    std::cout << "-------------------------------" << std::endl;
}