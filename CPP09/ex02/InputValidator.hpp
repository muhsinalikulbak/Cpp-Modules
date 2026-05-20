#ifndef INPUTVALIDATOR_HPP
#define INPUTVALIDATOR_HPP

#include <vector>
#include <deque>
#include <utility>
#include <cstdlib>
#include <limits>
#include <cerrno>
#include <set>
#include <stdexcept>

class InputValidator
{
private:
    std::vector<int> originalSequence;
    std::vector<std::pair<int, int> > vectorPairs;
    std::deque<std::pair<int, int> > dequePairs;
    int straggler;
    bool hasStraggler;

    void reset();

public:
    InputValidator();

    static void validateArguments(char **argv);

    void buildWinnerLoserPairs(char **argv);

    const std::vector<int>& getOriginalSequence() const;
    const std::vector<std::pair<int, int> >& getVectorPairs() const;
    const std::deque<std::pair<int, int> >& getDequePairs() const;
    int getStraggler() const;
    bool getHasStraggler() const;
};

#endif