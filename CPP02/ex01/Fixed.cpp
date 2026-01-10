#include "Fixed.hpp"

Fixed::Fixed()
{
    std::cout << "Default constructor called" << std::endl;
    _fixedPointValue = 0;
}

Fixed::Fixed(const Fixed& fixed)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = fixed;
}

Fixed::Fixed(const float& floatValue)
{
    std::cout << "Float constructor called" << std::endl;
    int multipFactor = 1 << _fractionalsBits;
    setRawBits(static_cast<int> (roundf(floatValue * multipFactor)));
}

Fixed::Fixed(const int& intValue)
{
    std::cout << "Int constructor called" << std::endl;
    setRawBits(intValue << _fractionalsBits);
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed& other)
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
    float divisionFactor = static_cast<float> (1 << _fractionalsBits);
    return static_cast<float> (getRawBits() / divisionFactor);
}

std::ostream &operator<<(std::ostream & os, const Fixed& rhs)
{
    os << rhs.toFloat();
    return os;
}

int     Fixed::toInt( void ) const
{
    return getRawBits() >> _fractionalsBits;
}

int     Fixed::getRawBits( void ) const
{
    return _fixedPointValue;
}

void    Fixed::setRawBits( int const raw )
{
    _fixedPointValue = raw;
}
