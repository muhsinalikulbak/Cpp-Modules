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


    static void    checkFormatRpn(std::string& input);
    static void    checkOperator(std::string& input);
    static int     rpnCalculator(std::string& input);

    class InvalidExpressionException : public std::exception 
    {
        private:
            std::string _errorMessage;

        public:

            InvalidExpressionException(const std::string& msg) throw() : _errorMessage(msg)  {} 
            virtual ~InvalidExpressionException() throw() {}
            virtual const char* what() const throw();
    };

};




#endif



