#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <iostream>
#include <iomanip>
#include <sys/time.h>

#include "InputValidator.hpp"
#include "FordJohnsonSorter.hpp"

// PmergeMe, uygulamanın dışarıya açılan orkestratör katmanıdır. Girdi
// doğrulama, Ford-Johnson sıralama ve süre ölçümü bu sınıf üzerinden
// birbirine bağlanır.
class PmergeMe
{
private:
    InputValidator input;
    FordJohnsonSorter sorter;
    double vectorTime;
    double dequeTime;

    // İki timeval arasındaki mikro saniye farkını hesaplar.
    double getTimeInMicroseconds(struct timeval start, struct timeval end) const;
    // Vector ve deque sıralama sürelerini ölçer.
    void measureSort();
    // Sonuçları okunabilir biçimde ekrana basar.
    static void display(const std::vector<int>& before,
                        const std::vector<int>& after,
                        double timeVector,
                        double timeDeque);

public:
    // Boş orkestratör nesnesi oluşturur.
    PmergeMe();

    // Tüm akışı çalıştırır.
    void run(char **argv);
};

#endif