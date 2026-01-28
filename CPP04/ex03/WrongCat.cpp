#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal()
{
    std::cout << "WrongCat Default constructor called" << std::endl;
    type = "WrongCat";
}

WrongCat::~WrongCat()
{
    std::cout << "WrongCat is destroyed" << std::endl;
}

WrongCat::WrongCat(const WrongCat& other) : WrongAnimal(other)
{
    std::cout << "WrongCat copy constructor  called" << std::endl;
}

WrongCat& WrongCat::operator = (const WrongCat& rhs)
{
    std::cout << "WrongCat copy assignment operator called" << std::endl;

    if (this != &rhs)
    {
        WrongAnimal::operator=(rhs);
        this->type = rhs.type;
    }
    return *this;
}

void WrongCat::makeSound() const
{
    std::cout << "Wrong Meaow!" << std::endl;
}
