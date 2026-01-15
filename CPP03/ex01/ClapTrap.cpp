#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
    std::cout << "ClapTrap default constructor called" << std::endl;
    _name = "";
    _hitPoints = 10;
    _energyPoints = 10;
    _attackDamage = 0;
}

ClapTrap::ClapTrap(const ClapTrap& other)
{
    std::cout << "ClapTrap copy constructor called" << std::endl;
    *this = other;
}

ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap " << _name << " destructed!" << std::endl;
}

ClapTrap& ClapTrap::operator = (const ClapTrap& rhs)
{
    std::cout << "ClapTrap assignment operator called" << std::endl;

    if (this != &rhs)
    {
        _name = rhs._name;
        _hitPoints = rhs._hitPoints;
        _energyPoints = rhs._energyPoints;
        _attackDamage = rhs._attackDamage;
    }
    return *this;
}


ClapTrap::ClapTrap(const std::string& name)
{
    std::cout << "ClapTrap " << name << " has been built!" << std::endl;

    _name = name;
    _hitPoints = 10;
    _energyPoints = 10;
    _attackDamage = 0;
}

void ClapTrap::attack(const std::string& target)
{
    if (_energyPoints == 0 || _hitPoints == 0)
        std::cout << "ClapTrap " << _name << " is unable to attack: no hit points or energy left!" << std::endl;
    else
    {
        std::cout << "ClapTrap " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage!" << std::endl;
        _energyPoints--;
    }
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (_hitPoints == 0)
        std::cout << "ClapTrap " << _name << " is already dead!" << std::endl;
    else if (amount >= _hitPoints)
    {
        _hitPoints = 0;
        std::cout << "ClapTrap " << _name << " died!" << std::endl;
    }
    else
    {
        _hitPoints -= amount;
        std::cout << "ClapTrap " << _name << " took " << amount << " points of damage! Remaining HP: " << _hitPoints << std::endl;
    }
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (_hitPoints == 0 || _energyPoints == 0)
        std::cout << "ClapTrap " << _name << " cannot be repaired (already dead or no energy)!" << std::endl;
    else
    {
        _hitPoints += amount;
        _energyPoints--;
        std::cout << "ClapTrap " << _name << " repairs itself, regaining " << amount <<
        " HP! Current HP: " << _hitPoints << " | Energy: " << _energyPoints << std::endl;
    }
}


std::string ClapTrap::getName() const
{
    return _name;
}

unsigned int ClapTrap::getHitPoints() const
{
    return _hitPoints;
}

unsigned int ClapTrap::getEnergyPoints() const
{
    return _energyPoints;
}

unsigned int ClapTrap::getAttackDamage() const
{
    return _attackDamage;
}
