#include "Brain.hpp"
#include <iostream>

Brain::Brain()
{
    std::cout << "Brain Default Constructor Called" << std::endl;
}
Brain::~Brain()
{
    std::cout << "Brain is destroyed" << std::endl;
}

Brain::Brain(const Brain& other)
{
    std::cout << "Brain Copy constructor called" << std::endl;
    for (int i = 0; i < 100; i++)
    {
        ideas[i] = other.ideas[i];
    }
}

Brain& Brain::operator = (const Brain& rhs)
{
    std::cout << "Brain copy assignment opertor called" << std::endl;

    if (this != &rhs)
    {
        for (unsigned int i = 0; i < rhs.ideas->length(); i++)
        {
            ideas[i] = rhs.ideas[i];
        }
    }
    return *this;
}
