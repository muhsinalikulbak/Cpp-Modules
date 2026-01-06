#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
private:
    int _rawBits;
    static const int  _fractionalsBits = 8; 
    // Normalde static değişken deklarasyonu class dışında olur ama eğer static const ise class içerisinde yapılabilir.
    // floating point sayılar dışında diğer primitive type değişkenler için bu kural geçerlidir.
    // Floating point sayılar için sadece deklarasyon yapılır (static const double num; gibi)

public:
    // Canonic Form
    Fixed();
    Fixed(Fixed& fixed);
    ~Fixed();
    Fixed& operator = (Fixed& other);

    // Member Functions
    float   toFloat( void ) const;
    int     toInt( void ) const;

    int     getRawBits( void ) const;
    void    setRawBits( int const raw );

};



#endif