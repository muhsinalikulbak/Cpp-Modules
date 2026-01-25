    
#include "Cat.hpp"

Cat::Cat()
{
    std::cout << "Cat is created" << std::endl;
    type = "Animal";
}
Cat::~Cat()
{
    std::cout << "Cat is destroyed" << std::endl;
}
Cat::Cat(const Cat& other)
{
    std::cout << "Cat copy constructor  called" << std::endl;
    *this = other;

}
Cat& Cat::operator = (const Cat& rhs)
{
    std::cout << "Cat copy assignment operator called" << std::endl;
    this->type = rhs.type;
}

void Cat::makeSound() const
{
    std::cout << "Meaow!" << std::endl;
}
