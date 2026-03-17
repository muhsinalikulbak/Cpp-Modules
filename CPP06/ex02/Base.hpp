#ifndef BASE_HPP
#define BASE_HPP

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

class Base
{
private:
    
public:
    Base();
    virtual ~Base();
};

Base * generate(void);
void identify(Base* p);
void identify(Base& p);

Base* createA();
Base* createB();
Base* createC();



#endif