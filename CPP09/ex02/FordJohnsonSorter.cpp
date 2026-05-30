#include "FordJohnsonSorter.hpp"

FordJohnsonSorter::FordJohnsonSorter() : straggler(0), hasStraggler(false)
{
}


// Pend boyutuna göre Jacobsthal insertion sırasını üretir (O(n) kompleksite).
// Jacobsthal sayılarını dinamik programlama ile ardışık hesaplar: J(n) = J(n-1) + 2*J(n-2)

std::vector<int> FordJohnsonSorter::generateInsertionOrder(int pendSize) const
{
    std::vector<int> order;
    int prev2;
    int prev1;
    int currentJacob;
    int lastJacob;
    int target;
    int i;

    if (pendSize <= 1)
        return order;

    prev2 = 0;
    prev1 = 1;
    currentJacob = 1;
    lastJacob = 1;

    while (lastJacob < pendSize)
    {
        currentJacob = prev1 + 2 * prev2;
        prev2 = prev1;
        prev1 = currentJacob;

        target = (currentJacob > pendSize) ? pendSize : currentJacob;

        for (i = target; i > lastJacob; --i)
            order.push_back(i);

        lastJacob = target;
    }

    return order;
}


void FordJohnsonSorter::mergePairsVector(std::vector<std::pair<int, int> >& arr,
                                         int left,
                                         int mid,
                                         int right)
{
    std::vector<std::pair<int, int> > temp;
    int i;

    for (i = left; i <= mid; ++i)
        temp.push_back(arr[i]);
    for (i = mid + 1; i <= right; ++i)
        temp.push_back(arr[i]);

    int j = mid - left + 1;
    int k = left;
    i = 0;

    while (i <= mid - left && j <= right - left)
    {
        if (temp[i].first <= temp[j].first)
            arr[k++] = temp[i++];
        else
            arr[k++] = temp[j++];
    }

    while (i <= mid - left)
        arr[k++] = temp[i++];

    while (j <= right - left)
        arr[k++] = temp[j++];
}


void FordJohnsonSorter::mergeSortPairsVector(std::vector<std::pair<int, int> >& arr,
                                             int left,
                                             int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;
        mergeSortPairsVector(arr, left, mid);
        mergeSortPairsVector(arr, mid + 1, right);
        mergePairsVector(arr, left, mid, right);
    }
}


void FordJohnsonSorter::sortWinnersByMergeVector(std::vector<std::pair<int, int> >& pairs)
{
    if (pairs.size() > 1)
        mergeSortPairsVector(pairs, 0, static_cast<int>(pairs.size()) - 1);
}

void FordJohnsonSorter::insertLosersVector()
{
    std::vector<int> insertionOrder;

    if (vectorPend.empty())
        return;

    insertionOrder = generateInsertionOrder(static_cast<int>(vectorPend.size()));

    for (size_t j = 0; j < insertionOrder.size(); ++j)
    {
        int pendIndex = insertionOrder[j] - 1;

        if (pendIndex < 0 || pendIndex >= static_cast<int>(vectorPend.size()))
            continue;

        int loserValue = vectorPend[pendIndex];
        int winnerValue = vectorPairs[pendIndex].first;

        std::vector<int>::iterator winnerPos = std::find(mainVector.begin(),
                                                          mainVector.end(),
                                                          winnerValue);

        if (winnerPos == mainVector.end())
            mainVector.insert(mainVector.end(), loserValue);
        else
        {
            std::vector<int>::iterator insertPos = std::lower_bound(mainVector.begin(),
                                                                     winnerPos,
                                                                     loserValue);
            mainVector.insert(insertPos, loserValue);
        }
    }
}


void FordJohnsonSorter::insertStragglerVector()
{
    std::vector<int>::iterator pos = std::lower_bound(mainVector.begin(),
                                                      mainVector.end(),
                                                      straggler);
    mainVector.insert(pos, straggler);
}


void FordJohnsonSorter::insertionPhaseVector()
{
    if (vectorPend.empty())
    {
        if (hasStraggler)
            insertStragglerVector();
        return;
    }
 
    // Main vector de şu an sıralanmış winner'lar ver
    // İlk winner'ın loser'ı şu an da main chain'deki tüm sayılardan küçük olduğu için
    // İlk loser'ı başa eklemek bedavadır.

    mainVector.insert(mainVector.begin(), vectorPend[0]); // Tekrar ekleme sorunu olmuyor mu ?
    insertLosersVector();

    if (hasStraggler)
        insertStragglerVector();
}


void FordJohnsonSorter::mergePairsDeque(std::deque<std::pair<int, int> >& arr,
                                        int left,
                                        int mid,
                                        int right)
{
    std::deque<std::pair<int, int> > temp;
    int i;

    for (i = left; i <= mid; ++i)
        temp.push_back(arr[i]);
    for (i = mid + 1; i <= right; ++i)
        temp.push_back(arr[i]);

    int j = mid - left + 1;
    int k = left;
    i = 0;

    while (i <= mid - left && j <= right - left)
    {
        if (temp[i].first <= temp[j].first)
            arr[k++] = temp[i++];
        else
            arr[k++] = temp[j++];
    }

    while (i <= mid - left)
        arr[k++] = temp[i++];

    while (j <= right - left)
        arr[k++] = temp[j++];
}


