#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap()
{

}

DiamondTrap::DiamondTrap(const DiamondTrap& other)
{
    
    *this = other;
}

DiamondTrap::~DiamondTrap()
{

}

DiamondTrap& DiamondTrap::operator = (const DiamondTrap& rhs)
{
    if (this != &rhs)
    {
        //...
    }
}

DiamondTrap::DiamondTrap(const std::string& name)
{
    _name = name;
    //.....
}

std::string DiamondTrap::getName() const
{
    return _name;
}


void DiamondTrap::whoAmI()
{
    std::cout << "DiamondTrap " << this->getName() << std::endl;
    std::cout << "ClapTrap "  << getName() << std::endl;
}

