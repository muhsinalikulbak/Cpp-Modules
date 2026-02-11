#include "Cure.hpp"
#include "ICharacter.hpp"
#include <iostream>

// Default Constructor
Cure::Cure() : AMateria("cure")
{
}

// Copy Constructor
Cure::Cure(const Cure& other) : AMateria(other)
{
}

// Copy Assignment Operator
Cure& Cure::operator=(const Cure& rhs)
{
    // Note: We don't copy the type as per requirements
    // "copying the type doesn't make sense"
    (void)rhs;
    return *this;
}

// Destructor
Cure::~Cure()
{
}

// Clone Function
AMateria* Cure::clone() const
{
    return new Cure(*this);
}

// Use Function
void Cure::use(ICharacter& target)
{
    std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
