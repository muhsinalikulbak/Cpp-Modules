#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{
    hasStraggler = false;
    straggler = 0;
}

PmergeMe::PmergeMe(const PmergeMe& other)
{
    *this = other;
}

PmergeMe::~PmergeMe()
{

}


PmergeMe& PmergeMe::operator = (const PmergeMe& rhs)
{
    if (this != &rhs)
    {
        this->dequePairs = rhs.dequePairs;
        this->vectorPairs = rhs.vectorPairs;
        this->mainDeque = rhs.mainDeque;
        this->mainVector = rhs.mainVector;
        this->straggler = rhs.straggler;
        this->hasStraggler = rhs.hasStraggler;
    }
    return *this;
}

void PmergeMe::dividedIntoPairs(char **argv)
{
    int i = 1;
    int winner = 0;
    int loser = 0;
    int temp = 0;

    while (argv[i]) 
    {
        winner = std::atoi(argv[i]);
        if (argv[i + 1])
            loser = std::atoi(argv[i + 1]);
        else
        {
            straggler = winner;
            hasStraggler = true;
            break;
        }

        if (winner < loser)
        {
            temp = winner;
            winner = loser;
            loser = temp;
        }
        
        std::pair<int, int> p(winner, loser);

        vectorPairs.push_back(p);
        dequePairs.push_back(p);

        i+=2;
    }
            
}

void PmergeMe::argvCheck(char **argv)
{
    int i = 1;
    long value;
    char* end;
    
    while (argv[i])
    {
        value = std::strtol(argv[i], &end, 10);
        
        if (errno == ERANGE)
            throw std::invalid_argument("Overflow Exception");
        
        if (end == argv[i])
            throw std::invalid_argument(std::string("Invalid Argument: ") + end);

        while (*end != '\0' && *end == ' ')
            end++;

        if (*end != '\0')
            throw std::invalid_argument("Invalid Argument: Trailing characters found");
        
        if (value > std::numeric_limits<int>::max() || value < std::numeric_limits<int>::min())
            throw std::invalid_argument("Overflow Exception");
        if (value < 0)
            throw std::invalid_argument("Number cannot be negative");        
        i++;
    }
}

void PmergeMe::sortVector()
{
    std::sort(vectorPairs.begin(), vectorPairs.end(), PairComparator());

    for (size_t i = 0; i < vectorPairs.size(); i++)
    {
        mainVector.push_back(vectorPairs[i].first);
        std::cout << vectorPairs[i].first << " ";
    }
    
}

void PmergeMe::sortDeque()
{
    std::sort(dequePairs.begin(), dequePairs.end(), PairComparator());

    for (size_t i = 0; i < dequePairs.size(); i++)
    {
        mainDeque.push_back(dequePairs[i].first);
    }
    
}
