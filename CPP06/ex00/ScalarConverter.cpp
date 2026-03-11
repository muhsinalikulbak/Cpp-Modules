#include "ScalarConverter.hpp"


// Parse Functions

ScalarConverter::TypeStatus ScalarConverter::intTryParse(double num)
{
    if (std::isnan(num) || std::isinf(num))
        return IMPOSSIBLE;
    
    if (num > std::numeric_limits<int>::max() || num < std::numeric_limits<int>::min())
        return IMPOSSIBLE;
    return VALID;
}

ScalarConverter::TypeStatus ScalarConverter::doubleTryParse(const std::string& str, double& ref)
{
    
    if (str.length() == 1 && !isdigit(str[0]))
    {
        ref = static_cast<double>(str[0]);
        return VALID;
    }

    char* end = NULL;
    std::string s;
    
    ref = strtod(str.c_str(), &end);
    s = end;
    
    if (s.length() > 1 || (s.length() == 1 && (s[0] != 'f' && s[0] != 'F')))
        return INVALID_INPUT;
    
    if (std::isnan(ref))
        return NOT_A_NUM;
    else if (std::isinf(ref))
        return INFINITY_NUM;
    return VALID;
}

ScalarConverter::TypeStatus ScalarConverter::floatTryParse(double num)
{
    if (std::isnan(num))
        return NOT_A_NUM;
    else if (std::isinf(num))
        return INFINITY_NUM;

    if (num > std::numeric_limits<float>::max() || -num < std::numeric_limits<float>::max())
        return INFINITY_NUM;
    return VALID;
}

ScalarConverter::TypeStatus ScalarConverter::charTryParse(double num)
{
    if (std::isnan(num) || std::isinf(num))
        return IMPOSSIBLE;
    
    if (num > std::numeric_limits<unsigned char>::max() || num < std::numeric_limits< unsigned char>::min())
        return IMPOSSIBLE;
    return VALID;
}


// Print Functions

void ScalarConverter::printInt(double num)
{
    TypeStatus st = intTryParse(num);

    if (st == VALID)
        std::cout << "int : " << static_cast<int>(num) << std::endl;
    else
        std::cout << "int : " << "impossible" << std::endl;
}

void ScalarConverter::printDouble(double num, TypeStatus st)
{
    if (st == VALID)
        std::cout << "double : " << num << std::endl;
    else if (st == NOT_A_NUM)
        std::cout << "double : " << "nan" << std::endl;
    else if (st == INFINITY_NUM)
        std::cout << "double : " << "inf" << std::endl;
}

void ScalarConverter::printFloat(double num)
{
    TypeStatus st = intTryParse(num);

    if (st == VALID)
        std::cout << "float : " << static_cast<float>(num) << std::endl;
    else if (st == NOT_A_NUM)
        std::cout << "float : " << "nan" << std::endl;
    else if (st == INFINITY_NUM)
        std::cout << "float : " << "inf" << std::endl;
}

void ScalarConverter::printChar(double num)
{
    TypeStatus st = intTryParse(num);
    char ch;

    if (st == VALID)
    {
        ch = static_cast<char>(num);
        if (std::isprint(ch))
            std::cout << "char : " << ch << std::endl;
        else
            std::cout << "char : " << "Non displayable" << std::endl;
    }
    else
        std::cout << "char : " << "impossible" << std::endl;
}


void ScalarConverter::printSpecial(const std::string& type, const std::string& str)
{
    std::cout << type << " : " << str << std::endl;
}

void ScalarConverter::convert(const std::string& str)
{
    double doubleNum = 0;
    TypeStatus doubleStatus = doubleTryParse(str, doubleNum); 


    // Burada str.Length == 0 kontrolü eklenbilir
    if (doubleStatus == INVALID_INPUT)
    {
        printSpecial("double", "Invalid Input");
        printSpecial("float", "Invalid Input");
        printSpecial("int", "Invalid Input");
        printSpecial("char", "Invalid Input");
        return ;
    }

    printDouble(doubleNum, doubleStatus);
    printFloat(doubleNum);
    printInt(doubleNum);
    printChar(doubleNum);


}
