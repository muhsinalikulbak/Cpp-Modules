#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap:public FragTrap, public ScavTrap
{
private:
    std::string _name;
    using FragTrap::_hitPoints;
    using ScavTrap::_energyPoints;
    using FragTrap::_attackDamage;

public:
    DiamondTrap();
    DiamondTrap(const DiamondTrap& other);
    ~DiamondTrap();
    DiamondTrap& operator = (const DiamondTrap& rhs);

    DiamondTrap(const std::string& name);

    using ScavTrap::attack;
    using ClapTrap::getName;
    
    std::string getName() const;
    void whoAmI();
};



#endif