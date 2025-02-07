#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <map>

class BitcoinExchange
{
    private:
        std::map<std::string, double> data;
        enum FileType { DataFile = 0, InputFile = 1};
    private:
        void readFile(const std::string &file, int type);
        void setData(const std::string &line);
        void calculateValue(const std::string &date, double value) const;
    private:
        double toDouble(const std::string &value) const;
        bool checkDate(const std::string &line) const;
        bool isValidDate(long year, long month, long day) const;
        bool validHeader(const std::string &line) const;
        void validateInput(const std::string &line, int type) const;
    public:
        BitcoinExchange(const std::string &file);
        BitcoinExchange(const BitcoinExchange &copy);
        BitcoinExchange &operator=(const BitcoinExchange &copy);
        ~BitcoinExchange();
};


#endif