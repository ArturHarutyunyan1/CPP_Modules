#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
    if (argc <= 2)
    {
        std::cout << "Error" << std::endl;
        return (1);
    }
    else
    {
        PmergeMe pm = PmergeMe();
        pm.processInput(argc, argv);
    }
    return (0);
}