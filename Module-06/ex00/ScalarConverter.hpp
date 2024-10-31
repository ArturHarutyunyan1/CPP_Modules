#ifndef SCALARCONVERTER
#define SCALARCONVERTER

#include <iostream>
#include <iomanip>

class ScalarConverter
{
    public:
        static void convert(std::string input);
    private:
        ScalarConverter();
        ScalarConverter(const ScalarConverter &copy);
        ScalarConverter &operator=(const ScalarConverter &copy);
        ~ScalarConverter();
};

#endif