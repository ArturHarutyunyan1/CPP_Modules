#include "RPN.hpp"

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cout << "Error" << std::endl;
        return (1);
    }
    else
    {
        RPN polish = RPN();

        polish.ReversePolishNotation(argv[1]);
    }
    return (0);
}