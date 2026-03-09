#include "ScalarConverter.hpp"


bool ScalarConverter::checkDigit(const std::string& str)
{
    int dotCount = 0;
    int fCount = 0;
    int plusCount = 0;
    int minusCount = 0;


    for (size_t i = 0; i < str.length(); i++)
    {
        if (str[i] == '.')
            dotCount++;
        else if (str[i] == 'f')
            fCount++;
        else if (plusCount == '+')
            plusCount++;
        else if (minusCount == '-')
            minusCount++;
    }

    if (dotCount > 1 || fCount > 1 || plusCount > 1 || minusCount > 1)
        return false;
    if (minusCount == 1 && plusCount == 1)
        return false;
    if (minusCount == 1 && str[0] != '-')
        return false;
    if (plusCount == 1 && str[0] != '+')
        return false;
    if (dotCount == 1 && (str[0] == '.' || str[str.length() - 1] == '.'))
        return false;
    if (fCount == 1 && str[str.length() - 1] != 'f')
        return false;
    return true;
}

bool ScalarConverter::intTryParse(const std::string& str, int& ref)
{

}

bool ScalarConverter::doubleTryParse(const std::string& str, double& ref)
{
    // strtod (string to double) ve isinf kullan.
    // strtod da diyelim ki double değerini aştı
    // isinf bunu fark eder.
    // Double impossable ise hepsi impossible'dır.
}

bool ScalarConverter::floatTryParse(const std::string& str, float& ref)
{

}

bool ScalarConverter::charTryParse(const std::string& str, char& ref)
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

void ScalarConverter::printImpossible()
{

}


void ScalarConverter::convert(const std::string& str)
{
    int intNum = 0;
    double doubleNum = 0;
    float floatNum = 0;
    char ch = '\0';

    if (str == "nanf" || str == "nan")
    {

    }
    else if (str.length() == 1)
    {
        // Burada bu  0-256 arası bir karakter olduğu anlamına gelir ona göre yazdırma yapılıcak.
    }
    else if (!checkDigit(str))
    {
        // print error ve return ile çık
    }

    if (doubleTryParse(str, doubleNum))
        ;// Yazdır
    // Değilse impossible yaz
    

    

    // önce nan nanf kontrolleri yap, (Araştır)
    // Eğer nan , nanf ise yazdır çık.
    // Değilse double convert dene ve errno kontrol et.
    // Double olabiliyorsa tek tek dönüşümleri yap.
    // Double olamıyorsa hepsi imposseble
}


// Eğer uzunluk tek karakter ise 