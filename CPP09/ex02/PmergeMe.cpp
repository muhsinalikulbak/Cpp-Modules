#include "PmergeMe.hpp"





void PmergeMe::dividedIntoPairs(char **argv)
{
    int i = 1;
    int winner = 0;
    int loser = 0;

    while (argv[i]) 
    {
        winner = std::atoi(argv[i]);
        if (argv[i + 1])
            loser = std::atoi(argv[i + 1]);
        else
        {
            straggler = winner;
            continue;;
        }

        std::pair<int, int> p(winner, loser);

        vectorPairs.push_back(p);
        dequePairs.push_back(p);

        i++;
    }
            
}

void PmergeMe::argvCheck(char **argv)
{
    int i = 1;
    int j = 0;
    long num = 0;

    // Longa çevir overflow'U burada kontrol et.
            // throw std::invalid_argument("Error: Overflow or invalid conversion");

    while (argv[i])
    {
        j = 0;
        if (argv[i][j] == '-')
            j++;
        while (argv[i][j])
        {
            if (!std::isdigit(argv[i][j]))
                throw std::invalid_argument("Invalid Argument");
            j++;
        }
        i++;
    }
}
