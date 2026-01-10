#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
private:
    static const int  _fractionalsBits = 8;
    int _fixedPointValue;


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

    // Operator Overloads

    bool    operator < (const Fixed& rhs) const;
    bool    operator > (const Fixed& rhs) const;
    bool    operator >= (const Fixed& rhs) const;
    bool    operator <= (const Fixed& rhs) const;
    bool    operator == (const Fixed& rhs) const;
    bool    operator != (const Fixed& rhs) const;

    Fixed operator + (const Fixed& rhs) const;
    Fixed operator - (const Fixed& rhs) const;
    Fixed operator * (const Fixed& rhs) const;
    Fixed operator / (const Fixed& rhs) const;

    // Increment-Decrement Overloads

    // Prefix
    Fixed& operator++();
    Fixed& operator--();
    // Postfix
    Fixed operator++(int);
    Fixed operator--(int);

    // Function Overloads
    static Fixed& min(Fixed& f1, Fixed& f2);
    static const Fixed& min(const Fixed& f1, const Fixed& f2);

    static Fixed& max (Fixed& f1, Fixed& f2);
    static const Fixed& max (const Fixed& f1, const Fixed& f2);
};

std::ostream & operator<<(std::ostream & os, const Fixed& rhs);
#endif
