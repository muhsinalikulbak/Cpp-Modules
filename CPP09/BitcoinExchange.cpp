#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
    inputDate = "";
    intputValue = 0;
}

BitcoinExchange::~BitcoinExchange()
{

}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other)
{
    this->inputDate = other.inputDate;
    this->intputValue = other.intputValue;
    this->dateMap = other.dateMap;
}

BitcoinExchange& BitcoinExchange::operator = (const BitcoinExchange& rhs)
{
    if (this != &rhs)
    {
        this->inputDate = rhs.inputDate;
        this->intputValue = rhs.intputValue;
        this->dateMap = rhs.dateMap;
    }
    return *this;
}

const char* BitcoinExchange::FileError::what() const throw()
{
    return "Error: could not open file.";
}

bool BitcoinExchange::checkDelimiter(const std::string& line)
{
    int count = 0;

    for (int i = 0; i < line.size(); i++)
    {
        if (line[i] == '|')
            count++;
    }
    return count == 1;    
}

void BitcoinExchange::loadDatabase()
{
    std::ifstream file("data.csv");
    std::string line;
    std::string date;
    size_t pos;
    double value;

    if (!file.is_open())
        throw BitcoinExchange::FileError();
    
    while (std::getline(file, line))
    {
        if (line.empty())
            continue;
        if (!checkDelimiter(line))
            continue;
        
        pos = line.find(',');
        if (pos != std::string::npos)
        {
            date = line.substr(0, pos );
            value = static_cast<float>(line.substr(pos+1));
        }
        
        
    }

}

void BitcoinExchange::processInput(std::ifstream& file)
{

    while (true)
    {
        try
        {
            /*  */
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
    }
    
}
