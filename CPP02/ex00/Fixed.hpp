#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
private:
    int _fixedNum;
    static int  _fractionals;
    
public:
    Fixed();
    
    ~Fixed();


    int     getRawBits( void ) const;
    void    setRawBits( int const raw );

};



#endif