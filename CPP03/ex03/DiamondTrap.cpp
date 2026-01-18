#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap():ClapTrap(), FragTrap(), ScavTrap()
{
    std::cout << "DiamondTrap activated!" << std::endl;
    _name = "";
    _hitPoints = 100;
    _energyPoints = 50;
    _attackDamage = 30;
}

DiamondTrap::DiamondTrap(const DiamondTrap& other):ClapTrap(other), FragTrap(other), ScavTrap(other)
{
    std::cout << "DiamondTrap " << other._name << " activated (copy)!" << std::endl;
    _name = other._name;
}

DiamondTrap::~DiamondTrap()
{
    std::cout << "DiamondTrap " << _name << " deactivated!" << std::endl;
}

DiamondTrap& DiamondTrap::operator = (const DiamondTrap& rhs)
{
    std::cout << "DiamondTrap assignment operator called!" << std::endl;
    if (this != &rhs)
    {
        ClapTrap::_name = rhs.ClapTrap::_name;
        _name = rhs._name;
        _hitPoints = rhs._hitPoints;
        _energyPoints = rhs._energyPoints;
        _attackDamage = rhs._attackDamage;
    }
    return *this;
}

DiamondTrap::DiamondTrap(const std::string& name):ClapTrap(name + "_clap_name")
{
    std::cout << "DiamondTrap " << name << " has been built!" << std::endl;
    _name = name;
    _hitPoints = 100;
    _energyPoints = 50;
    _attackDamage = 30;
}


void DiamondTrap::whoAmI()
{
    std::cout << "DiamondTrap name : " << _name << std::endl;
    std::cout << "ClapTrap name : "  << ClapTrap::_name << std::endl;
}
