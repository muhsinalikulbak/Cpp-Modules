#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>
#include <utility>
#include <iostream>
#include <sstream>
#include <cstdlib>
#include <limits>
#include <cerrno>
#include <set>
#include <algorithm>
#include <iterator>
#include <iomanip>
#include <sys/time.h>
#include <sys/time.h>

class PmergeMe
{
private:
    std::vector<std::pair<int, int> > vectorPairs;
    std::deque<std::pair<int, int> > dequePairs;

    std::vector<int> mainVector;
    std::deque<int> mainDeque;
    
    std::vector<int> originalSequence;

    int straggler;
    bool hasStraggler;

    // Private static helper functions for  operations
    static void mergePairsVector(std::vector<std::pair<int, int> >& arr, int left, int mid, int right);
    static void mergeSortPairsVector(std::vector<std::pair<int, int> >& arr, int left, int right);

    static void mergePairsDeque(std::deque<std::pair<int, int> >& arr, int left, int mid, int right);
    static void mergeSortPairsDeque(std::deque<std::pair<int, int> >& arr, int left, int right);

    static void argvCheck(char **argv);
    static void display(const std::vector<int>& before, const std::vector<int>& after, double timeVector, double timeDeque);


public:
    PmergeMe();
    PmergeMe(const PmergeMe& other);
    ~PmergeMe();

    PmergeMe& operator = (const PmergeMe& rhs);

    void dividedIntoPairs(char **argv);
    void sortVector();
    void sortDeque();
    void run(char **argv);

};

                  

#endif