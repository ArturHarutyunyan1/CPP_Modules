#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : virtual public ClapTrap, virtual public ScavTrap, virtual public FragTrap
{
    private:
        std::string _name;
    public:
        DiamondTrap();
        DiamondTrap(const std::string &name);
        DiamondTrap(const DiamondTrap &copy);
        DiamondTrap &operator=(const DiamondTrap &copy);
        virtual ~DiamondTrap();
        void attack(const std::string& target);
        void whoAmI();
};

#endif