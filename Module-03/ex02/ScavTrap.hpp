#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap: public ClapTrap
{
    private:
        bool _gate;
    public:
        ScavTrap();
        ScavTrap(std::string name);
        ScavTrap(const ScavTrap &st);
        ~ScavTrap();
        ScavTrap& operator=(const ScavTrap &sp);
        void attack(const std::string& target);
        void guardGate();
};

#endif