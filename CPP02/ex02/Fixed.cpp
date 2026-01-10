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

bool    Fixed::operator < (const Fixed& rhs) const
{
    return this->_fixedPointValue < rhs._fixedPointValue;
}

bool    Fixed::operator > (const Fixed& rhs) const
{
    return this->_fixedPointValue > rhs._fixedPointValue;
}

bool    Fixed::operator >= (const Fixed& rhs) const
{
    return this->_fixedPointValue >= rhs._fixedPointValue;
}

bool    Fixed::operator <= (const Fixed& rhs) const
{
    return this->_fixedPointValue <= rhs._fixedPointValue;
}

bool    Fixed::operator == (const Fixed& rhs) const
{
    return this->_fixedPointValue == rhs._fixedPointValue;
}

bool    Fixed::operator != (const Fixed& rhs) const
{
    return this->_fixedPointValue != rhs._fixedPointValue;
}


Fixed   Fixed::operator + (const Fixed& rhs) const
{
    Fixed fixed;
    fixed.setRawBits(this->_fixedPointValue + rhs._fixedPointValue);
    return fixed;
}

Fixed   Fixed::operator - (const Fixed& rhs) const
{
    Fixed fixed;
    fixed.setRawBits(this->_fixedPointValue - rhs._fixedPointValue);
    return fixed;
}

Fixed   Fixed::operator * (const Fixed& rhs) const
{
    int scale = 1 << _fractionalsBits;
    Fixed fixed;

    // Burada scale'e bölmemizin sebebi scale'in scale^2 olarak büyümesini önlemektir.
    // yani aslında 256 value içerisinde vardır -- > (raw_a * 256) * (raw_b * 256)
    // Ölçeklenmiş sayı raw * 256 olarak düşünebiliriz
    // Çarpmayı direk yaparsak eğer 256 ölçeği --> 256^2 olacaktır
    // O yüzden 256'ya bölerek scale'in yine 256 olarak kalmasını sağlıyoruz.
    fixed.setRawBits(this->_fixedPointValue * rhs._fixedPointValue / scale);
    return fixed;
}

Fixed   Fixed::operator / (const Fixed& rhs) const
{
    int scale = 1 << _fractionalsBits;
    Fixed fixed;

    // Aynı şekilde de burada ölçek (raw_a * 256) / (raw_b * 256) yapınca ölçekler
    // kaybolacağı için tekrar ölçekle çarpıyoruz.
    // Nasıl ki çarpmada ölçek büyüyorsa scale^2 burada da ölçek kayboluyor.

    fixed.setRawBits(this->_fixedPointValue / rhs._fixedPointValue * scale);
    return fixed;
}


// Increment-Decrement Overloads

// Prefix
Fixed& Fixed::operator++()
{
    _fixedPointValue++;
    return *this;
}

Fixed& Fixed::operator--()
{
    _fixedPointValue--;
    return *this;
}

// Postfix
Fixed Fixed::operator++(int)
{
    Fixed prev = *this;
    _fixedPointValue++;
    return prev;
}

Fixed Fixed::operator--(int)
{
    Fixed prev = *this;
    _fixedPointValue--;
    return prev;
}


// Function Overloads
Fixed&  Fixed::min(Fixed& f1, Fixed& f2)
{
    return f1 < f2 ? f1 : f2;
}

const Fixed& Fixed::min(const Fixed& f1, const Fixed& f2)
{
    return f1 < f2 ? f1 : f2;
}


Fixed& Fixed::max (Fixed& f1, Fixed& f2)
{
    return f1 > f2 ? f1 : f2;
}

const Fixed& Fixed::max (const Fixed& f1, const Fixed& f2)
{
    return f1 > f2 ? f1 : f2;
}
