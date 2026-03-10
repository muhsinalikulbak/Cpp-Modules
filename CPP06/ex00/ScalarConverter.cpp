#include "ScalarConverter.hpp"


bool ScalarConverter::intTryParse(double num)
{

}

bool ScalarConverter::doubleTryParse(const std::string& str, double& ref)
{
    char* end = NULL;
    std::string s;

    ref = strtod(str.c_str(), &end);
    s = end;

    if (s.length() > 1 || (s.length() == 1 && s[0] != 'f'))
    {
        printImpossible("double");
        printImpossible("float");
        printImpossible("int");
        printImpossible("char");
        return false;
    }
    return true;
}

bool ScalarConverter::floatTryParse(double num)
{

}

bool ScalarConverter::charTryParse(double num)
{

}

void ScalarConverter::printInt(int num)
{

}

void ScalarConverter::printDouble(double num)
{

}

void ScalarConverter::printFloat(float num)
{

}

void ScalarConverter::printChar(char ch)
{

}

void ScalarConverter::printImpossible(const std::string& type)
{
    std::cout << type << ": Impossible" << std::endl;
}

void ScalarConverter::printSpecial(const std::string& str)
{
    std::cout << str << std::endl;
}

bool ScalarConverter::checkSpecial(double num)
{
    if (std::isnan(num))
    {
        // Gerekli çıktılar yazdırılacak
        printSpecial("NAN");
        return false;
    }
    else if (std::isinf(num))
    {
        // Gerekli çıktılar yazdırılacak
        printSpecial("INF");
        return false;
    }
    return true;
}


// Bu egzersiz çevriliyorsa hepsini yazdırıyor.
// Eğer sayıyı getirmemizi isteyseydi ilgili fonksiyon içinde double check yapılıp
// Ardından ilgili tipe (Örneğin int) cast yapılırdı.
// Cast yapılabilirse integer değer geri döndürülürdü.
// Cast yapılamıyorsa hata çıktısı verilir

void ScalarConverter::convert(const std::string& str)
{
    double doubleNum = 0;

    if (str.length() == 1 && !isdigit(str[0]))  // Burada length fonksiyonu std:: ile kullanılamıyor mu ?
    {
        // Tek bir karakterse ve rakam değilse char için char tipte, diğer tipleri ise ASCII tipte yazdırılacak
        // Printable olmayanlar karakterlerde char kısmı yazdırırken char: Non displayable çıktısı verilecek.
        return ;
    }

    if (!doubleTryParse(str, doubleNum))
        return ;
    
    if (checkSpecial(doubleNum))
        return;

    printDouble(doubleNum);

    if (floatTryParse(doubleNum))
        printDouble(doubleNum);
    // else
    
    // if (intTryParse(doubleNum))
        
    
    
}
