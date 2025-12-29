#include "Fixed.hpp"

Fixed::Fixed()
{
    std::cout << "Default Constructor is called" << std::endl;
    _rawBits = 0;
}
Fixed::Fixed(Fixed& fixed)
{
    std::cout << "Default Copy Constructor is Called" << std::endl;
    setRawBits(fixed.getRawBits());
}
Fixed::~Fixed()
{
    std::cout << "Default Destructor is called" << std::endl;
}

int     Fixed::getRawBits( void ) const
{
    return _rawBits;
}

void    Fixed::setRawBits( int const raw )
{
    _rawBits = raw;
}
