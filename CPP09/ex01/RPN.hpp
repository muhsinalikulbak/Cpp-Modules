#ifndef RPN_HPP
#define RPN_HPP

#include <string>
#include <stack>
#include <sstream>
#include <string.h>

class RPN
{
private:
    
public:
    RPN();
    ~RPN();
    RPN(const RPN& other);
    RPN& operator = (const RPN& rhs);


    bool    checkFormatRpn(std::string& input);
    bool    checkOperator(std::string& input);
    int     rpnCalculator(std::string& input);
    
};




#endif



