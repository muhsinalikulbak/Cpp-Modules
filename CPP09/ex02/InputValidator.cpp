#include "InputValidator.hpp"

InputValidator::InputValidator() : straggler(0), hasStraggler(false)
{
}

void InputValidator::reset()
{
    originalSequence.clear();
    vectorPairs.clear();
    dequePairs.clear();
    straggler = 0;
    hasStraggler = false;
}

void InputValidator::validateArguments(char **argv)
{
    int i = 1;
    long value;
    char *end;
    errno = 0;
    std::set<int> argvSet;

    if (argv == NULL)
        throw std::invalid_argument("Invalid Argument!");

    while (argv[i])
    {
        value = std::strtol(argv[i], &end, 10);

        if (errno == ERANGE)
            throw std::invalid_argument("Overflow Exception");

        if (end == argv[i])
            throw std::invalid_argument(std::string("Invalid Argument: ") + end);

        while (*end != '\0' && *end == ' ')
            end++;

        if (*end != '\0')
            throw std::invalid_argument("Invalid Argument");

        if (value > std::numeric_limits<int>::max() ||
            value < std::numeric_limits<int>::min())
            throw std::invalid_argument("Overflow Exception");

        if (value < 0)
            throw std::invalid_argument("Number cannot be negative");

        if (!argvSet.insert(static_cast<int>(value)).second)
            throw std::invalid_argument("Repeating number detected!");

        i++;
    }
}

// Girdiyi winner/loser çiftlerine ayırır.
void InputValidator::buildWinnerLoserPairs(char **argv)
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

const std::vector<int>& InputValidator::getOriginalSequence() const
{
    return originalSequence;
}

const std::vector<std::pair<int, int> >& InputValidator::getVectorPairs() const
{
    return vectorPairs;
}

const std::deque<std::pair<int, int> >& InputValidator::getDequePairs() const
{
    return dequePairs;
}

int InputValidator::getStraggler() const
{
    return straggler;
}

bool InputValidator::getHasStraggler() const
{
    return hasStraggler;
}