#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
    std::cout << "ScalarConverter constructed" << std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter &copy)
{
    std::cout << "ScalarConverter Copied" << std::endl;
    (void)copy;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &copy)
{
    std::cout << "ScalarConverter copy assignment" << std::endl;
    if (this != &copy)
        ;
    return (*this);
}

ScalarConverter::~ScalarConverter()
{
    std::cout << "ScalarConverter destroyed :((" << std::endl;
}

bool isNumber(const std::string& str) {
    if (str.empty()) return false;
    if (str[0] == '-') {
        return str.length() > 1 && std::all_of(str.begin() + 1, str.end(), ::isdigit);
    }
    return std::all_of(str.begin(), str.end(), ::isdigit);
}

bool isFloat(const std::string& str) {
    if (str.empty()) return false;

    bool hasF = (str.back() == 'f' || str.back() == 'F');
    std::string numericPart = hasF ? str.substr(0, str.size() - 1) : str;

    char* end;
    std::strtof(numericPart.c_str(), &end);
    
    return end != numericPart.c_str() && *end == '\0';
}

void toChar(const std::string& str) {
    float f = std::stof(str);
    int x = static_cast<int>(f);

    if ((f < 0) || (x > 255))
        std::cout << "Char: impossible" << std::endl;
    else if (f >= 32 && f <= 126)
    {
        char r = static_cast<char>(x);
        std::cout << "Char: " << r << std::endl;
    }
    else
        std::cout << "Char: Non displayable" << std::endl;
    
    std::cout << "----------------------------" << std::endl;
}

void toInt(const std::string& str) {
    if (isFloat(str))
    {
        float f = std::stof(str);
        if (f < std::numeric_limits<int>::min() || f > std::numeric_limits<int>::max()) {
            std::cout << "Int: impossible" << std::endl;
        }
        else
        {
            int x = static_cast<int>(f);
            std::cout << "Int: " << x << std::endl;
        }
    }
    else if (isNumber(str))
    {
        int x = std::atoi(str.c_str());
        std::cout << "Int: " << x << std::endl;
    }
    else
        std::cout << "Int: impossible" << std::endl;

    std::cout << "----------------------------" << std::endl;
}

void toFloat(const std::string& str) {
    if (!isFloat(str))
    {
        std::cout << "Float: impossible" << std::endl;
        std::cout << "----------------------------" << std::endl;
        return;
    }

    float f = std::stof(str);
    std::cout << std::fixed << std::setprecision(1) << "Float: " << f << "f" << std::endl;

    std::cout << "----------------------------" << std::endl;
}

void toDouble(const std::string& str) {
    if (str == "nan" || str == "NAN")
        std::cout << "Double: nan" << std::endl;
    else if (!isFloat(str))
        std::cout << "Double: impossible" << std::endl;
    else
    {
        double d = std::stod(str); // Convert string to double
        std::cout << std::fixed << std::setprecision(1) << "Double: " << d << std::endl;
    }

    std::cout << "----------------------------" << std::endl;
}

void ScalarConverter::convert(std::string str)
{
    toChar(str);
    toInt(str);
    toFloat(str);
    toDouble(str);
}