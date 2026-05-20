#ifndef FORDJOHNSONSORTER_HPP
#define FORDJOHNSONSORTER_HPP

#include <vector>
#include <deque>
#include <utility>
#include <algorithm>

class InputValidator;

// FordJohnsonSorter, Ford-Johnson algoritmasının tüm matematiksel sıralama
// adımlarını yöneten çekirdek katmandır. Jacobsthal sırası, winner/loser
// ayrımı ve sınırlandırılmış binary search burada toplanır.
class FordJohnsonSorter
{
private:
    std::vector<int> mainVector;
    std::deque<int> mainDeque;
    std::vector<int> vectorPend;
    std::deque<int> dequePend;
    std::vector<std::pair<int, int> >* vectorPairs;
    std::deque<std::pair<int, int> >* dequePairs;
    std::vector<int>* originalSequence;
    int* straggler;
    bool* hasStraggler;

    // Jacobsthal sayısını üretir; insertion düzeninin temelini oluşturur.
    int jacobsthal(int n) const;

    // Pend boyutuna göre Jacobsthal geri-tarama sırası üretir.
    std::vector<int> generateInsertionOrder(int pendSize) const;

    // Vector winner çiftlerini merge sort ile birleştirir.
    static void mergePairsVector(std::vector<std::pair<int, int> >& arr,
                                 int left,
                                 int mid,
                                 int right);

    // Vector çiftleri için recursive merge sort uygular.
    static void mergeSortPairsVector(std::vector<std::pair<int, int> >& arr,
                                     int left,
                                     int right);

    // Vector winner çiftlerini sıraya koyar.
    static void sortWinnersByMergeVector(std::vector<std::pair<int, int> >& pairs);

    // Vector loser'larını kendi winner sınırlarına kadar ekler.
    void insertLosersVector();

    // Vector için tek kalan sayıyı ekler.
    void insertStragglerVector();

    // Vector Ford-Johnson insertion fazını yönetir.
    void insertionPhaseVector();

    // Deque winner çiftlerini merge sort ile birleştirir.
    static void mergePairsDeque(std::deque<std::pair<int, int> >& arr,
                                int left,
                                int mid,
                                int right);

    // Deque çiftleri için recursive merge sort uygular.
    static void mergeSortPairsDeque(std::deque<std::pair<int, int> >& arr,
                                    int left,
                                    int right);

    // Deque winner çiftlerini sıraya koyar.
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

    // Doğrulanmış girdiye doğrudan bağlanır; gereksiz kopya üretmez.
    void loadFromValidator(InputValidator& input);
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