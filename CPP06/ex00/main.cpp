
#include <cmath>
#include <iostream> 
#include <math.h>
#include <stdio.h>
#include <string>
#include "ScalarConverter.hpp"

#include <stdio.h>

int main()
{

    ScalarConverter::convert("sdlkflsdf");
    std::cout << "--------" << std::endl;
    ScalarConverter::convert("123");
    std::cout << "--------" << std::endl;

    ScalarConverter::convert("ç");
    std::cout << "--------" << std::endl;

    ScalarConverter::convert("ğ");
    std::cout << "--------" << std::endl;

    ScalarConverter::convert("a");
    std::cout << "--------" << std::endl;

    ScalarConverter::convert("");
    std::cout << "--------" << std::endl;


    ScalarConverter::convert("33333333333");
    std::cout << "--------" << std::endl;

    ScalarConverter::convert("333333333333333333333333333333333");
    std::cout << "--------" << std::endl;

}
