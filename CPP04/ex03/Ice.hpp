#ifndef ICE_HPP
#define ICE_HPP

#include "AMateria.hpp"

class Ice : public AMateria
{
public:
    // Canonical Form
    Ice();
    Ice(const Ice& other);
    Ice& operator=(const Ice& rhs);
    ~Ice();

    // Member Functions
    AMateria* clone() const;
    void use(ICharacter& target);
};

#endif
