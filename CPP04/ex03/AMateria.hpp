#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <string>
#include "ICharacter.hpp"

class AMateria
{
protected:
    std::string type;

public:
    AMateria(std::string const & type);

    // Canonic Form
    AMateria();
    ~AMateria();
    AMateria(const AMateria& other);
    AMateria& operator = (const AMateria& rhs);

    // Other Functions
    std::string const & getType() const; //Returns the materia type
    virtual AMateria* clone() const = 0; // zorunlu implemente
    virtual void use(ICharacter& target);
};

#endif
