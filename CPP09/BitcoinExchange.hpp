#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANHE_HPP

#include <exception>
#include <stdexcept>
#include <fstream>
#include <string>

class BitcoinExchange
{

private:
    /* data */
public:
    BitcoinExchange();
    BitcoinExchange(const BitcoinExchange& other);
    ~BitcoinExchange();

    BitcoinExchange& operator = (const BitcoinExchange& rhs);

    class FileNotFound : public std::exception
    {
        public:
            FileNotFound(const std::string& filename);
            virtual const char* what() const throw();
    };

};





#endif