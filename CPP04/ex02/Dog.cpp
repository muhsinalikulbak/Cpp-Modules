#include "Dog.hpp"
#include "Brain.hpp"

Dog::Dog() : Animal()
{
    std::cout << "Dog Default constructor called" << std::endl;
    type = "Dog";
    brain = new Brain();
}
Dog::~Dog()
{
    std::cout << "Dog is destroyed" << std::endl;
    delete brain;
}

Dog::Dog(const Dog& other) : Animal(other)
{
    std::cout << "Dog copy constructor  called" << std::endl;
    brain = new Brain(*other.brain);
}

Dog& Dog::operator = (const Dog& rhs)
{
    std::cout << "Dog copy assignment operator called" << std::endl;

    if (this != &rhs)
    {
        Animal::operator=(rhs);
        *brain = *rhs.brain;
    }
    return *this;
}

void Dog::makeSound() const
{
    std::cout << "Woof woof!" << std::endl;
}