void FordJohnsonSorter::mergeSortPairsDeque(std::deque<std::pair<int, int> >& arr,
                                            int left,
                                            int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;
        mergeSortPairsDeque(arr, left, mid);
        mergeSortPairsDeque(arr, mid + 1, right);
        mergePairsDeque(arr, left, mid, right);
    }
}

void FordJohnsonSorter::sortWinnersByMergeDeque(std::deque<std::pair<int, int> >& pairs)
{
    if (pairs.size() > 1)
        mergeSortPairsDeque(pairs, 0, static_cast<int>(pairs.size()) - 1);
}

void FordJohnsonSorter::insertLosersDeque()
{
    std::vector<int> insertionOrder;

    if (dequePend.empty())
        return;

    insertionOrder = generateInsertionOrder(static_cast<int>(dequePend.size()));

    for (size_t j = 0; j < insertionOrder.size(); ++j)
    {
        int pendIndex = insertionOrder[j] - 1;

        if (pendIndex < 0 || pendIndex >= static_cast<int>(dequePend.size()))
            continue;

        int loserValue = dequePend[pendIndex];
        int winnerValue = dequePairs[pendIndex].first;

        std::deque<int>::iterator winnerPos = std::find(mainDeque.begin(),
                                                         mainDeque.end(),
                                                         winnerValue);

        if (winnerPos == mainDeque.end())
            mainDeque.insert(mainDeque.end(), loserValue);
        else
        {
            std::deque<int>::iterator insertPos = std::lower_bound(mainDeque.begin(),
                                                                    winnerPos,
                                                                    loserValue);
            mainDeque.insert(insertPos, loserValue);
        }
    }
}

void FordJohnsonSorter::insertStragglerDeque()
{
    std::deque<int>::iterator pos = std::lower_bound(mainDeque.begin(),
                                                     mainDeque.end(),
                                                     straggler);
    mainDeque.insert(pos, straggler);
}

void FordJohnsonSorter::insertionPhaseDeque()
{
    if (dequePend.empty())
    {
        if (hasStraggler)
            insertStragglerDeque();
        return;
    }

    mainDeque.insert(mainDeque.begin(), dequePend[0]);
    insertLosersDeque();

    if (hasStraggler)
        insertStragglerDeque();
}

void FordJohnsonSorter::sortVector()
{
    if (originalSequence.size() <= 1 || vectorPairs.empty())
    {
        mainVector = originalSequence;
        return;
    }

    sortWinnersByMergeVector(vectorPairs);

    for (size_t i = 0; i < vectorPairs.size(); ++i)
    {
        mainVector.push_back(vectorPairs[i].first);
        vectorPend.push_back(vectorPairs[i].second);
    }

    insertionPhaseVector();
}

void FordJohnsonSorter::sortDeque()
{
    if (originalSequence.size() <= 1 || dequePairs.empty())
    {
        mainDeque.assign(originalSequence.begin(), originalSequence.end());
        return;
    }

    sortWinnersByMergeDeque(dequePairs);

    for (size_t i = 0; i < dequePairs.size(); ++i)
    {
        mainDeque.push_back(dequePairs[i].first);
        dequePend.push_back(dequePairs[i].second);
    }

    insertionPhaseDeque();
}

void FordJohnsonSorter::reset()
{
    vectorPairs.clear();
    dequePairs.clear();
    mainVector.clear();
    mainDeque.clear();
    vectorPend.clear();
    dequePend.clear();
    originalSequence.clear();
    straggler = 0;
    hasStraggler = false;
}

void FordJohnsonSorter::buildWinnerLoserPairs(char **argv)
{
    int i = 1;
    int winner;
    int loser;
    int temp;

    reset();

    while (argv[i])
    {
        winner = std::atoi(argv[i]);
        originalSequence.push_back(winner);

        if (argv[i + 1])
        {
            loser = std::atoi(argv[i + 1]);
            originalSequence.push_back(loser);
        }
        else
        {
            straggler = winner;
            hasStraggler = true;
            break;
        }

        if (winner < loser)
        {
            temp = winner;
            winner = loser;
            loser = temp;
        }

        vectorPairs.push_back(std::make_pair(winner, loser));
        dequePairs.push_back(std::make_pair(winner, loser));

        i += 2;
    }
}

const std::vector<int>& FordJohnsonSorter::getSortedVector() const
{
    return mainVector;
}

const std::deque<int>& FordJohnsonSorter::getSortedDeque() const
{
    return mainDeque;
}

const std::vector<int>& FordJohnsonSorter::getOriginalSequence() const
{
    return originalSequence;
}
