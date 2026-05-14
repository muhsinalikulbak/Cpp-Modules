#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>
#include <utility> // pair için gerekli
#include <iostream>


class PmergeMe
{
private:
    std::vector<std::pair<int, int>> vectorPairs;
    std::deque<std::pair<int, int>> dequePairs;
    int straggler;
    bool stragg; // Bu ismi düzelt

public:
    PmergeMe(/* args */);
    ~PmergeMe();
    void dividedIntoPairs(char **argv);
    void argvCheck(char **argv);

};



#endif