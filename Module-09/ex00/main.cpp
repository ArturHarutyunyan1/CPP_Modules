#include "BitcoinExchange.hpp"
#include <string>

int main(int argc, char **argv)
{
    try
    {
        if (argc != 2)
            throw std::runtime_error("Error\nUsage ./btc [input_file]");
        std::string file(argv[1]);
        BitcoinExchange btc(file);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        return (1);
    }
}