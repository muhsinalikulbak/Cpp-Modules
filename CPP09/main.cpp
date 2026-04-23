#include "BitcoinExchange.hpp"
#include <iostream>
#include <fstream>

int main(int argc, char const *argv[])
{
    try
    {
        if (argc != 2)
            throw std::invalid_argument("Usage: ./bitcoin_exchange <filename>");
        std::ifstream file;
        file.exceptions(std::ifstream::failbit);    
        file.open(argv[1]);
    }
    catch(const std::ios_base::failure& e)
    {
        std::cerr << "Error: Could not open file '" << argv[1] << "'\n";
    }
    
    // date | value gelicek.
    /*
        Dosya kontrolü yap
        sonra geçerli date ve value kontrolü yap
        Ardından csv deki verileri string, int olarak sakla
        Yani tarih değer olarak.
        Ardından verilen date kontrolü yap varsa o date'deki value ile sonucu getir
        Yoksa eğer verilen date'den küçük olan ilk date'i baz alarak işlem yap.
    */
    return 0;
}
