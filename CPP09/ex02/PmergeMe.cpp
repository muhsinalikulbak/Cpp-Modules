#include "PmergeMe.hpp"

// Vector-specific merge for winner-sorted pairs.
void PmergeMe::mergePairsVector(std::vector<std::pair<int, int> >& arr, int left, int mid, int right)
{
    std::vector<std::pair<int, int> > temp;
    for (int i = left; i <= mid; ++i)
        temp.push_back(arr[i]);
    for (int i = mid + 1; i <= right; ++i)
        temp.push_back(arr[i]);

    int i = 0;
    int j = mid - left + 1;
    int k = left;

    while (i <= mid - left && j <= right - left)
    {
        if (temp[i].first <= temp[j].first)
        {
            arr[k] = temp[i];
            ++i;
        }
        else
        {
            arr[k] = temp[j];
            ++j;
        }
        ++k;
    }

    while (i <= mid - left)
    {
        arr[k] = temp[i];
        ++i;
        ++k;
    }

    while (j <= right - left)
    {
        arr[k] = temp[j];
        ++j;
        ++k;
    }
}

void PmergeMe::mergeSortPairsVector(std::vector<std::pair<int, int> >& arr, int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;
        mergeSortPairsVector(arr, left, mid);
        mergeSortPairsVector(arr, mid + 1, right);
        mergePairsVector(arr, left, mid, right);
    }
}

// Deque-specific merge for winner-sorted pairs.
void PmergeMe::mergePairsDeque(std::deque<std::pair<int, int> >& arr, int left, int mid, int right)
{
    std::deque<std::pair<int, int> > temp;
    for (int i = left; i <= mid; ++i)
        temp.push_back(arr[i]);
    for (int i = mid + 1; i <= right; ++i)
        temp.push_back(arr[i]);

    int i = 0;
    int j = mid - left + 1;
    int k = left;

    while (i <= mid - left && j <= right - left)
    {
        if (temp[i].first <= temp[j].first)
        {
            arr[k] = temp[i];
            ++i;
        }
        else
        {
            arr[k] = temp[j];
            ++j;
        }
        ++k;
    }

    while (i <= mid - left)
    {
        arr[k] = temp[i];
        ++i;
        ++k;
    }

    while (j <= right - left)
    {
        arr[k] = temp[j];
        ++j;
        ++k;
    }
}

void PmergeMe::mergeSortPairsDeque(std::deque<std::pair<int, int> >& arr, int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;
        mergeSortPairsDeque(arr, left, mid);
        mergeSortPairsDeque(arr, mid + 1, right);
        mergePairsDeque(arr, left, mid, right);
    }
}

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
        this->originalSequence = rhs.originalSequence;
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
        originalSequence.push_back(winner);
        
        if (argv[i + 1])
        {
            loser = std::atoi(argv[i + 1]);
            originalSequence.push_back(loser);
        }
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
    std::set<int> argvSet;

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

        if (!argvSet.insert(value).second) // Bunun yerine en aşağıda set.size() != argc -1 yapabilirim, hız farkı olursa yap
            throw std::invalid_argument("Repeating number detected!");

        i++;
    }
}

void PmergeMe::sortVector()
{
    mainVector.clear();


    if (vectorPairs.size() > 1)
        PmergeMe::mergeSortPairsVector(vectorPairs, 0, vectorPairs.size() - 1);
    
    
    for (size_t i = 0; i < vectorPairs.size(); ++i)
    {
        mainVector.push_back(vectorPairs[i].first);
    }
    if (vectorPairs.size() == 0 && hasStraggler)
        mainVector.push_back(straggler);
}

void PmergeMe::sortDeque()
{
    mainDeque.clear();

    // Sort pairs by winner (first element) using merge-sort
    // Pair bonds remain intact during sorting
    if (dequePairs.size() > 1)
        PmergeMe::mergeSortPairsDeque(dequePairs, 0, dequePairs.size() - 1);
    
    // Extract winners (losers will be inserted in next phase)
    for (size_t i = 0; i < dequePairs.size(); ++i)
    {
        mainDeque.push_back(dequePairs[i].first);
    }
    if (dequePairs.size() == 0 && hasStraggler)
        mainDeque.push_back(straggler);
}

void PmergeMe::run(char **argv)
{
    struct timeval startVector, endVector, startDeque, endDeque;

    argvCheck(argv);
    dividedIntoPairs(argv);

    
    gettimeofday(&startVector, NULL);
    sortVector();
    gettimeofday(&endVector, NULL);
    double timeVector = (endVector.tv_sec - startVector.tv_sec) * 1000000.0 +
                        (endVector.tv_usec - startVector.tv_usec);
    
    gettimeofday(&startDeque, NULL);
    sortDeque();
    gettimeofday(&endDeque, NULL);
    double timeDeque = (endDeque.tv_sec - startDeque.tv_sec) * 1000000.0 +
                       (endDeque.tv_usec - startDeque.tv_usec);
    
    display(originalSequence, mainVector, timeVector, timeDeque);
}

void PmergeMe::display(const std::vector<int>& before, const std::vector<int>& after, double timeVector, double timeDeque)
{
    std::cout << "Before: ";
    for (size_t i = 0; i < before.size(); ++i)
    {
        std::cout << before[i];
        if (i < before.size() - 1)
            std::cout << " ";
    }
    std::cout << std::endl;
    
    std::cout << "After: ";
    for (size_t i = 0; i < after.size(); ++i)
    {
        std::cout << after[i];
        if (i < after.size() - 1)
            std::cout << " ";
    }
    std::cout << std::endl;
    
    std::cout << "Time to process a range of " << before.size() 
              << " elements with std::vector : " << std::fixed << std::setprecision(5) << timeVector << " us" << std::endl;
    std::cout << "Time to process a range of " << before.size() 
              << " elements with std::deque : " << std::fixed << std::setprecision(5) << timeDeque << " us" << std::endl;
}
