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

class PmergeMe
{
private:
    std::vector<std::pair<int, int> > vectorPairs;
    std::deque<std::pair<int, int> > dequePairs;

    std::vector<int> mainVector;
    std::deque<int> maindDeque;

    int straggler;
    bool hasStraggler;

public:
    PmergeMe();
    PmergeMe(const PmergeMe& other);
    ~PmergeMe();

    PmergeMe operator = (const PmergeMe& rhs);

    void dividedIntoPairs(char **argv);
    void argvCheck(char **argv);

};



#endif