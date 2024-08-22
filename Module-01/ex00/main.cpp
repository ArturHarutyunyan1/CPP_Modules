#include "Zombie.hpp"

Zombie* newZombie( std::string name );
void randomChump( std::string name );

int main(void)
{
    Zombie *n = newZombie("Gaspar");
    n->announce();
    randomChump("Vaspur");
    delete n;
}