#include "AMateria.hpp"
#include <iostream>

AMateria::AMateria(std::string const & type)
{
    this->type = type;
}

AMateria::AMateria()
{
    std::cout << "Default constructor called" << std::endl;
}

AMateria::~AMateria()
{
    std::cout << "Destructor called" << std::endl;
}

AMateria::AMateria(const AMateria& other)
{
    std::cout << "Copy constructor called" << std::endl;
    this->type = other.type;
}

AMateria& AMateria::operator = (const AMateria&rhs)
{
    std::cout << "Copy assignment overload called" << std::endl;

    if (this != &rhs)
    {
        this->type = rhs.type;
    }
    return *this;
}

std::string const & AMateria::getType() const
{
    return type;
}

void AMateria::use(ICharacter& target)
{
    // Base implementation - derived classes will override this
    (void)target;
}
