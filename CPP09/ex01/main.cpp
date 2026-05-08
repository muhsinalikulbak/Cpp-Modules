#include "RPN.hpp"
#include <iostream>

int main(int argc, char *argv[])
{
    if (argc != 2 || argv[1] == NULL || argv[1][0] == '\0')
    {
        std::cout << "Invalid Argument!" << std::endl;
        return 1;
    }
    

    std::string input(argv[1]);
    RPN rpn;
    try
    {
        rpn.checkOperator(input);
        rpn.checkFormatRpn(input);
        int res = rpn.rpnCalculator(input);
        
        std::cout << "result : " << res << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    

    return 0;
}
