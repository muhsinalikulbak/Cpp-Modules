#include "RPN.hpp"
#include <iostream>

int main(int argc, char *argv[])
{
    if (argc != 2 || argv[1] == NULL || argv[1][0] == '\0')
    {
        std::cout << "Invalid Argument!";
        return 1;
    }
    std::string input(argv[1]);

    RPN rpn;

    if (!rpn.checkOperator(input) || !rpn.checkFormatRpn(input))
        std::cout << "Error" << std::endl;

    int res = rpn.rpnCalculator(input);
    std::cout << "result : " << res << std::endl;
    return 0;
}
