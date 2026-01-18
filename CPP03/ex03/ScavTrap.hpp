#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"



class ScavTrap:virtual public ClapTrap
{

public:

    // Canonic Form
    ScavTrap();
    ScavTrap(const ScavTrap& other);
    ~ScavTrap();
    ScavTrap& operator = (const ScavTrap& rhs);

    ScavTrap(std::string name);
    void attack(const std::string& target);


    void guardGate();
};


#endif
