#include "Dog.hpp"    

Dog::Dog() : Animal()
{
    std::cout << "Dog Default constructor called" << std::endl;
    type = "Dog";
}
Dog::~Dog()
{
    std::cout << "Dog is destroyed" << std::endl;
}

Dog::Dog(const Dog& other) : Animal(other)
{
    std::cout << "Dog copy constructor  called" << std::endl;
}

Dog& Dog::operator = (const Dog& rhs)
{
    std::cout << "Dog copy assignment operator called" << std::endl;

    if (this != &rhs)
    {
        Animal::operator=(rhs);
        this->type = rhs.type;
    }
    return *this;
}

void Dog::makeSound() const
{
    std::cout << "Woof wood!" << std::endl;
}
