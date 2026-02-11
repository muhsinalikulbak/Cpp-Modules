#include "MateriaSource.hpp"

// Default Constructor
MateriaSource::MateriaSource()
{
    for (int i = 0; i < 4; i++)
    {
        templates[i] = NULL;
    }
}

// Copy Constructor - Deep copy
MateriaSource::MateriaSource(const MateriaSource& other)
{
    for (int i = 0; i < 4; i++)
    {
        if (other.templates[i] != NULL)
            templates[i] = other.templates[i]->clone();
        else
            templates[i] = NULL;
    }
}

// Copy Assignment Operator - Deep copy
MateriaSource& MateriaSource::operator=(const MateriaSource& rhs)
{
    if (this != &rhs)
    {
        // Delete old templates
        for (int i = 0; i < 4; i++)
        {
            if (templates[i] != NULL)
            {
                delete templates[i];
                templates[i] = NULL;
            }
        }
        
        // Clone new templates
        for (int i = 0; i < 4; i++)
        {
            if (rhs.templates[i] != NULL)
                templates[i] = rhs.templates[i]->clone();
            else
                templates[i] = NULL;
        }
    }
    return *this;
}

// Destructor
MateriaSource::~MateriaSource()
{
    for (int i = 0; i < 4; i++)
    {
        if (templates[i] != NULL)
        {
            delete templates[i];
        }
    }
}

// learnMateria - Copies and stores the Materia
void MateriaSource::learnMateria(AMateria* m)
{
    if (m == NULL)
        return;
    
    for (int i = 0; i < 4; i++)
    {
        if (templates[i] == NULL)
        {
            templates[i] = m->clone();
            return;
        }
    }
    // Storage is full, do nothing
}

// createMateria - Returns a new Materia of the requested type
AMateria* MateriaSource::createMateria(std::string const & type)
{
    for (int i = 0; i < 4; i++)
    {
        if (templates[i] != NULL && templates[i]->getType() == type)
        {
            return templates[i]->clone();
        }
    }
    // Type unknown, return NULL
    return NULL;
}
