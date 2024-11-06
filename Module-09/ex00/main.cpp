#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
    (void)argv;
    if (argc != 2)
    {
        std::cerr << "Invalid input! Usage - ./btc input.txt" << std::endl;
        return (1);
    }
    else
    {
        BitcoinExchange b = BitcoinExchange();
        b.processInput(argv[1]);
    }
    return (0);
}