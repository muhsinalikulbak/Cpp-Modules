#include "Fixed.hpp"

Fixed::Fixed()
{
    std::cout << "Default constructor called" << std::endl;
    
}

Fixed::Fixed(Fixed& fixed)
{
    std::cout << "Copy constructor called" << std::endl;
    
}
Fixed::Fixed(float floatValue)
{
    
}

Fixed::Fixed(int intValue)
{
    setRawBits(intValue << 8);
}

Fixed::Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

Fixed& Fixed::operator=(Fixed& other)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other)
    {
        _fixedPointValue = other._fixedPointValue;
    }
    return *this;
}

float   Fixed::toFloat( void ) const
{
    return 1;
}

int     Fixed::toInt( void ) const
{
    return 1;
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
