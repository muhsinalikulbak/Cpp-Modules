#include "Animal.hpp"


Animal::Animal()
{
    std::cout << "Animal Default constructor called" << std::endl;
    type = "Animal";
}

Animal::~Animal()
{
    std::cout << "Animal is destroyed" << std::endl;
}

Animal::Animal(const Animal& other)
{
    std::cout << "Animal copy constructor  called" << std::endl;
    type = other.type;
}

Animal& Animal::operator = (const Animal& rhs)
{
    std::cout << "Animal copy assignment operator called" << std::endl;

    if (this != &rhs)
    {
        this->type = rhs.type;
    }
    return *this;
}

std::string Animal::getType() const
{
    return type;
}
