#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(const std::string &file)
{
    std::string name("data.csv");
    readFile(name, DataFile);
    readFile(file, InputFile);
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

void BitcoinExchange::readFile(const std::string &fileName, int type)
{
    std::ifstream file(fileName);
    std::string line;

    if (!file.is_open())
        throw std::runtime_error("Can't open file: " + fileName);
    validateInput(line, 1);
    if (type == DataFile)
        while (std::getline(file, line))
            setData(line);
    else
        while (std::getline(file, line))
           validateInput(line, 0);
}

void BitcoinExchange::calculateValue(const std::string &key, double value) const
{
    double result = 0;
    std::map<std::string, double>::const_iterator it;

    it = this->data.find(key);
    if (it != this->data.end())
        result = it->second * value;
    else
    {
        for (it = this->data.begin(); it != this->data.end(); ++it)
        {
            if (it->first < key)
                result = it->second * value;
            else
                break;
        }
    }
    std::cout << std::fixed << std::setprecision(4) << key << " => " << value << " = " << result << std::endl;
}
