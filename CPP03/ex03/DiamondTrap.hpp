#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap:public FragTrap, public ScavTrap
{
private:
    std::string _name;

public:
    DiamondTrap();
    DiamondTrap(const DiamondTrap& other);
    ~DiamondTrap();
    DiamondTrap& operator = (const DiamondTrap& rhs);

    DiamondTrap(const std::string& name);

    using ScavTrap::attack;

    void whoAmI();
};



#endif
