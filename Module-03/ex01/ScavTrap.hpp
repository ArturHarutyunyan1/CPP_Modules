#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap: public ClapTrap
{
    private:
        bool        _guard;
    public:
        ScavTrap();
        ScavTrap(const std::string &name);
        ScavTrap(const ScavTrap &copy);
        ScavTrap &operator=(const ScavTrap &copy);
        virtual ~ScavTrap();
        void guardGate();
};

#endif