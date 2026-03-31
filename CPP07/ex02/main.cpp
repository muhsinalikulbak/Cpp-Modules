#include <iostream>
#include "Array.hpp"


int main() 
{
    try 
    {
        std::cout << "--- Basic Construction & Access ---" << std::endl;
        Array<int> numbers(3);
        numbers[0] = 10;
        numbers[1] = 20;
        numbers[2] = 30;
        std::cout << "Original: " << numbers[0] << ", " << numbers[1] << std::endl;

        std::cout << "\n--- Const Access Test ---" << std::endl;
        const Array<int> constNumbers(3);
        std::cout << constNumbers[0] << std::endl;

        std::cout << "\n--- Deep Copy Test (Copy Constructor) ---" << std::endl;
        Array<int> copy(numbers);
        copy[0] = 999;
        std::cout << "Original[0] after copy modified: " << numbers[0] << " (Should be 10)" << std::endl;
        std::cout << "Copy[0]: " << copy[0] << " (Should be 999)" << std::endl;

        std::cout << "\n--- Assignment Operator Test ---" << std::endl;
        Array<int> assigned;
        assigned = numbers;
        assigned[1] = 888;
        std::cout << "Original[1]: " << numbers[1] << " (Should be 20)" << std::endl;
        std::cout << "Assigned[1]: " << assigned[1] << " (Should be 888)" << std::endl;

        std::cout << "\n--- Out of Bounds Test ---" << std::endl;
        std::cout << numbers[5] << std::endl;

    } 
    catch (const std::exception& e)
    {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}
