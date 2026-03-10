#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>
#include <iostream>
#include <cmath>
#include <math.h>



class ScalarConverter
{
public:
    static void convert(const std::string& str);

private:
    typedef enum e_TypeStatus
    {
        VALID,
        IMPOSSIBLE,
        NON_DISPLAYABLE,
        INVALID_INPUT,
        NOT_A_NUM,
        INFINITY_NUM
    } TypeStatus;

    ScalarConverter();
    static TypeStatus intTryParse(double num);
    static TypeStatus doubleTryParse(const std::string& str, double& ref);
    static TypeStatus floatTryParse(double num);
    static TypeStatus charTryParse(double num);

    static void printInt(double num);
    static void printDouble(double num, TypeStatus st);
    static void printFloat(double num);
    static void printChar(double num);
    static void printSpecial(const std::string& type, const std::string& str);

};

#endif