// FordJohnsonSorter.cpp, Ford-Johnson algoritmasının sıralama çekirdeğidir.
// Bu dosya winner/loser çiftlerini işler, Jacobsthal sırasını üretir ve
// sınırlı lower_bound yerleştirme adımlarını doğrudan sınıf üyeleriyle yönetir.
#include "FordJohnsonSorter.hpp"
#include "InputValidator.hpp"

FordJohnsonSorter::FordJohnsonSorter()
    : vectorPairs(NULL), dequePairs(NULL), originalSequence(NULL),
      straggler(NULL), hasStraggler(NULL)
{
}

void FordJohnsonSorter::loadFromValidator(InputValidator& input)
{
    vectorPairs = &input.getVectorPairs();
    dequePairs = &input.getDequePairs();
    originalSequence = &input.getOriginalSequence();
    straggler = &input.getStraggler();
    hasStraggler = &input.getHasStraggler();

    mainVector.clear();
    mainDeque.clear();
    vectorPend.clear();
    dequePend.clear();
}

int FordJohnsonSorter::jacobsthal(int n) const
{
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;

    int prev2 = 0;
    int prev1 = 1;
    int current = 0;

    for (int i = 2; i <= n; ++i)
    {
        current = prev1 + 2 * prev2;
        prev2 = prev1;
        prev1 = current;
    }
    return current;
}

std::vector<int> FordJohnsonSorter::generateInsertionOrder(int pendSize) const
{
    std::vector<int> order;

    if (pendSize <= 1)
        return order;

    int jacobIndex = 3;
    int lastJacob = 1;

    while (lastJacob < pendSize)
    {
        int currentJacob = jacobsthal(jacobIndex);

        if (currentJacob > pendSize)
            currentJacob = pendSize;

        for (int i = currentJacob; i > lastJacob; --i)
            order.push_back(i);

        lastJacob = currentJacob;
        jacobIndex++;
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
        int winnerValue = (*vectorPairs)[pendIndex].first;

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
                                                      *straggler);
    mainVector.insert(pos, *straggler);
}

void FordJohnsonSorter::insertionPhaseVector()
{
    if (vectorPend.empty())
    {
        if (*hasStraggler)
            insertStragglerVector();
        return;
    }

    mainVector.insert(mainVector.begin(), vectorPend[0]);
    insertLosersVector();

    if (*hasStraggler)
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
        int winnerValue = (*dequePairs)[pendIndex].first;

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
                                                     *straggler);
    mainDeque.insert(pos, *straggler);
}

void FordJohnsonSorter::insertionPhaseDeque()
{
    if (dequePend.empty())
    {
        if (*hasStraggler)
            insertStragglerDeque();
        return;
    }

    mainDeque.insert(mainDeque.begin(), dequePend[0]);
    insertLosersDeque();

    if (*hasStraggler)
        insertStragglerDeque();
}

void FordJohnsonSorter::sortVector()
{
    if (vectorPairs == NULL || originalSequence == NULL)
        return;

    if (originalSequence->size() <= 1 || vectorPairs->empty())
        return;

    mainVector.clear();
    vectorPend.clear();

    sortWinnersByMergeVector(*vectorPairs);

    for (size_t i = 0; i < vectorPairs->size(); ++i)
    {
        mainVector.push_back((*vectorPairs)[i].first);
        vectorPend.push_back((*vectorPairs)[i].second);
    }

    insertionPhaseVector();
}

void FordJohnsonSorter::sortDeque()
{
    if (dequePairs == NULL || originalSequence == NULL)
        return;

    if (originalSequence->size() <= 1 || dequePairs->empty())
        return;

    mainDeque.clear();
    dequePend.clear();

    sortWinnersByMergeDeque(*dequePairs);

    for (size_t i = 0; i < dequePairs->size(); ++i)
    {
        mainDeque.push_back((*dequePairs)[i].first);
        dequePend.push_back((*dequePairs)[i].second);
    }

    insertionPhaseDeque();
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
    return *originalSequence;
}