#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <map>
#include <fstream>
#include <algorithm>
#include <exception>
#include <cstdlib>
#include <regex>
#include <cmath>

class BitcoinExchange
{
    public:
        BitcoinExchange();
        BitcoinExchange(const BitcoinExchange &copy);
        BitcoinExchange &operator=(const BitcoinExchange &copy);
        void processInput(char *filename);
        template <typename T>
        void checkOccrrence(std::string key, T value);
        void processLine(std::string key, std::string value);
        bool validateData(std::string key, std::string value);
        ~BitcoinExchange();
    private:
        std::map<std::string, std::string> data;
};

#endif