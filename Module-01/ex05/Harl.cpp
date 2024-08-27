#include "Harl.hpp"

Harl::Harl(void)
{
    std::cout << "Harl was created :)" << std::endl;
}

Harl::~Harl(void)
{
    std::cout << "\nHarl has been destroyed :(" << std::endl;
}

void Harl::debug(void)
{
    std::cout << "\n" <<  DEBUG_COLOR << "[DEBUG]" << RESET_COLOR << "\n";
    std::cout << "I love having extra bacon for my "
              << "7XL-double-cheese-triple-pickle-specialketchup burger. "
              << "I really do!" << std::endl;
}

void Harl::info(void)
{
    std::cout << "\n" <<  INFO_COLOR << "[INFO]" << RESET_COLOR << "\n";
    std::cout << "I cannot believe adding extra bacon costs more money. "
              << "You didn’t put enough bacon in my burger! "
              << "If you did, I wouldn’t be asking for more!" << std::endl;
}

void Harl::warning(void)
{
    std::cout << "\n" <<  WARNING_COLOR << "[WARNING]" << RESET_COLOR << "\n";
    std::cout << "I think I deserve to have some extra bacon for free. "
              << "I’ve been coming for years whereas you started working here since last month." << std::endl;
}

void Harl::error(void)
{
    std::cout << "\n" <<  ERROR_COLOR << "[ERROR]" << RESET_COLOR << "\n";
    std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void Harl::complain(std::string level)
{
    void (Harl::*ptr_to_complain[4])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
    std::string lvls[4] = {"debug", "info", "warning", "error"};

    for (int i = 0; i < 4; i++)
    {
        if (lvls[i] == level)
        {
            (this->*ptr_to_complain[i])();
            break;
        }
    }
}