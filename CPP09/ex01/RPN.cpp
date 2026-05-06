#include "RPN.hpp"

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

bool    RPN::checkArguments(std::string argv)
{
    for (size_t i = 0; i < argv.length(); i++)
    {
        if (argv[i] != ' ' && argv[i] != '+' && 
            argv[i] != '-' && argv[i] != '*' &&
            argv[i] != '/' && !std::isdigit(argv[i]))
                return false;
    }
    return true;
}

int     RPN::rpnCalculator(std::string argv)
{
    int i;

    i = 0;
    while (i < argv.length())
    {

    }
    
}
