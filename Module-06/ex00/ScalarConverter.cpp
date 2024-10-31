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

std::string ft_toupper(std::string str)
{
    for (int i = 0; str[i]; i++)
    {
        if (str[i] >= 'a' && str[i] <= 'z')
            str[i] = (char)std::toupper(str[i]);
    }
    return (str);
}

bool isNum(const std::string str)
{
    unsigned int i = 0;
    
    if (str.empty())
        return (false);
    if (str[0] == '-') {
        if (str.size() == 1 || !std::isdigit(str[1]))
            return (false);
        i = 1;
    }
    while (i < str.size())
    {
        if (!std::isdigit(str[i]))
            return (false);
        i++;
    }
    return (true);
}

bool isFloat(const std::string str)
{
    unsigned int i = 0;
    bool hasDecimal = false;

    if (str.empty())
        return (false);
    if (str[0] == '-')
    {
        if (str.size() == 1 || !std::isdigit(str[1]))
            return (false);
        i = 1;
    }
    while (i < str.size())
    {
        if (i == str.size() - 1 && str[i] == 'f')
            return (hasDecimal);
        if (str[i] == '.')
        {
            if (hasDecimal)
                return (false);
            hasDecimal = true;
        }
        else if (!std::isdigit(str[i]))
            return (false);
        i++;
    }
    return (true);
}

void processInput(std::string str)
{
    if (ft_toupper(str) == "-INF" || ft_toupper(str) == "-INFF")
    {
        std::cout << "char: imposibble\nint: imposibble\nfloat: -inff\ndouble: -inf" << std::endl;
        exit(1);
    }
    else if (ft_toupper(str) == "+INF" || ft_toupper(str) == "+INFF")
    {
        std::cout << "char: imposibble\nint: imposibble\nfloat: +inff\ndouble: +inf" << std::endl;
        exit(1);
    }
    else if (ft_toupper(str) == "NAN" || ft_toupper(str) == "NANF")
    {
        std::cout << "char: imposibble\nint: imposibble\nfloat: nanf\ndouble: nan" << std::endl;
        exit(1);
    }
    else if (!isNum(str) && !isFloat(str) && str.size() > 1)
    {
        std::cout << "char: imposibble\nint: imposibble\nfloat: imposibble\ndouble: imposibble" << std::endl;
        exit(1);
    }
}

void toChar(std::string str)
{
    int x;
    float f;

    if (isNum(str))
    {
        x = std::atoi(str.c_str());
        char c = static_cast<char>(x);
        if (x >= 32 && x <= 126)
            std::cout << "char: '" << c << "'" << std::endl;
        else if (x < 0 || x > 255)
            std::cout << "char: imposibble" << std::endl;
        else
            std::cout << "char: non displayable" << std::endl;
    }
    else if (isFloat(str))
    {
        f = std::stof(str);
        x = static_cast<int>(f);
        char c = static_cast<char>(x);
        if (f < 0 || x > 255)
            std::cout << "char: imposibble" << std::endl;
        else if (x >= 32 && x <= 126)
            std::cout << "char: '" << c << "'" << std::endl;
        else
            std::cout << "char: non displayable" << std::endl;
    }
    else
    {
        if (str.size() == 1)
            std::cout << "char: '" << str[0] << "' " << std::endl;
        else
            std::cout << "char: impossible" << std::endl;
    }
}

void toInt(std::string str)
{
    int x;
    long long temp;
    if (!isNum(str) && !isFloat(str))
    {
        if (str.size() == 1)
        {
            x = static_cast<int>(str[0]);
            std::cout << "int: " << x << std::endl;
            return;
        }
        else
        {
            std::cout << "int: invalid input" << std::endl;
            return;
        }
    }
    try
    {
        if (isNum(str))
            temp = std::stoll(str);
        if (isFloat(str))
            temp = std::stof(str);
        if (temp > std::numeric_limits<int>::max() || temp < std::numeric_limits<int>::min())
            std::cout << "int: impossible" << std::endl;
        else
        {
            x = static_cast<int>(temp);
            std::cout << "int: " << x << std::endl;
        }
    }
    catch (const std::out_of_range&)
    {
        std::cout << "int: impossible" << std::endl;
    }
}

void toFloat(std::string str)
{
    float x;
    long long temp;
    if (!isNum(str) && !isFloat(str))
    {
        if (str.size() == 1)
        {
            x = static_cast<float>(str[0]);
            std::cout << std::fixed << std::setprecision(1) << "float: " << x << "f" << std::endl;
            return;
        }
        else
        {
            std::cout << "float: invalid input" << std::endl;
            return;
        }
    }
    try
    {
        temp = std::stof(str);
        if (temp > std::numeric_limits<int>::max() || temp < std::numeric_limits<int>::min())
            std::cout << "float: impossible" << std::endl;
        else
        {
            x = static_cast<float>(temp);
            std::cout << std::fixed << std::setprecision(1) << "float: " << x << "f" << std::endl;
        }
    }
    catch (const std::out_of_range&)
    {
        std::cout << "float: impossible" << std::endl;
    }
}

void toDouble(std::string str)
{
    double x;
    long long temp;
    if (!isNum(str) && !isFloat(str))
    {
        if (str.size() == 1)
        {
            x = static_cast<float>(str[0]);
            std::cout << "float: " << x << std::endl;
            return;
        }
        else
        {
            std::cout << "float: invalid input" << std::endl;
            return;
        }
    }
    try
    {
        temp = std::stof(str);
        if (temp > std::numeric_limits<int>::max() || temp < std::numeric_limits<int>::min())
            std::cout << "float: impossible" << std::endl;
        else
        {
            x = static_cast<float>(temp);
            std::cout << "float: " << x << std::endl;
        }
    }
    catch (const std::out_of_range&)
    {
        std::cout << "float: impossible" << std::endl;
    }
}

void ScalarConverter::convert(std::string str)
{
    processInput(str);
    toChar(str);
    toInt(str);
    toFloat(str);
    toDouble(str);
}