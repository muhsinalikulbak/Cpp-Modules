#ifndef DATA_HPP
#define DATA_HPP

#include <string>

struct Data 
{
    int         idNumber;
    std::string name;
    float       value;

    Data(int id);
    Data();
    ~Data();
};

#endif
