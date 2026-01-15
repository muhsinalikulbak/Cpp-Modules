#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>
#include <string>

class ClapTrap
{
private:

    std::string _name;
    int _hitPoints;
    int _energyPoints;
    int _attackDamage;



public:

    // Canonic Form
    ClapTrap();
    ClapTrap(ClapTrap& other);
    ~ClapTrap();
    ClapTrap& operator = (const ClapTrap& rhs);

    ClapTrap(std::string& name);

    void attack(const std::string& target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);



};

#endif
