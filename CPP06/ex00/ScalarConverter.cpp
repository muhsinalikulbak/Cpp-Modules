#include "ScalarConverter.hpp"


// Parse Functions

ScalarConverter::TypeStatus ScalarConverter::intTryParse(double num)
{
    // limit kullanarak kontrol et
    // Duruma göre impossible ya da valid gönder
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
    
    if (isnan(ref))
        return NOT_A_NUM;
    else if (isinf(ref))
        return INFINITY_NUM;
    return VALID;
}

ScalarConverter::TypeStatus ScalarConverter::floatTryParse(double num)
{
    // limit kullanarak kontrol et
    // Duruma göre impossible ya da valid gönder
}

ScalarConverter::TypeStatus ScalarConverter::charTryParse(double num)
{
    // limit kullanarak kontrol et
    // Duruma göre impossible ya da valid gönder
}


// Print Functions

void ScalarConverter::printInt(double num)
{
    TypeStatus st = intTryParse(num);
}

void ScalarConverter::printDouble(double num, TypeStatus st)
{
    if (st == VALID)
        std::cout << "double : " << num << std::endl;
    else if (st == IMPOSSIBLE)
        std::cout << "double : " << "impossible" << std::endl;
    else if (st == NOT_A_NUM)
        std::cout << "double : " << "nan" << std::endl;
    else if (st == INFINITY_NUM)
        std::cout << "double : " << "inf" << std::endl;
}

void ScalarConverter::printFloat(double num)
{
    TypeStatus st = intTryParse(num);

}

void ScalarConverter::printChar(double num)
{
    TypeStatus st = intTryParse(num);

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
