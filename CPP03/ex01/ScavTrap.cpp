#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
{
    std::cout << "ScavTrap default constructor called" << std::endl;
    _name = "";
    _hitPoints = 100;
    _energyPoints = 50;
    _attackDamage = 20;
}

ScavTrap::ScavTrap(const ScavTrap& other)
{
    std::cout << "ScavTrap copy constructor called" << std::endl;
    *this = other;
}


ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap " << _name << " destructed!" << std::endl;
}

ScavTrap& ScavTrap::operator = (const ScavTrap& rhs)
{
    std::cout << "ScavTrap assignment operator called" << std::endl;

    if (this != &rhs)
    {
        _name = rhs._name;
        _hitPoints = rhs._hitPoints;
        _energyPoints = rhs._energyPoints;
        _attackDamage = rhs._attackDamage;
    }
    return *this;
}

ScavTrap::ScavTrap(std::string name)
{
    std::cout << "ScavTrap " << name << " has been built!" << std::endl;
    _name = name;
    _hitPoints = 100;
    _energyPoints = 50;
    _attackDamage = 20;
}

void ScavTrap::attack(const std::string& target)
{
    if (_energyPoints == 0 || _hitPoints == 0)
        std::cout << "ScavTrap " << _name << " is unable to attack: no hit points or energy left!" << std::endl;
    else
    {
        std::cout << "ScavTrap " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage!" << std::endl;
        _energyPoints--;
    }
}

void ScavTrap::guardGate()
{
    std::cout << "ScavTrap " << _name << " is now in Gate keeper mode." << std::endl;
}
