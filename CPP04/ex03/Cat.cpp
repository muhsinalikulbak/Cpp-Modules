
#include "Cat.hpp"
#include "Brain.hpp"

Cat::Cat() : Animal()
{
    std::cout << "Cat Default constructor called" << std::endl;
    type = "Cat";
    brain = new Brain();
}

Cat::~Cat()
{
    std::cout << "Cat is destroyed" << std::endl;
    delete brain;
}

Cat::Cat(const Cat& other) : Animal(other)
{
    std::cout << "Cat copy constructor  called" << std::endl;
    this->brain = new Brain(*other.brain);
}

Cat& Cat::operator = (const Cat& rhs)
{
    std::cout << "Cat copy assignment operator called" << std::endl;

    // Burada cat yeni mi açılacak ?
    if (this != &rhs)
    {
        Animal::operator=(rhs);
        *brain = *rhs.brain;
    }
    return *this;
}

void Cat::makeSound() const
{
    std::cout << "Meaow!" << std::endl;
}
