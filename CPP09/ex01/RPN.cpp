#include "RPN.hpp"
#include <iostream>

RPN::RPN()
{}

RPN::~RPN()
{}

RPN::RPN(const RPN& other)
{
    *this = other;
}

RPN& RPN::operator = (const RPN& rhs)
{
    if (this != &rhs)
    {

    }
    return *this;
}

void RPN::checkFormatRpn(std::string& input)
{
    int len = input.size();
    int stack = 0;
    int i = 0;

    while (i < len)
    {
        while (i < len && input[i] == ' ')
            i++;

        if (i == len)
            break;

        if (std::isdigit(input[i]))
            stack++;
        else if (stack > 1)
            stack--;
        else
            throw InvalidExpressionException("Error : Invalid rpn format!");
        i++;
    }
    if (stack != 1)
        throw InvalidExpressionException("Error : Invalid rpn format!");
}

void    RPN::checkOperator(std::string& input)
{
    int len = input.size();
    int i = 0;

    while (i < len)
    {
        while (i < len && input[i] == ' ')
            i++;

        if (i < len &&
            input[i] != '+' && input[i] != '-' &&
            input[i] != '*' && input[i] != '/' &&
            !std::isdigit(input[i]))
                throw InvalidExpressionException(std::string("Error : Invalid operator : ") + input[i]);            
        if (i + 1 < len && input[i + 1] != ' ')
                throw InvalidExpressionException("Error : Invalid syntax!");
        i++;
    }
}

int     RPN::rpnCalculator(std::string& input)
{
    int i = 0;
    int len = input.size();
    int num1 = 0;
    int num2 = 0;
    std::stack<int> numStack;

    while (i < len)
    {
        while (i < len && input[i] == ' ')
            i++;

        if (i == len)
            break;
        
        if (std::isdigit(input[i]))
            numStack.push(input[i] - '0');
        else
        {
            num2 = numStack.top();
            numStack.pop();
            num1 = numStack.top();
            numStack.pop();

            char ch = input[i];

            if (ch == '+')
                    numStack.push(num1 + num2);
            else if (ch == '-')
                numStack.push(num1 - num2);
            else if (ch == '*')
                numStack.push(num1 * num2);
            else if (ch == '/')
            {
                if (num2 == 0)
                    throw InvalidExpressionException("Error : Attempt to divide by zero!");
                numStack.push(num1 / num2);
            }
        }
        i++;
    }
    return numStack.top();
}


const char* RPN::InvalidExpressionException::what() const throw()
{
    return _errorMessage.c_str();
}


