#include "Ice.hpp"
#include "ICharacter.hpp"
#include <iostream>

// Default Constructor
Ice::Ice() : AMateria("ice")
{
}

// Copy Constructor
Ice::Ice(const Ice& other) : AMateria(other)
{
}

// Copy Assignment Operator
Ice& Ice::operator=(const Ice& rhs)
{
    // Note: We don't copy the type as per requirements
    // "copying the type doesn't make sense"
    (void)rhs;
    return *this;
}

// Destructor
Ice::~Ice()
{
}

// Clone Function
AMateria* Ice::clone() const
{
    return new Ice(*this);
}

// Use Function
void Ice::use(ICharacter& target)
{
    std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
