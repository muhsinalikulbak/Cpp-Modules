#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
private:
    static const int  _fractionalsBits = 8;
    int _fixedPointValue;
    // Normalde static değişken deklarasyonu class dışında olur ama eğer static const ise class içerisinde yapılabilir.
    // floating point sayılar dışında diğer primitive type değişkenler için bu kural geçerlidir.
    // Floating point sayılar için sadece deklarasyon yapılır (static const double num; gibi)

public:
    // Canonic Form
    Fixed();
    Fixed(const Fixed& fixed);
    Fixed(const float& floatValue);
    Fixed(const int& intValue);
    ~Fixed();
    Fixed& operator = (const Fixed& other);

    // Member Functions
    float   toFloat( void ) const;
    int     toInt( void ) const;
    int     getRawBits( void ) const;
    void    setRawBits( int const raw );

};

std::ostream & operator<<(std::ostream & o, Fixed const & i);

#endif