#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap():ClapTrap(), FragTrap(), ScavTrap()
{
    std::cout << "Diamond runs with default right now !" << std::endl;
    _name = "";
    _hitPoints = 100;
    _energyPoints = 50;
    _attackDamage = 30;
}

DiamondTrap::DiamondTrap(const DiamondTrap& other):ClapTrap(other), FragTrap(other), ScavTrap(other)
{
    std::cout << "Diamond starts with copy" << std::endl;
    _name = other._name;
}

DiamondTrap::~DiamondTrap()
{
    std::cout << "Diamond Destroyed !" << std::endl;
}

DiamondTrap& DiamondTrap::operator = (const DiamondTrap& rhs)
{
    if (this != &rhs)
    {
        _name = rhs._name;
        _hitPoints = rhs._hitPoints;
        _energyPoints = rhs._energyPoints;
        _attackDamage = rhs._attackDamage;
    }
    return *this;
}

DiamondTrap::DiamondTrap(const std::string& name):ClapTrap(name + "_clap_name")
{
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
