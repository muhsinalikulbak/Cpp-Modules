#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <exception>
#include <stdexcept>
#include <fstream>
#include <string>
#include <map>
#include <iostream>
#include <sstream>
#include <cmath>

class BitcoinExchange
{

private:

    std::map<std::string, float> dateMap;
    std::string date;
    float value; 
    
public:
    BitcoinExchange();
    BitcoinExchange(const BitcoinExchange& other);
    ~BitcoinExchange();

    BitcoinExchange& operator = (const BitcoinExchange& rhs);

    void loadDatabase();
    void processInput(std::ifstream& file);
    
    void isValidValue(const std::string& value);
    void isValidDate(const std::string& date);
    void isFormatValid(const std::string& date);
    bool isLeapYear(int year);


    std::string trim(const std::string& str);

    class FileError : public std::exception
    {
        public:
            virtual const char* what() const throw();
    };
};





#endif