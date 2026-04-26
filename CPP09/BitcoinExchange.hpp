#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANHE_HPP

#include <exception>
#include <stdexcept>
#include <fstream>
#include <string>
#include <map>
#include <iostream>

class BitcoinExchange
{

private:

    std::map<std::string, int> dateMap;
    std::string inputDate;
    int intputValue;
    
public:
    BitcoinExchange();
    BitcoinExchange(const BitcoinExchange& other);
    ~BitcoinExchange();

    BitcoinExchange& operator = (const BitcoinExchange& rhs);

    void loadDatabase();
    void processInput(std::ifstream& file);
    
    bool checkValue(const double& value);
    bool checkDate(const std::string& date);
    bool checkDelimiter(const std::string& line);
    class FileError : public std::exception
    {
        public:
            virtual const char* what() const throw();
    };

};





#endif