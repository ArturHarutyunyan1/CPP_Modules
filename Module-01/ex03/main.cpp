#include "HumanA.hpp"
#include "HumanB.hpp"

int main()
    {
        {
            Weapon club = Weapon("ak47");
            HumanA bob("Gaspar", club);
            bob.attack();
            club.setType("rpg");
            bob.attack();
        }
        {
            Weapon club = Weapon("Vaspur");
            HumanB jim("Agatangexos");
            jim.setWeapon(club);
            jim.attack();
            club.setType("Spiridon");
            jim.attack();
    }
    return 0;
}