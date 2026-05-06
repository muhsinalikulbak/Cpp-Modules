#ifndef RPN_HPP
#define RPN_HPP

#include <string>
#include <stack>
#include <sstream>

class RPN
{
private:
    
public:
    RPN();
    ~RPN();
    RPN(const RPN& other);
    RPN& operator = (const RPN& rhs);

    bool    checkArguments(std::string argv);
    int     rpnCalculator(std::string argv);
};




#endif



