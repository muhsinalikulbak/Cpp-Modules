#include "Animal.hpp"    
    
    
Animal::Animal()
{
    std::cout << "Animal is created" << std::endl;
    type = "Animal";
}
Animal::~Animal()
{
    std::cout << "Animal is destroyed" << std::endl;
}
Animal::Animal(const Animal& other)
{
    std::cout << "Animal copy constructor  called" << std::endl;
    *this = other;

}
Animal& Animal::operator = (const Animal& rhs)
{
    std::cout << "Animal copy assignment operator called" << std::endl;
    this->type = rhs.type;
}

void Animal::makeSound() const
{
    std::cout << "Animel called the makeSound() function" << std::endl;
}
