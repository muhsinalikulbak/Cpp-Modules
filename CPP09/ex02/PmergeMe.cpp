#include "PmergeMe.hpp"

PmergeMe::PmergeMe() : vectorTime(0), dequeTime(0)
{
}

double PmergeMe::getTimeInMicroseconds(struct timeval start,
                                      struct timeval end) const
{
    return (end.tv_sec - start.tv_sec) * 1000000.0 +
           (end.tv_usec - start.tv_usec);
}

void PmergeMe::measureSort()
{
    struct timeval start;
    struct timeval end;

    gettimeofday(&start, NULL);
    sorter.sortVector();
    gettimeofday(&end, NULL);
    vectorTime = getTimeInMicroseconds(start, end);

    gettimeofday(&start, NULL);
    sorter.sortDeque();
    gettimeofday(&end, NULL);
    dequeTime = getTimeInMicroseconds(start, end);
}

void PmergeMe::display(const std::vector<int>& before,
                      const std::vector<int>& after,
                      double timeVector,
                      double timeDeque)
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
              << " elements with std::vector : " << std::fixed
              << std::setprecision(5) << timeVector << " us" << std::endl;
    std::cout << "Time to process a range of " << before.size()
              << " elements with std::deque : " << std::fixed
              << std::setprecision(5) << timeDeque << " us" << std::endl;
}



void PmergeMe::run(char **argv)
{
    validateArguments(argv);
    sorter.buildWinnerLoserPairs(argv);
    measureSort();
    display(sorter.getOriginalSequence(), sorter.getSortedVector(),
            vectorTime, dequeTime);
}


void PmergeMe::validateArguments(char **argv)
{
    int i = 1;
    long value;
    char *end;
    errno = 0;
    std::set<int> argvSet;

    if (argv == NULL)
        throw std::invalid_argument("Invalid Argument!");

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
            throw std::invalid_argument("Invalid Argument");

        if (value > std::numeric_limits<int>::max() ||
            value < std::numeric_limits<int>::min())
            throw std::invalid_argument("Overflow Exception");

        if (value < 0)
            throw std::invalid_argument("Number cannot be negative");

        if (!argvSet.insert(static_cast<int>(value)).second)
            throw std::invalid_argument("Repeating number detected!");

        i++;
    }
}
