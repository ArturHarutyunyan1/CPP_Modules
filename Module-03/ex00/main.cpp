#include "ClapTrap.hpp"

int main()
{
    ClapTrap agatangexos("Agatangexos");
    ClapTrap vaspurak("Vaspurak");
    ClapTrap gaspar("Gasparcho");

    std::cout << "-------------------------------" << std::endl;

    agatangexos.attack("Gasparcho");
    agatangexos.attack("Vaspurak");
    gaspar.takeDamage(7);
    vaspurak.takeDamage(5);
    vaspurak.attack("Gasparcho");
    gaspar.takeDamage(3);
    agatangexos.attack("Gasparcho");
    gaspar.takeDamage(5);
    vaspurak.beRepaired(5);
    vaspurak.attack("Agatangexos");
    agatangexos.takeDamage(10);
    std::cout << "-------------------------------" << std::endl;
}