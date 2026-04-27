#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
    date = "";
    value = 0.0F;
}

BitcoinExchange::~BitcoinExchange()
{

}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other)
{
    this->date = other.date;
    this->value = other.value;
    this->dateMap = other.dateMap;
}

BitcoinExchange& BitcoinExchange::operator = (const BitcoinExchange& rhs)
{
    if (this != &rhs)
    {
        this->date = rhs.date;
        this->value = rhs.value;
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

    for (size_t i = 0; i < line.size(); i++)
    {
        if (line[i] == '|')
            count++;
    }
    return count != 1;
}

void BitcoinExchange::loadDatabase()
{
    std::ifstream file("data.csv");
    std::string line;
    std::string date;
    std::string strValue;
    float value;

    if (!file.is_open())
        throw BitcoinExchange::FileError();
    
    std::getline(file, line);

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
            std::cerr << "Float convert error! : " + strValue << std::endl;
        
        dateMap[date] = value;
    }

}
void BitcoinExchange::isValidValue(const std::string& value)
{
    char* end = NULL;
    std::string suffix;
    float val;

    val = strtof(value.c_str(), &end);
    if (end == value.c_str())
        throw std::invalid_argument("Error: bad input =>" + value);
    
    if (suffix.length() > 1 || (suffix.length() == 1 && (suffix[0] != 'f' && suffix[0] != 'F')))
        throw std::invalid_argument("Error: bad input =>" + value);
    if (std::isnan(val))
        throw std::invalid_argument("Error : not a number");
    if (std::isinf(val) || val > 1000)
        throw std::invalid_argument("Error: too large a number.");
    if (val < 0)
        throw std::invalid_argument("Error: not a positive number.");
}

void BitcoinExchange::isFormatValid(const std::string& date)
{
    if (date.length() != 10)
        throw std::invalid_argument("Error : bad input");

    if (date[4] != '-' || date[7] != '-')
        throw std::invalid_argument("Error : bad input");

    for (int i = 0; i < 10; i++)
    {
        if (i == 4 || i == 7) 
            continue;
        if (!std::isdigit(date[i]))
            throw std::invalid_argument("Error : bat input");
    }
}

void BitcoinExchange::processInput(std::ifstream& file)
{
    std::string line;
    std::string date;
    std::string value;
    size_t      pos;
    // Date        d;

    while (std::getline(file, line))
    {
        try
        {
            if (line.empty())
                throw std::invalid_argument("Error : line is empty");
            if (checkDelimiter(line))
                throw std::invalid_argument("Error : unexpected delimiter");
   
            pos = line.find('|');
            date = trim(line.substr(0, pos));
            value = trim(line.substr(pos + 1));
            
            isValidValue(value);
            // isValidDate()
            

            

        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
    }
}

std::string BitcoinExchange::trim(const std::string& str) 
{
    size_t first = str.find_first_not_of(" \t\n\r");
    if (first == std::string::npos) // String tamamen boşluklardan oluşuyorsa
        return "";
    size_t last = str.find_last_not_of(" \t\n\r");
    return str.substr(first, (last - first + 1));
}
