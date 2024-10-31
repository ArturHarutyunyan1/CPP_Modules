#include "ScalarConverter.hpp"

int main(int argc, char **argv)
{
    if (argc > 1 && !argv[2])
        ScalarConverter::convert(argv[1]);
    else
    {
        std::cout << "Invalid input!" << std::endl;
        return (1);
    }
}