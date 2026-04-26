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
    std::string strValue;
    double value;

    if (!file.is_open())
        throw BitcoinExchange::FileError();
    
    while (std::getline(file, line))
    {
        if (line.empty())
            continue;

        std::stringstream ss(line);

        // virgüle kadar her şeyi al
        std::getline(ss, date, ',');

        // virgülden sonra her şeyi al
        std::getline(ss, strValue);

        std::stringstream ssValue (strValue);

        if (!(ssValue >> value))
            std::cerr << "Double convert error!" << std::endl;
        
        dateMap[date] = value;
    }

}

void BitcoinExchange::processInput(std::ifstream& file)
{
    std::string line;
    std::string date;
    std::string value;
    size_t      pos;

    while (std::getline(file, line))
    {
        try
        {
            if (line.empty())
                throw std::invalid_argument("Error : ");
            if (checkDelimiter(line));
                throw std::invalid_argument("Error : ");

        
            pos = line.find('|');
            date = line.substr(0, pos);
            value = line.substr(pos + 1);
            

        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
    }
    
}
