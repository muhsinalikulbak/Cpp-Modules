#ifndef FIXED_HPP
#define FIXED_HPP

#include <fstream>
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

    bool    operator < (const Fixed& rhs);
    bool    operator > (const Fixed& rhs);
    bool    operator >= (const Fixed& rhs);
    bool    operator <= (const Fixed& rhs);
    bool    operator == (const Fixed& rhs);
    bool    operator != (const Fixed& rhs);

    const Fixed operator + (const Fixed& rhs);
    const Fixed operator - (const Fixed& rhs);
    const Fixed operator * (const Fixed& rhs);
    const Fixed operator / (const Fixed& rhs);


};

std::ostream & operator<<(std::ostream & os, const Fixed& rhs);
#endif
