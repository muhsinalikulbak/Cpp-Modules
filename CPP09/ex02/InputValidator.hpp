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

// InputValidator, komut satırı girdisini doğrulayan ve Ford-Johnson
// sıralamasına verilecek normalize edilmiş başlangıç modelini hazırlayan
// giriş katmanıdır.
class InputValidator
{
private:
    std::vector<int> originalSequence;
    std::vector<std::pair<int, int> > vectorPairs;
    std::deque<std::pair<int, int> > dequePairs;
    int straggler;
    bool hasStraggler;

    void reset();
    static void argvCheck(char **argv);

public:
    // Boş ve güvenli bir doğrulayıcı nesne oluşturur.
    InputValidator();

    // argv içeriğini doğrular ve winner/loser çiftlerini çıkarır.
    void validateAndParse(char **argv);

    // Orijinal giriş dizisini döndürür.
    std::vector<int>& getOriginalSequence();
    // Vector tarafı için hazırlanmış winner/loser çiftlerini döndürür.
    std::vector<std::pair<int, int> >& getVectorPairs();
    // Deque tarafı için hazırlanmış winner/loser çiftlerini döndürür.
    std::deque<std::pair<int, int> >& getDequePairs();
    // Tek kalan sayıyı döndürür.
    int& getStraggler();
    // Tek kalan sayı bilgisini döndürür.
    bool& getHasStraggler();
};

#endif