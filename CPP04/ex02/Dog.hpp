#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
private:
    Brain* brain;
public:
    // Canonic Form
    Dog();
    ~Dog();
    Dog(const Dog& other);
    Dog& operator = (const Dog& rhs);

    void makeSound() const;
};

#endif
