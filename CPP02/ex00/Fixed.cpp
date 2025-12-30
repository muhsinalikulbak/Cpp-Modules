#include "Fixed.hpp"

Fixed::Fixed()
{
    std::cout << "Default constructor called" << std::endl;
    _rawBits = 0;
}
Fixed::Fixed(Fixed& fixed)
{
    std::cout << "Copy constructor called" << std::endl;
    _rawBits = fixed.getRawBits();
}
Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

int     Fixed::getRawBits( void ) const
{
    std::cout << "getRawBits member function called" << std::endl; 
    return _rawBits;
}

void    Fixed::setRawBits( int const raw )
{
    std::cout << "getRawBits member function called" << std::endl; 
    _rawBits = raw;
}
