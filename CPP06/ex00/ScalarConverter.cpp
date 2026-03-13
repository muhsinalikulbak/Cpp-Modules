#include "ScalarConverter.hpp"

#include <iomanip>

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
    if (str.length() == 1 && !std::isdigit(str[0]))
    {
        ref = static_cast<double>(str[0]);
        return VALID;
    }

    char* end = NULL;
    std::string suffix;

    ref = std::strtod(str.c_str(), &end);
    if (end == str.c_str())
        return INVALID_INPUT;

    suffix = end;
    if (suffix.length() > 1 || (suffix.length() == 1 && (suffix[0] != 'f' && suffix[0] != 'F')))
        return INVALID_INPUT;

    if (std::isnan(ref))
        return NOT_A_NUM;
    if (std::isinf(ref))
        return INFINITY_NUM;
    return VALID;
}

ScalarConverter::TypeStatus ScalarConverter::floatTryParse(double num)
{
    if (std::isnan(num))
        return NOT_A_NUM;
    if (std::isinf(num))
        return INFINITY_NUM;

    if (num > std::numeric_limits<float>::max() || num < -std::numeric_limits<float>::max())
        return INFINITY_NUM;
    return VALID;
}

ScalarConverter::TypeStatus ScalarConverter::charTryParse(double num)
{
    if (std::isnan(num) || std::isinf(num))
        return IMPOSSIBLE;

    if (num > std::numeric_limits<unsigned char>::max() || num < std::numeric_limits<unsigned char>::min())
        return IMPOSSIBLE;
    return VALID;
}

// Print Functions

void ScalarConverter::printInt(double num)
{
    TypeStatus st = intTryParse(num);

    if (st == VALID)
        std::cout << "int: " << static_cast<int>(num) << std::endl;
    else
        std::cout << "int: impossible" << std::endl;
}

void ScalarConverter::printDouble(double num, TypeStatus st)
{
    if (st == VALID)
    {
        std::cout << "double: ";
        if (std::floor(num) == num) // Sayı aşağı yuvarlanmış haliyle aynı ise bir tam sayıdır. 5.0 == 5  ve 5.2 > 5.0 != 5.2
            std::cout << std::fixed << std::setprecision(1) << num;  // Eğer tam sayı ise sonuna .0 koymak için 
        else
            std::cout << num;
        std::cout.unsetf(std::ios::floatfield);
        std::cout << std::setprecision(6) << std::endl;
    }
    else if (st == NOT_A_NUM)
    {
        std::cout << "double: nan" << std::endl;
    }
    else if (st == INFINITY_NUM)
    {
        std::cout << "double: " << (std::signbit(num) ? "-inf" : "+inf") << std::endl;
    }
}

void ScalarConverter::printFloat(double num)
{
    TypeStatus st = floatTryParse(num);

    if (st == VALID)
    {
        std::cout << "float: ";
        if (std::floor(num) == num)
            std::cout << std::fixed << std::setprecision(1) << static_cast<float>(num);
        else
            std::cout << static_cast<float>(num);
        std::cout << "f";
        std::cout.unsetf(std::ios::floatfield);
        std::cout << std::setprecision(6) << std::endl;
    }
    else if (st == NOT_A_NUM)
    {
        std::cout << "float: nanf" << std::endl;
    }
    else if (st == INFINITY_NUM)
    {
        std::cout << "float: " << (std::signbit(num) ? "-inff" : "+inff") << std::endl;
    }
}

void ScalarConverter::printChar(double num)
{
    TypeStatus st = charTryParse(num);

    if (st == VALID)
    {
        char ch = static_cast<unsigned char>(num);
        if (std::isprint(ch))
            std::cout << "char: '" << ch << "'" << std::endl;
        else
            std::cout << "char: Non displayable" << std::endl;
    }
    else
    {
        std::cout << "char: impossible" << std::endl;
    }
}

void ScalarConverter::printSpecial(const std::string& type, const std::string& str)
{
    std::cout << type << ": " << str << std::endl;
}

void ScalarConverter::convert(const std::string& str)
{
    double doubleNum = 0.0;
    const TypeStatus doubleStatus = doubleTryParse(str, doubleNum);

    if (doubleStatus == INVALID_INPUT)
    {
        printSpecial("char", "impossible");
        printSpecial("int", "impossible");
        printSpecial("float", "impossible");
        printSpecial("double", "impossible");
        return;
    }

    printChar(doubleNum);
    printInt(doubleNum);
    printFloat(doubleNum);
    printDouble(doubleNum, doubleStatus);
}
