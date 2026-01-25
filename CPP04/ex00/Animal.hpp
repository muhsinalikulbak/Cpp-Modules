#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string>
#include <iostream>
class Animal
{
protected:
    std::string type;

public:
    //Canonic Form
    Animal();
    ~Animal();
    Animal(const Animal& other);
    Animal& operator = (const Animal& rhs);

    virtual void makeSound() const;
};

#endif
