#include <iostream>
#include "Array.hpp"

int main()
{
    Array<int> arr(5);
    
    for (size_t i = 0; i < arr.size(); i++)
        arr[i] = 5;
    
    Array<int> arr2 (135);

    arr2 = arr;
    for (size_t i = 0; i < arr.size(); i++)
        std::cout << arr2[i] << std::endl;
    
}
