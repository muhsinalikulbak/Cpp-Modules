#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANHE_HPP

#include <exception>
#include <stdexcept>
#include <fstream>
#include <string>
#include <map>
#include <iostream>
#include <sstream>
#include <cmath>

struct Date
{
    int year;
    int month;
    int day;
};

class BitcoinExchange
{

private:

    std::map<std::string, int> dateMap;
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
    bool isValidDate(int year, int month, int day);
    std::string trim(const std::string& str);

    bool checkDelimiter(const std::string& line);

    class FileError : public std::exception
    {
        public:
            virtual const char* what() const throw();
    };
};





#endif