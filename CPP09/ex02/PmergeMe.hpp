#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <iostream>
#include <iomanip>
#include <sys/time.h>

#include <limits>
#include <vector>
#include <deque>
#include <utility>
#include <cstdlib>
#include <cerrno>
#include <set>
#include <stdexcept>

#include "FordJohnsonSorter.hpp"

class PmergeMe
{
private:
    FordJohnsonSorter sorter;
    double vectorTime;
    double dequeTime;

    double getTimeInMicroseconds(struct timeval start, struct timeval end) const;
    void measureSort();
    static void display(const std::vector<int>& before,
                        const std::vector<int>& after,
                        double timeVector,
                        double timeDeque);

public:
    PmergeMe();
    static void validateArguments(char **argv);


    void run(char **argv);
};

#endif