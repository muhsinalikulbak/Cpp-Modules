    
#include "Cat.hpp"

Cat::Cat() : Animal()
{
    std::cout << "Cat Default constructor called" << std::endl;
    type = "Cat";
}
Cat::~Cat()
{
    std::cout << "Cat is destroyed" << std::endl;
}

Cat::Cat(const Cat& other) : Animal(other)
{
    std::cout << "Cat copy constructor  called" << std::endl;
}

Cat& Cat::operator = (const Cat& rhs)
{
    std::cout << "Cat copy assignment operator called" << std::endl;

    if (this != &rhs)
    {
        Animal::operator=(rhs);
        this->type = rhs.type;
    }
    return *this;
}

void Cat::makeSound() const
{
    std::cout << "Meaow!" << std::endl;
}
