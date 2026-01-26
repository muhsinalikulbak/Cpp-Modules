#ifndef DOG_HPP
#define DOG_HPP

#include <string>
#include "Animal.hpp"

class Dog : public Animal
{
    
public:
    // Canonic Form
    Dog();
    ~Dog();
    Dog(const Dog& other);
    Dog& operator = (const Dog& rhs);

    void makeSound() const;
};

#endif
