#ifndef DOG_HPP
#define DOG_HPP

#include <string>

class Dog
{
protected:
    std::string type;

public:
    Dog();
    ~Dog();
    Dog(const Dog& other);
    Dog& operator = (const Dog& rhs);

};

#endif
