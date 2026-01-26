#include "WrongAnimal.hpp"    
    
    
WrongAnimal::WrongAnimal()
{
    std::cout << "WrongAnimal is created" << std::endl;
    type = "WrongAnimal";
}

WrongAnimal::~WrongAnimal()
{
    std::cout << "WrongAnimal is destroyed" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& other)
{
    std::cout << "WrongAnimal copy constructor  called" << std::endl;
    *this = other;
}

WrongAnimal& WrongAnimal::operator = (const WrongAnimal& rhs)
{
    std::cout << "WrongAnimal copy assignment operator called" << std::endl;
    
    if (this != &rhs)
    {
        this->type = rhs.type;
    } 
    return *this;
}

void WrongAnimal::makeSound() const
{
    std::cout << "WrongAnimal called the makeSound() function" << std::endl;
}

std::string WrongAnimal::getType() const
{
    return type;    
}
