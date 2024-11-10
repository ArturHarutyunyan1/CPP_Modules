#include "BitcoinExchange.hpp"

long long stringToLong(const std::string &str)
{
    std::stringstream ss(str);
    long long result;

    ss >> result;
    if (ss.fail() || !ss.eof() || result > std::numeric_limits<int>::max())
    {
        throw std::exception();
        return (0);
    }
    return (result);
}

double stringToDouble(const std::string &str)
{
    std::stringstream ss(str);
    double result;

    ss >> result;
    if (ss.fail() || !ss.eof() || result > std::numeric_limits<int>::max())
    {
        throw std::exception();
        return (0);
    }
    return (result);
}

bool isFloat(const std::string str)
{
    try
    {
        double x = stringToDouble(str);
        (void)x;
        return (true);
    }
    catch(...)
    {
        return (false);
    }
}