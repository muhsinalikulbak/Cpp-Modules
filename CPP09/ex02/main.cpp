#include "PmergeMe.hpp"
#include <iostream>

int main(int argc, char const *argv[])
{
    if (argc < 2 || argv == NULL)
    {
        std::cout << "Invalid Argument!" << std::endl;
        return 1;
    }


    try
    {
        PmergeMe merge;
        
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    return 0;
}
