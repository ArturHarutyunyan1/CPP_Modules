#include "Account.hpp"
#include <ctime>
#include <iomanip>
#include <iostream>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

int Account::getNbAccounts( void )
{
    return (_nbAccounts);
}

int Account::getTotalAmount( void )
{
    return (_totalAmount);
}

int Account::getNbDeposits( void )
{
    return (_totalNbDeposits);
};

int Account::getNbWithdrawals( void )
{
    return (_totalNbWithdrawals);
}

void	Account::_displayTimestamp( void )
{
    std::time_t now = std::time(0);
    std::tm *local = std::localtime(&now);

    std::cout << "["
              << 1900 + local->tm_year
              << std::setw(2) << std::setfill('0') << 1 + local->tm_mon
              << std::setw(2) << std::setfill('0') << local->tm_mday << "_"
              << std::setw(2) << std::setfill('0') << local->tm_hour
              << std::setw(2) << std::setfill('0') << local->tm_min
              << std::setw(2) << std::setfill('0') << local->tm_sec
              << "] " << std::flush;
}

Account::Account( int initial_deposit )
{
   this->_accountIndex = _nbAccounts;
   _nbAccounts++;
   this->_amount = initial_deposit;
   _totalAmount += initial_deposit;
   this->_nbDeposits = 0;
   this->_nbWithdrawals = 0;
    _displayTimestamp();
   std::cout << "index:" << this->_accountIndex << ";"
             << "amount:" << this->_amount << ";"
             << "created" << std::endl;
}

void	Account::displayAccountsInfos( void )
{
    _displayTimestamp();
    std::cout << "accounts:" << _nbAccounts
              << "total:" << _totalAmount
              << "deposits:" << _totalNbDeposits
              << "withdrawals:" << _totalNbWithdrawals << std::endl;
}

Account::~Account(void)
{
    _displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";"
              << "amount:" << this->_amount << ";"
              << "closed" << std::endl;
}

void	Account::makeDeposit( int deposit )
{
    int deposit_amount;

    deposit_amount = this->_amount;
    this->_amount += deposit;
    this->_nbDeposits++;
    this->_totalNbDeposits++;
    _displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";"
             << "amount:" << this->_amount << ";"
             << "deposit:" << deposit_amount << ";"
             << "withdrawals:" << this->_nbWithdrawals << std::endl;
}

bool	Account::makeWithdrawal( int withdrawal )
{
    _displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";"
              << "p_amount:" << this->_amount << ";";
    if (this->_amount - withdrawal < 0)
    {
        std::cout << "withdrawal:" << "refused" << std::endl;
        return (false);
    }
    this->_amount -= withdrawal;
    this->_nbWithdrawals++;
    _totalAmount -= withdrawal;
    _totalNbWithdrawals++;
    std::cout << "amount:" << this->_amount << ";"
              << "nb_withdrawals:" << this->_nbWithdrawals << std::endl;
    return (true);
}

int Account::checkAmount() const
{
    return (this->_amount);
}

void Account::displayStatus() const
{
    _displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";"
              << "amount:" << this->_amount << ";"
              << "deposits:" << this->_nbDeposits << ";"
              << "withdrawals" << this->_nbWithdrawals << std::endl;
}

