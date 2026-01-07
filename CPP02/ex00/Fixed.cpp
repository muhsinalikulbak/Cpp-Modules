#include "Fixed.hpp"

Fixed::Fixed()
{
    std::cout << "Default constructor called" << std::endl;
    _fixedPointValue = 0;
}

Fixed::Fixed(Fixed& fixed)
{
    std::cout << "Copy constructor called" << std::endl;
    _fixedPointValue = fixed.getRawBits();
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

Fixed& Fixed::operator=(Fixed& other)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other)
    {
        _fixedPointValue = other.getRawBits();
    }
    return *this;
}


int     Fixed::getRawBits( void ) const
{
    std::cout << "getRawBits member function called" << std::endl; 
    return _fixedPointValue;
}

void    Fixed::setRawBits( int const raw )
{
    std::cout << "getRawBits member function called" << std::endl; 
    _fixedPointValue = raw;
}
