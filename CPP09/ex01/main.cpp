#include "RPN.hpp"
#include <iostream>

int main(int argc, char *argv[])
{
    if (argc != 2 || argv[1] == NULL || argv[1][0] == '\0')
    {
        std::cout << "Invalid Argument!" << std::endl;
        return 1;
    }
    

    try
    {
        std::string input(argv[1]);
        RPN::checkOperator(input);
        RPN::checkFormatRpn(input);
        int res = RPN::rpnCalculator(input);
        
        std::cout << "result : " << res << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    return 0;
}
