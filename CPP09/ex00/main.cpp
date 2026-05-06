#include "BitcoinExchange.hpp"
#include <iostream>
#include <fstream>

int main(int argc, char const *argv[])
{
    if (argc != 2)
    {
        std::cerr << "Error: Could not open file." << std::endl;
        return 1;
    }

    try
    {
        std::ifstream file(argv[1]);

        if (!file.is_open())
            throw BitcoinExchange::FileError();
            
        BitcoinExchange btc;

        btc.loadDatabase();
        btc.processInput(file);
    }
    catch(std::exception& ex)
    {
        std::cerr << ex.what() << std::endl;
        return 1;
    }
    return 0;
}
