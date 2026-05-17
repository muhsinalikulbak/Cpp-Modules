#include "PmergeMe.hpp"
#include <iostream>

int main(int argc, char  *argv[])
{
    if (argc < 2 || argv == NULL)
    {
        std::cout << "Invalid Argument!" << std::endl;
        return 1;
    }

    try
    {
        PmergeMe merge;
        merge.argvCheck(argv);
        merge.run(argv);
    }
    catch(const std::exception& e)
    {
        std::cerr << "Error" << std::endl;
    }
    
    return 0;
}
