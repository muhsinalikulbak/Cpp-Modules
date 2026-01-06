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

Fixed& Fixed::operator=(Fixed& other)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other)
    {
        _rawBits = other.getRawBits();
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
    return _rawBits;
}

void    Fixed::setRawBits( int const raw )
{
    std::cout << "getRawBits member function called" << std::endl; 
    _rawBits = raw;
}
