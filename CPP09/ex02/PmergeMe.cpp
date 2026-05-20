#include "PmergeMe.hpp"

// PmergeMe.cpp, programın üst seviye yürütme katmanıdır. Bu dosya algoritma
// detaylarına girmez; yalnızca girdi hazırlığı, sıralama süre ölçümü ve
// nihai çıktının sunumundan sorumludur.

// Zaman ölçümlerini sıfırlayarak orkestratörü hazırlar.
PmergeMe::PmergeMe() : vectorTime(0), dequeTime(0)
{
}

// İki zaman damgası arasındaki mikro saniye farkını hesaplar.
double PmergeMe::getTimeInMicroseconds(struct timeval start,
                                      struct timeval end) const
{
    return (end.tv_sec - start.tv_sec) * 1000000.0 +
           (end.tv_usec - start.tv_usec);
}

// Vector ve deque sıralama süresini ayrı ayrı ölçer.
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

// Sıralama öncesi ve sonrası dizileri ile süreleri okunabilir biçimde yazar.
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

// Girdiyi doğrular, sıralayıcıyı besler, süreleri ölçer ve sonucu gösterir.
void PmergeMe::run(char **argv)
{
    input.validateAndParse(argv);
    sorter.loadFromValidator(input);
    measureSort();
    display(sorter.getOriginalSequence(), sorter.getSortedVector(),
            vectorTime, dequeTime);
}