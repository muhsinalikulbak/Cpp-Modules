#ifndef FORDJOHNSONSORTER_HPP
#define FORDJOHNSONSORTER_HPP

#include <vector>
#include <deque>
#include <utility>
#include <algorithm>

class InputValidator;

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

    // Pend boyutuna göre Jacobsthal geri-tarama sırasını üretir.
    std::vector<int> generateInsertionOrder(int pendSize) const;

    // Vector çiftlerini winner alanına göre merge sort ile birleştirir.
    static void mergePairsVector(std::vector<std::pair<int, int> >& arr,
                                 int left,
                                 int mid,
                                 int right);

    // Vector çiftleri üzerinde recursive merge sort uygular.
    static void mergeSortPairsVector(std::vector<std::pair<int, int> >& arr,
                                     int left,
                                     int right);

    // Vector winner çiftlerini sıralar.
    static void sortWinnersByMergeVector(std::vector<std::pair<int, int> >& pairs);

    // Vector loser'larını kendi winner sınırlarına kadar ekler.
    void insertLosersVector();

    // Vector için tek kalan sayıyı ekler.
    void insertStragglerVector();

    // Vector Ford-Johnson insertion fazını yönetir.
    void insertionPhaseVector();

    // Deque çiftlerini winner alanına göre merge sort ile birleştirir.
    static void mergePairsDeque(std::deque<std::pair<int, int> >& arr,
                                int left,
                                int mid,
                                int right);

    // Deque çiftleri üzerinde recursive merge sort uygular.
    static void mergeSortPairsDeque(std::deque<std::pair<int, int> >& arr,
                                    int left,
                                    int right);

    // Deque winner çiftlerini sıralar.
    static void sortWinnersByMergeDeque(std::deque<std::pair<int, int> >& pairs);

    // Deque loser'larını kendi winner sınırlarına kadar ekler.
    void insertLosersDeque();

    // Deque için tek kalan sayıyı ekler.
    void insertStragglerDeque();

    // Deque Ford-Johnson insertion fazını yönetir.
    void insertionPhaseDeque();

public:
    // Boş ve güvenli bir sıralayıcı oluşturur.
    FordJohnsonSorter();

    // Doğrulanmış girdiyi sorter iç kopyalarına tek seferlik aktarır.
    void loadFromValidator(const InputValidator& input);

    // Vector sıralama akışını çalıştırır.
    void sortVector();

    // Deque sıralama akışını çalıştırır.
    void sortDeque();

    // Sıralanmış vector sonucunu döndürür.
    const std::vector<int>& getSortedVector() const;

    // Sıralanmış deque sonucunu döndürür.
    const std::deque<int>& getSortedDeque() const;

    // Orijinal giriş dizisini döndürür.
    const std::vector<int>& getOriginalSequence() const;
};

#endif
