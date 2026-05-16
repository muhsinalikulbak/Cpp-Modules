#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>
#include <utility> // pair için gerekli
#include <iostream>
#include <sstream>
#include <cstdlib>
#include <limits>
#include <cerrno>

class PmergeMe
{
private:
    std::vector<std::pair<int, int> > vectorPairs;
    std::deque<std::pair<int, int> > dequePairs;
    int straggler;
    bool hasStraggler; // Bu ismi düzelt

public:
    PmergeMe();
    PmergeMe(const PmergeMe& other);
    ~PmergeMe();

    PmergeMe operator = (const PmergeMe& rhs);

    void dividedIntoPairs(char **argv);
    void argvCheck(char **argv);

};



#endif