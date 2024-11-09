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
    std::getline(file, line);
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

            if (validateData(key, value))
                data[key] = value;
        }
        else
        {
            std::cerr << "Error: bad input => " << line << std::endl;
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
    int firstDash = date.find('-');
    int secondDash = date.find('-', firstDash + 1);

    if (date.size() > 10 || date[4] != '-' || date[7] != '-')
        throw std::invalid_argument("Error: Date must be in the format YYYY-MM-DD");
    int year, month, day;
    try {
        year = std::stoi(date.substr(0, firstDash));
        month = std::stoi(date.substr(firstDash + 1, secondDash - firstDash - 1));
        day = std::stoi(date.substr(secondDash + 1));
        if (year <= 0 || month <= 0 || day <= 0)
            throw std::out_of_range("Error: Year, month, or day cannot be zero");
    }
    catch (...)
    {
        throw std::invalid_argument("Error: Exception caught in date parsing");
    }

    if (month == 2)
    {
        bool isLeap = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
        if ((isLeap && day > 29) || (!isLeap && day > 28))
            throw std::out_of_range("Error: Invalid day for February");
    }
    else if (month == 4 || month == 6 || month == 9 || month == 11)
    {
        if (day > 30)
            throw std::out_of_range("Error: Invalid day for 30-day month");
    }
    else if (day > 31)
    {
        throw std::out_of_range("Error: Invalid day for month");
    }
}

bool BitcoinExchange::validateData(std::string key, std::string value)
{
    try {
        processDate(key);
    } catch (const std::exception& e) {
        std::cerr << e.what() << " => " << key << std::endl;
        return false;
    }

    try {
        double x = std::stod(value);
        if (x < 0) {
            std::cerr << "Error: Negative number in data" << std::endl;
            return false;
        }
        if (x > std::numeric_limits<int>::max()) {
            std::cerr << "Error: Too large a number in data" << std::endl;
            return false;
        }
    } catch (...) {
        std::cerr << "Error: Invalid number format in data" << std::endl;
        return false;
    }

    return true;
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
                std::cout << findDate->first << " => " << value << " = " << std::fixed << std::setprecision(2) << res << std::endl;
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
                std::cout << key << " => " << value << " = " << std::fixed << std::setprecision(2) << res << std::endl;
        }
        else
            std::cout << key << " => " << value << " = " << res << std::endl;
    }
}

void BitcoinExchange::processLine(std::string key, std::string value)
{
    if (!BitcoinExchange::validateData(key, value))
        return;
    long long temp;
    int dashCount = 0;

    for (size_t i = 0; i < key.size(); i++)
    {
        if (key[i] == '-')
            dashCount++;
    }
    if (dashCount != 2)
    {
        std::cerr << "Error: Invalid format YEAR-MONTH-DAY" << std::endl;
        return;
    }
    for (size_t i = 0; i < key.size(); i++)
    {
        if ((!std::isdigit(key[i]) && key[i] != '-') || key.size() > 10)
        {
            std::cerr << "Error: Bad input => " << key << std::endl;
            return; 
        }
    }
    for (size_t i = 0; i < value.size(); i++)
    {
        if (!std::isdigit(value[i]) && value[i] != '-' && value[i] != '.')
        {
            std::cerr << "Error: Bad input => " << value << std::endl;
            return;
        }
        
        if ((value[i] == '-' && i != 0) || (value[i] == '.' && (i == 0 || i == value.size() - 1 || value.find('.') != i)))
        {
            std::cerr << "Error: Bad input => " << value << std::endl;
            return;
        }
        
        if (std::isdigit(value[i]) && i + 1 < value.size() && !std::isdigit(value[i + 1]) && value[i + 1] != '.' && value[i + 1] != '-')
        {
            std::cerr << "Error: Bad input => " << value << std::endl;
            return;
        }
    }

    try
    {
        temp = std::stoll(value);
    }
    catch (...)
    {
        std::cerr << "Error: Exception caught" << std::endl;
        return;
    }
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