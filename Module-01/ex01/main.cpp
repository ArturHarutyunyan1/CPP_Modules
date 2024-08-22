#include "Zombie.hpp"

int main(void)
{
    int N = 5;

    Zombie *hrd = zombieHorde(N, "Gasparcho");
    for (int i = 0; i < N; i++)
        hrd[i].announce();
    delete [] hrd;
}