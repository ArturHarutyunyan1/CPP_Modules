#include "BitcoinExchange.hpp"

void BitcoinExchange::setData(const std::string &line)
{
    size_t pos;
    double val;

    pos = line.find(',');
    if (pos != std::string::npos)
    {
        std::string key = line.substr(0, pos);
        std::string value = line.substr(pos + 1);
        val = toDouble(value);
        this->data[key] = val;    
    }
}

void BitcoinExchange::validateInput(const std::string &line, int type) const
{
    size_t pos;
    double val;

    pos = line.find('|');
    if (pos != std::string::npos)
    {
        std::string key = line.substr(0, pos);
        std::string value = line.substr(pos + 1);

        key.erase(0, key.find_first_not_of(" \t"));
        key.erase(key.find_last_not_of(" \t") + 1);
        value.erase(0, value.find_first_not_of(" \t"));
        value.erase(value.find_last_not_of(" \t") + 1);
        val = toDouble(value);
        if (type == 1 && key != "date" && value != "value")
            throw std::runtime_error("Error: Invalid file content");
        if (value[0] == '-')
        {
            std::cerr << "Error: not a positive number => " << value << std::endl;
            return;
        }
        else if (val > 1000)
        {
            std::cerr << "Error: too large a number => " << value << std::endl;
            return;
        }
        if (checkDate(key))
            calculateValue(key, val);
    }
    else
        std::cerr << "Bad input => " << line << std::endl;
}

bool BitcoinExchange::checkDate(const std::string &line) const {
    
    size_t firstDash = line.find('-');
    size_t secondDash = line.find('-', firstDash + 1);
    
    if (firstDash == std::string::npos || secondDash == std::string::npos || line.substr(secondDash + 1).find('-') != std::string::npos)
    {
        std::cerr << "Error: Invalid date format " << line << ". Expected format: YEAR-MONTH-DAY" << std::endl;
        return (false);
    }

    std::string y = line.substr(0, firstDash);
    std::string m = line.substr(firstDash + 1, secondDash - firstDash - 1);
    std::string d = line.substr(secondDash + 1);

    if ((m.size() == 2 && m[0] == '0' && m[1] == '0') || (d.size() == 2 && d[0] == '0' && d[1] == '0'))
    {
        std::cerr << "Error: Invalid date => " << line << std::endl;
        return (false);
    }
    for (size_t i = 0; i < line.size(); ++i)
    {
        if (!std::isdigit(line[i]) && line[i] != '-') {
            std::cerr << "Error: Bad input => " << line << std::endl;
            return (false);
        }
    }

    long year = toDouble(y);
    long month = toDouble(m);
    long day = toDouble(d);

    if (!isValidDate(year, month, day))
    {
        std::cerr << "Error: Invalid date => " << line << std::endl;
        return (false);
    }
    return (true);
}

bool BitcoinExchange::isValidDate(long year, long month, long day) const
{
    if (month < 1 || month > 12 || day < 1 || day > 31)
        return false;
    if (month == 2)
    {
        bool isLeap = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
        if ((isLeap && day > 29) || (!isLeap && day > 28)) {
            return false;
        }
    }
    else if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)
        return false;
    return true;
}

double BitcoinExchange::toDouble(const std::string &value) const
{
    std::stringstream ss(value);

    double res;
    ss >> res;
    if (ss.fail() || !ss.eof())
        std::cerr << "Error: Invalid number => " << value << std::endl;
    return (res);
}