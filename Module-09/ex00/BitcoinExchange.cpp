#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
    std::ifstream file("data.csv");
    std::string line;

    if (!file.is_open())
    {
        std::cerr << "Can't open file - data.csv" << std::endl;
        exit(1);
    }
    while (std::getline(file, line))
    {
        size_t pos = line.find(',');

        if (pos != std::string::npos)
        {
            std::string key = line.substr(0, pos);
            std::string value = line.substr(pos + 1);

            key.erase(0, key.find_first_not_of(" \t"));
            key.erase(key.find_last_not_of(" \t") + 1);
            value.erase(0, value.find_first_not_of(" \t"));
            value.erase(value.find_last_not_of(" \t") + 1);

            if (!key.empty() && !value.empty())
                data[key] = value;
        }
    }
    file.close();
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &copy) : data(copy.data)
{

}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &copy)
{
    if (this != &copy)
        data = copy.data;
    return (*this);
}

BitcoinExchange::~BitcoinExchange()
{

}

bool isFloat(const std::string str)
{
    try
    {
        std::stof(str);
        return (true);
    }
    catch(...)
    {
        return (false);
    }
}

void processDate(std::string date)
{
    std::regex pattern ("^\\d{4}-(0[1-9]|1[0-2])-(0[1-9]|[12]\\d|3[01])$");

    if (!std::regex_match(date, pattern))
    {
        std::cerr << "Error: bad input. Correct format => YEAR-MONTH-DAY" << std::endl;
        return;
    }
    int year = std::stoi(date.substr(0, 4));
    int month = std::stoi(date.substr(5, 2));
    int day = std::stoi(date.substr(8, 2));

    if (month == 2)
    {
        bool isLeap = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
        if ((isLeap && day > 29) || (!isLeap && day > 28))
        {
            std::cerr << "Error: invalid day for month" << std::endl;
            return;
        }
    }
    else if (month == 4 || month == 6 || month == 9 || month == 11)
    {
        if (day > 30)
        {
            std::cerr << "Error: 30 days in this month" << std::endl;
            return;
        }
    }
    else
    {
        if (day > 31)
        {
            std::cerr << "Error: invalid day for month" << std::endl;
            return;
        }
    }
}
template <typename T>
void BitcoinExchange::checkOccrrence(std::string key, T value)
{
    std::map<std::string, std::string>::iterator findDate = data.find(key);
    double val;
    
    val = std::atof(static_cast<std::string>(value).c_str());

    if (findDate != data.end())
    {
        double res = val * std::atof(findDate->second.c_str());
        if (isFloat(value))
        {
            if (std::floor(res) == res)
                std::cout << findDate->first << " => " << value << " = " << static_cast<int>(res) << std::endl;
            else
                std::cout << findDate->first << " => " << value << " = " << std::fixed << std::setprecision(1) << res << std::endl;
        }
        else
            std::cout << findDate->first << " => " << value << " = " << res << std::endl;
    }
    else
    {
        double closestValue = 0.0;

        for (std::map<std::string, std::string>::iterator dataIt = data.begin(); dataIt != data.end(); ++dataIt) {
            if (dataIt->first < key)
                closestValue = std::atof(dataIt->second.c_str());
            else
                break;
        }
        double res = val * closestValue;
        if (isFloat(value))
        {
            if (std::floor(res) == res)
                std::cout << key << " => " << value << " = " << static_cast<int>(res) << std::endl;
            else
                std::cout << key << " => " << value << " = " << std::fixed << std::setprecision(1) << res << std::endl;
        }
        else
            std::cout << key << " => " << value << " = " << res << std::endl;
    }
}

void BitcoinExchange::processLine(std::string key, std::string value)
{
    processDate(key);
    long long temp;

    temp = std::stoll(value);
    if (temp > 1000)
    {
        std::cerr << "Error: too large a number." << std::endl;
        return;
    }
    else if (temp < 0)
    {
        std::cerr << "Error: not a positive number." << std::endl;
        return;
    }
    BitcoinExchange::checkOccrrence(key, value);
    
}

bool checkExtension(char *file)
{
    int i = 0;
    while (file[i] != '.')
    {
        i++;
    }
    if (file[i + 1] != 't' && file[i + 2] != 'x' && file[i + 3] != 't' && file[i + 4] != '\0')
        return (false);
    return (true);    
}

void BitcoinExchange::processInput(char *filename)
{
    std::ifstream file(filename);
    std::string line;

    if (!checkExtension(filename))
    {
        std::cerr << "Invalid file format. Correct format .txt" << std::endl;
        exit (1);
    }

    if (!file.is_open())
    {
        std::cerr << "Can't open file - " << filename << std::endl;
        exit(1);
    }
    std::getline(file, line);
    while (std::getline(file, line))
    {
        size_t pos = line.find('|');

        if (pos != std::string::npos)
        {
            std::string key = line.substr(0, pos);
            std::string value = line.substr(pos + 1);

            key.erase(0, key.find_first_not_of(" \t"));
            key.erase(key.find_last_not_of(" \t") + 1);
            value.erase(0, value.find_first_not_of(" \t"));
            value.erase(value.find_last_not_of(" \t") + 1);
            processLine(key, value);
        }
        else
            std::cerr << "Error: bad input => " << line << std::endl; 
    }
    file.close();
}