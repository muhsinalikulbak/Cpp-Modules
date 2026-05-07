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
        *this = rhs;
    return *this;
}

bool RPN::checkFormatRpn(std::string& input)
{
    int len = input.size();
    int stack = 0;
    int i = 0;


    while (i < len)
    {
        while (i < len && input[i] == ' ')
            i++;
        
        if (std::isdigit(input[i]))
            stack++;
        else if (stack > 1)
            stack--;
        else
            return false;
        i++;
    }
    return stack == 1;
}

bool    RPN::checkOperator(std::string& input)
{
    int len = input.size();
    int i = 0;

    while (i < len)
    {
        while (i < len && input[i] == ' ')
            i++;

        if (input[i] != '+' && input[i] != '-' &&
            input[i] != '*' && input[i] != '/' &&
            !std::isdigit(input[i]))
                return false;
            
        if (i + 1 < input.size() && input[i + 1] != ' ')
            return false;
        i++;
    }
    return true;
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
        
        if (std::isdigit(input[i]))
            numStack.push(input[i] - '0');
        else
        {
            num2 = numStack.top();
            numStack.pop();
            num1 = numStack.top();
            numStack.pop();

            switch (input[i])
            {
                case '+':
                    numStack.push(num1 + num2);
                    break;
                case '-':
                    numStack.push(num1 - num2);
                    break;
                case '*':
                    numStack.push(num1 * num2);
                    break;
                case '/':
                   numStack.push(num1 / num2);
                   break;
            }
        }
        i++;
    }
    return numStack.top();
}

// 5 5 * 6 + 7 -
