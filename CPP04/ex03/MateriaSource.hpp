#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"
#include "AMateria.hpp"

class MateriaSource : public IMateriaSource
{
private:
    AMateria* templates[4];

public:
    // Canonical Form
    MateriaSource();
    MateriaSource(const MateriaSource& other);
    MateriaSource& operator=(const MateriaSource& rhs);
    ~MateriaSource();

    // IMateriaSource interface implementation
    void learnMateria(AMateria* m);
    AMateria* createMateria(std::string const & type);
};

#endif
