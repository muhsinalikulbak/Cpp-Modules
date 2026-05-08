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


    void    checkFormatRpn(std::string& input);
    void    checkOperator(std::string& input);
    int     rpnCalculator(std::string& input);

    class InvalidExpressionException : public std::exception 
    {
        private:
            std::string _errorMessage;

        public:

            InvalidExpressionException(const std::string& msg) : _errorMessage(msg) {}
            virtual ~InvalidExpressionException() throw() {}
            virtual const char* what() const throw();
    };

};




#endif



