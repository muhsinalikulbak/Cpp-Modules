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
    input.buildWinnerLoserPairs(argv);
    sorter.loadFromValidator(input);
    measureSort();
    display(sorter.getOriginalSequence(), sorter.getSortedVector(),
            vectorTime, dequeTime);
}