#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap:virtual public ClapTrap
{
public:

    FragTrap();
    FragTrap(const FragTrap& other);
    ~FragTrap();
    FragTrap& operator = (const FragTrap& rhs);

    FragTrap(std::string name);
    void attack(const std::string& target);
    void highFivesGuys(void);
};


#endif
