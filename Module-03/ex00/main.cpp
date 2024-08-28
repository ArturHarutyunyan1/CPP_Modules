#include "ClapTrap.hpp"

int main() {
    std::cout << "Welcome to the ClapTrap simulation!\n" << std::endl;

    // Create ClapTrap instances with unique names
    ClapTrap vaspurak("Vaspurak");
    ClapTrap agatangexos("Agatangexos");
    ClapTrap gasparcho("Gasparcho");

    std::cout << "Initial state:\n";
    vaspurak.attack("Agatangexos");
    agatangexos.takeDamage(4);

    agatangexos.attack("Gasparcho");
    gasparcho.takeDamage(5);

    gasparcho.attack("Vaspurak");
    vaspurak.takeDamage(10);

    std::cout << "\nAgatangexos repairs itself:\n";
    agatangexos.beRepaired(10);

    std::cout << "Vaspurak repairs itself:\n";
    vaspurak.beRepaired(3);

    std::cout << "Gasparcho repairs itself:\n";
    gasparcho.beRepaired(5);

    std::cout << "\nFinal state:\n";
    vaspurak.attack("Gasparcho");
    gasparcho.takeDamage(3);

    agatangexos.attack("Gasparcho");
    gasparcho.takeDamage(5);

    std::cout << "\nSimulation complete!\n";

    return 0;
}