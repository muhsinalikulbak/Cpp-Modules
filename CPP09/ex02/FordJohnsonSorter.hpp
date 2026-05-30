#ifndef FORDJOHNSONSORTER_HPP
#define FORDJOHNSONSORTER_HPP

#include <vector>
#include <deque>
#include <utility>
#include <algorithm>

// FordJohnsonSorter, Ford-Johnson algoritmasının sıralama çekirdeğidir.
// Bu katman, doğrulanmış girdiyi tek seferlik iç kopya olarak alır ve
// Jacobsthal tabanlı insertion akışını kendi üyeleri üzerinden yönetir.

class FordJohnsonSorter
{
private:
    std::vector<std::pair<int, int> > vectorPairs;
    std::deque<std::pair<int, int> > dequePairs;
    std::vector<int> mainVector;
    std::deque<int> mainDeque;
    std::vector<int> vectorPend;
    std::deque<int> dequePend;
    std::vector<int> originalSequence;
    int straggler;
    bool hasStraggler;


    std::vector<int> generateInsertionOrder(int pendSize) const;
    void reset();
    // VECTOR İşlemleri

    static void mergePairsVector(std::vector<std::pair<int, int> >& arr,
                                 int left,
                                 int mid,
                                 int right);

    static void mergeSortPairsVector(std::vector<std::pair<int, int> >& arr,
                                     int left,
                                     int right);

    static void sortWinnersByMergeVector(std::vector<std::pair<int, int> >& pairs);

    void insertLosersVector();

    void insertStragglerVector();

    void insertionPhaseVector();


    // DEQUE İşlemleri

    static void mergePairsDeque(std::deque<std::pair<int, int> >& arr,
                                int left,
                                int mid,
                                int right);

    static void mergeSortPairsDeque(std::deque<std::pair<int, int> >& arr,
                                    int left,
                                    int right);

    static void sortWinnersByMergeDeque(std::deque<std::pair<int, int> >& pairs);

    void insertLosersDeque();

    void insertStragglerDeque();

    void insertionPhaseDeque();

public:
    FordJohnsonSorter();
    
    void buildWinnerLoserPairs(char **argv);


    void sortVector();

    void sortDeque();

    // Sıralanmış vector sonucunu döndürür.
    const std::vector<int>& getSortedVector() const;

    // Sıralanmış deque sonucunu döndürür.
    const std::deque<int>& getSortedDeque() const;

    // Orijinal giriş dizisini döndürür.
    const std::vector<int>& getOriginalSequence() const;
};

#endif
