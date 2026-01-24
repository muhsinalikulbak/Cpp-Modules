#ifndef CAT_HPP
#define CAT_HPP

#include <string>

class Cat
{
protected:
    std::string type;

public:
    Cat();
    ~Cat();
    Cat(const Cat& other);
    Cat& operator = (const Cat& rhs);

};

#endif
