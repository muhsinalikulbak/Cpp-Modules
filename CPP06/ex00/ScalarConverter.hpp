#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>
#include <iostream>
#include <cmath>
#include <math.h>



class ScalarConverter
{
    typedef enum e_type_status  // Parse fonksiyonları status döndürsün, ona göre ayarla.
    {
        VALID,
        IMPOSSIBLE,
        NON_DISPLAYABLE,
        OVERFLOW_ERR
    } status;

private:
    ScalarConverter();
    static bool intTryParse(double num);
    static bool doubleTryParse(const std::string& str, double& ref);
    static bool floatTryParse(double num);
    static bool charTryParse(double num);

    static void printInt(int num);
    static void printDouble(double num);
    static void printFloat(float num);
    static void printChar(char ch);
    static void printImpossible(const std::string& type);
    static void printSpecial(const std::string& str);

    static bool checkSpecial(double num);
public:
    static void convert(const std::string& str);
};

#endif