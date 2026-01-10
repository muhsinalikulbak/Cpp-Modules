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
    int scale = 1 << _fractionalsBits;
    setRawBits(static_cast<int> (roundf(floatValue * scale)));
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
    float scale = static_cast<float> (1 << _fractionalsBits);
    return static_cast<float> (getRawBits() / scale);
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



// OPERATOR OVERLOADS

bool    Fixed::operator < (const Fixed& rhs)
{
    return this->_fixedPointValue < rhs._fixedPointValue;
}

bool    Fixed::operator > (const Fixed& rhs)
{
    return this->_fixedPointValue > rhs._fixedPointValue;
}

bool    Fixed::operator >= (const Fixed& rhs)
{
    return this->_fixedPointValue >= rhs._fixedPointValue;
}

bool    Fixed::operator <= (const Fixed& rhs)
{
    return this->_fixedPointValue <= rhs._fixedPointValue;
}

bool    Fixed::operator == (const Fixed& rhs)
{
    return this->_fixedPointValue == rhs._fixedPointValue;
}

bool    Fixed::operator != (const Fixed& rhs)
{
    return this->_fixedPointValue != rhs._fixedPointValue;
}


const Fixed    Fixed::operator + (const Fixed& rhs)
{
    Fixed fixed;
    fixed.setRawBits(this->_fixedPointValue + rhs._fixedPointValue);
    return fixed;
}

const Fixed    Fixed::operator - (const Fixed& rhs)
{
    Fixed fixed;
    fixed.setRawBits(this->_fixedPointValue - rhs._fixedPointValue);
    return fixed;
}

const Fixed    Fixed::operator * (const Fixed& rhs)
{
    int scale = 1 << _fractionalsBits;
    Fixed fixed;

    scale = scale * scale;
    fixed.setRawBits(this->_fixedPointValue * rhs._fixedPointValue * scale);
    return fixed;
}

const Fixed    Fixed::operator / (const Fixed& rhs)
{
    int scale = 1 << _fractionalsBits;
    Fixed fixed;

    fixed.setRawBits(this->_fixedPointValue * scale / rhs._fixedPointValue);
    return fixed;
}
