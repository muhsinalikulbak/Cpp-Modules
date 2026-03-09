#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>

class ScalarConverter
{
private:
    ScalarConverter();
    static bool checkDigit(const std::string& str);

    static bool intTryParse(const std::string& str, int& ref);
    static bool doubleTryParse(const std::string& str, double& ref);
    static bool floatTryParse(const std::string& str, float& ref);
    static bool charTryParse(const std::string& str, char& ref);

    static void printInt(int num);
    static void printDouble(double num);
    static void printFloat(float num);
    static void printChar(char ch);
    static void printImpossible();


public:
    static void convert(const std::string& str);
};

#endif