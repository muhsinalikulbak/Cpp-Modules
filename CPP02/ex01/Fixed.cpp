#include "Fixed.hpp"

Fixed::Fixed()
{
    std::cout << "Default constructor called" << std::endl;
    _fixedPointValue = 0;
}

Fixed::Fixed(const Fixed& fixed)
{
    this->_fixedPointValue = fixed.getRawBits();
    std::cout << "Copy constructor called" << std::endl;
}

Fixed::Fixed(float floatValue)
{
    std::cout << "Float constructor called" << std::endl;
    int multipFactor = 1 << _fractionalsBits;
    setRawBits(std::roundf(floatValue * multipFactor));
}

Fixed::Fixed(int intValue)
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
    // Burası soyutlama için iyidir, eğer fractional bits değişseydi buradaki 256 da değişecekti
    float divisionFactor = 1 << _fractionalsBits;
    return getRawBits() / divisionFactor;
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
