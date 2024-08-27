#ifndef HARL_HPP
#define HARL_HPP

#include <iostream>

const std::string DEBUG_COLOR = "\033[90m";
const std::string INFO_COLOR = "\033[32m";
const std::string WARNING_COLOR = "\033[33m";
const std::string ERROR_COLOR = "\033[31m";
const std::string RESET_COLOR = "\033[0m";

class Harl
{
    public:
        Harl();
        ~Harl();
        void complain( std::string level );
    private:
        void debug( void );
        void info( void );
        void warning( void );
        void error( void );
};

#endif