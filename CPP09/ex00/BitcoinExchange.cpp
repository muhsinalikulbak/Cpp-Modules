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
        {
            std::cerr << "Float convert error! : " + strValue << std::endl;
            continue;
        }
        
        dateMap[date] = value;
    }

}

bool BitcoinExchange::isLeapYear(int year) 
{
    return (year % 400 == 0) || (year % 4 == 0 && year % 100 != 0);
}

void BitcoinExchange::isValidDate(const std::string& date)
{
    int year;
    int month;
    int day;
    char seperate;

    int months[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    std::stringstream ss (date);
    ss >> year;
    ss >> seperate;

    ss >> month;
    ss >> seperate;
    ss >> day;

    if (month > 12 || month == 0)
        throw std::invalid_argument("Error: bad input => " + date);

    if (month != 2 && day > months[month-1])
        throw std::invalid_argument("Error: bad input => " + date);

    if (month == 2 && isLeapYear(year) &&  day > 29)
        throw std::invalid_argument("Error: bad input => " + date);

    if (month == 2 && !isLeapYear(year) &&  day > 28)
        throw std::invalid_argument("Error: bad input => " + date);

}

void BitcoinExchange::isValidValue(const std::string& value)
{
    char* end = NULL;
    float val;

    val = strtof(value.c_str(), &end);
    if (end == value.c_str())
        throw std::invalid_argument("Error: bad input => " + value);
    
    if (std::string(end).length() > 0)
        throw std::invalid_argument("Error: bad input => " + value);
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
            throw std::invalid_argument("Error: bad input => " + date);

    if (date[4] != '-' || date[7] != '-')
        throw std::invalid_argument("Error: bad input => " + date);

    for (int i = 0; i < 10; i++)
    {
        if (i == 4 || i == 7) 
            continue;
        if (!std::isdigit(date[i]))
            throw std::invalid_argument("Error: bad input => " + date);
    }
}

void BitcoinExchange::processInput(std::ifstream& file)
{
    std::string line;
    std::string date;
    std::string strValue;
    float       value;
    size_t      pos;

    while (std::getline(file, line))
    {
        try
        {
            if (line.empty())
                continue;
   
            pos = line.find('|');
            if (pos == std::string::npos)
                throw std::invalid_argument("Error: bad input => " + line);
            
            date = trim(line.substr(0, pos));
            strValue = trim(line.substr(pos + 1));
            
            isValidValue(strValue);
            std::stringstream(strValue) >> value;

            isFormatValid(date);
            isValidDate(date);

            std::map<std::string, float>::iterator it = dateMap.upper_bound(date);

            if (it == dateMap.begin())
                throw std::invalid_argument("Error: bad input => " + date);
            --it;

            std::cout << date << " => " << value << " = " << value * it->second << std::endl;
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
    if (first == std::string::npos)
        return "";
    size_t last = str.find_last_not_of(" \t\n\r");
    return str.substr(first, (last - first + 1));
}
