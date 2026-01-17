#include "FragTrap.hpp"
#include "ClapTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
    std::cout << "FragTrap ready!" << std::endl;
    _hitPoints = 100;
    _energyPoints = 100;
    _attackDamage = 30;
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other)
{
    std::cout << "FragTrap " << other._name << " ready (copy)!" << std::endl;
}


FragTrap::~FragTrap()
{
    std::cout << "FragTrap " << _name << " exploded!" << std::endl;
}

FragTrap& FragTrap::operator = (const FragTrap& rhs)
{
    std::cout << "FragTrap assignment operator called!" << std::endl;
    if (this != &rhs)
    {
        _name = rhs._name;
        _hitPoints = rhs._hitPoints;
        _energyPoints = rhs._energyPoints;
        _attackDamage = rhs._attackDamage;
    }
    return *this;
}


FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
    std::cout << "FragTrap " << name << " ready!" << std::endl;
    _hitPoints = 100;
    _energyPoints = 100;
    _attackDamage = 30;
}

void FragTrap::attack(const std::string& target)
{
    if (_energyPoints == 0 || _hitPoints == 0)
        std::cout << "FragTrap " << _name << " is unable to attack: no hit points or energy left!" << std::endl;
    else
    {
        std::cout << "FragTrap " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage!" << std::endl;
        _energyPoints--;
    }
}

void FragTrap::highFivesGuys(void)
{
    std::cout << "High five? Anyone? ✋" << std::endl;
}
