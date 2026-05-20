#ifndef FORDJOHNSONSORTER_HPP
#define FORDJOHNSONSORTER_HPP

#include <vector>
#include <deque>
#include <utility>
#include <algorithm>

class InputValidator;

class FordJohnsonSorter
{
private:
    std::vector<std::pair<int, int> > vectorPairs;
    std::deque<std::pair<int, int> > dequePairs;
    std::vector<int> mainVector;
    std::deque<int> mainDeque;
    std::vector<int> originalSequence;
    int straggler;
    bool hasStraggler;

    int jacobsthal(int n) const;
    std::vector<int> generateInsertionOrder(int pendSize) const;

    static void mergePairsVector(std::vector<std::pair<int, int> >& arr,
                                 int left,
                                 int mid,
                                 int right);
    static void mergeSortPairsVector(std::vector<std::pair<int, int> >& arr,
                                     int left,
                                     int right);
    static void sortWinnersByMergeVector(std::vector<std::pair<int, int> >& pairs);

    void insertLosersVector(std::vector<int>& sorted,
                            const std::vector<int>& pend,
                            const std::vector<std::pair<int, int> >& pairs) const;
    void insertStragglerVector(std::vector<int>& sorted) const;
    void insertionPhaseVector(std::vector<int>& sorted,
                              const std::vector<int>& pend,
                              const std::vector<std::pair<int, int> >& pairs) const;

    static void mergePairsDeque(std::deque<std::pair<int, int> >& arr,
                                int left,
                                int mid,
                                int right);
    static void mergeSortPairsDeque(std::deque<std::pair<int, int> >& arr,
                                    int left,
                                    int right);
    static void sortWinnersByMergeDeque(std::deque<std::pair<int, int> >& pairs);

    void insertLosersDeque(std::deque<int>& sorted,
                           const std::deque<int>& pend,
                           const std::deque<std::pair<int, int> >& pairs) const;
    void insertStragglerDeque(std::deque<int>& sorted) const;
    void insertionPhaseDeque(std::deque<int>& sorted,
                             const std::deque<int>& pend,
                             const std::deque<std::pair<int, int> >& pairs) const;

public:
    FordJohnsonSorter();

    void loadFromValidator(const InputValidator& input);
    void sortVector();
    void sortDeque();

    const std::vector<int>& getSortedVector() const;
    const std::deque<int>& getSortedDeque() const;
    const std::vector<int>& getOriginalSequence() const;
};

#endif