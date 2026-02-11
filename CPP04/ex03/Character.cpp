#include "Character.hpp"
#include <iostream>

// Constructor
Character::Character(std::string const & name) : name(name)
{
    for (int i = 0; i < 4; i++)
    {
        inventory[i] = NULL;
    }
}

// Copy Constructor - Deep copy
Character::Character(const Character& other) : name(other.name)
{
    for (int i = 0; i < 4; i++)
    {
        if (other.inventory[i] != NULL)
            inventory[i] = other.inventory[i]->clone();
        else
            inventory[i] = NULL;
    }
}

// Copy Assignment Operator - Deep copy
Character& Character::operator=(const Character& rhs)
{
    if (this != &rhs)
    {
        name = rhs.name;
        
        // Delete old materias
        for (int i = 0; i < 4; i++)
        {
            if (inventory[i] != NULL)
            {
                delete inventory[i];
                inventory[i] = NULL;
            }
        }
        
        // Clone new materias
        for (int i = 0; i < 4; i++)
        {
            if (rhs.inventory[i] != NULL)
                inventory[i] = rhs.inventory[i]->clone();
            else
                inventory[i] = NULL;
        }
    }
    return *this;
}

// Destructor
Character::~Character()
{
    for (int i = 0; i < 4; i++)
    {
        if (inventory[i] != NULL)
        {
            delete inventory[i];
        }
    }
}

// getName implementation
std::string const & Character::getName() const
{
    return name;
}

// equip implementation - adds to first empty slot
void Character::equip(AMateria* m)
{
    if (m == NULL)
        return;
    
    for (int i = 0; i < 4; i++)
    {
        if (inventory[i] == NULL)
        {
            inventory[i] = m;
            return;
        }
    }
    // Inventory is full, do nothing
}

// unequip implementation - does NOT delete the Materia
void Character::unequip(int idx)
{
    if (idx >= 0 && idx < 4 && inventory[idx] != NULL)
    {
        inventory[idx] = NULL;
    }
}

// use implementation - uses the Materia at slot[idx]
void Character::use(int idx, ICharacter& target)
{
    if (idx >= 0 && idx < 4 && inventory[idx] != NULL)
    {
        inventory[idx]->use(target);
    }
}
