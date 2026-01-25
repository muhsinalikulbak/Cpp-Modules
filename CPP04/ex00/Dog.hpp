#ifndef DOG_HPP
#define DOG_HPP

#include <string>
#include "Animal.hpp"

class Dog : Animal
{
protected:
    std::string type;

public:
    Dog();
    ~Dog();
    Dog(const Dog& other);
    Dog& operator = (const Dog& rhs);
};

#endif
