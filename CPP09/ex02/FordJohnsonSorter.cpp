#include "FordJohnsonSorter.hpp"
#include "InputValidator.hpp"

FordJohnsonSorter::FordJohnsonSorter() : straggler(0), hasStraggler(false)
{
}

void FordJohnsonSorter::loadFromValidator(const InputValidator& input)
{
    vectorPairs = input.getVectorPairs();
    dequePairs = input.getDequePairs();
    originalSequence = input.getOriginalSequence();
    straggler = input.getStraggler();
    hasStraggler = input.getHasStraggler();
    mainVector.clear();
    mainDeque.clear();
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

void FordJohnsonSorter::insertLosersVector(std::vector<int>& sorted,
                                          const std::vector<int>& pend,
                                          const std::vector<std::pair<int, int> >& pairs) const
{
    if (pend.empty())
        return;

    std::vector<int> insertionOrder = generateInsertionOrder(pend.size());

    for (size_t j = 0; j < insertionOrder.size(); ++j)
    {
        int pendIndex = insertionOrder[j] - 1;

        if (pendIndex < 0 || pendIndex >= static_cast<int>(pend.size()))
            continue;

        int loserValue = pend[pendIndex];
        int winnerValue = pairs[pendIndex].first;

        std::vector<int>::iterator winnerPos = std::find(sorted.begin(),
                                                          sorted.end(),
                                                          winnerValue);

        if (winnerPos == sorted.end())
        {
            sorted.insert(sorted.end(), loserValue);
        }
        else
        {
            std::vector<int>::iterator insertPos = std::lower_bound(sorted.begin(),
                                                                     winnerPos,
                                                                     loserValue);
            sorted.insert(insertPos, loserValue);
        }
    }
}

void FordJohnsonSorter::insertStragglerVector(std::vector<int>& sorted) const
{
    std::vector<int>::iterator pos = std::lower_bound(sorted.begin(),
                                                      sorted.end(),
                                                      straggler);
    sorted.insert(pos, straggler);
}

void FordJohnsonSorter::insertionPhaseVector(std::vector<int>& sorted,
                                            const std::vector<int>& pend,
                                            const std::vector<std::pair<int, int> >& pairs) const
{
    if (pend.empty())
    {
        if (hasStraggler)
            insertStragglerVector(sorted);
        return;
    }

    sorted.insert(sorted.begin(), pend[0]);
    insertLosersVector(sorted, pend, pairs);

    if (hasStraggler)
        insertStragglerVector(sorted);
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

void FordJohnsonSorter::insertLosersDeque(std::deque<int>& sorted,
                                         const std::deque<int>& pend,
                                         const std::deque<std::pair<int, int> >& pairs) const
{
    if (pend.empty())
        return;

    std::vector<int> insertionOrder = generateInsertionOrder(pend.size());

    for (size_t j = 0; j < insertionOrder.size(); ++j)
    {
        int pendIndex = insertionOrder[j] - 1;

        if (pendIndex < 0 || pendIndex >= static_cast<int>(pend.size()))
            continue;

        int loserValue = pend[pendIndex];
        int winnerValue = pairs[pendIndex].first;

        std::deque<int>::iterator winnerPos = std::find(sorted.begin(),
                                                         sorted.end(),
                                                         winnerValue);

        if (winnerPos == sorted.end())
        {
            sorted.insert(sorted.end(), loserValue);
        }
        else
        {
            std::deque<int>::iterator insertPos = std::lower_bound(sorted.begin(),
                                                                    winnerPos,
                                                                    loserValue);
            sorted.insert(insertPos, loserValue);
        }
    }
}

void FordJohnsonSorter::insertStragglerDeque(std::deque<int>& sorted) const
{
    std::deque<int>::iterator pos = std::lower_bound(sorted.begin(),
                                                     sorted.end(),
                                                     straggler);
    sorted.insert(pos, straggler);
}

void FordJohnsonSorter::insertionPhaseDeque(std::deque<int>& sorted,
                                           const std::deque<int>& pend,
                                           const std::deque<std::pair<int, int> >& pairs) const
{
    if (pend.empty())
    {
        if (hasStraggler)
            insertStragglerDeque(sorted);
        return;
    }

    sorted.insert(sorted.begin(), pend[0]);
    insertLosersDeque(sorted, pend, pairs);

    if (hasStraggler)
        insertStragglerDeque(sorted);
}

void FordJohnsonSorter::sortVector()
{
    std::vector<std::pair<int, int> > pairs = vectorPairs;
    std::vector<int> pend;

    mainVector = originalSequence;
    if (mainVector.size() <= 1)
        return;

    sortWinnersByMergeVector(pairs);

    mainVector.clear();
    for (size_t i = 0; i < pairs.size(); ++i)
    {
        mainVector.push_back(pairs[i].first);
        pend.push_back(pairs[i].second);
    }

    insertionPhaseVector(mainVector, pend, pairs);
}

void FordJohnsonSorter::sortDeque()
{
    std::deque<std::pair<int, int> > pairs = dequePairs;
    std::deque<int> pend;

    mainDeque.assign(originalSequence.begin(), originalSequence.end());
    if (mainDeque.size() <= 1)
        return;

    sortWinnersByMergeDeque(pairs);

    mainDeque.clear();
    for (size_t i = 0; i < pairs.size(); ++i)
    {
        mainDeque.push_back(pairs[i].first);
        pend.push_back(pairs[i].second);
    }

    insertionPhaseDeque(mainDeque, pend, pairs);
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