#include <iostream>
#include <string>
#include "iter.hpp"

// Test function 1: Increment an integer

void increment(int &n) 
{
    n++;
}

// Test function 2: Print any type of element

template <typename T>
static void printElement(const T &element) 
{
    std::cout << element << " ";
}

int main() 
{
    // ---- Test 1: Integer Array ----
    std::cout << "Test 1: Integers" << std::endl;
    int intArr[] = {0, 1, 2, 3, 4};

    std::cout << "Original: ";
    iter(intArr, 5, printElement<int>);
    
    std::cout << "\nIncrementing...";
    iter(intArr, 5, increment);
    
    std::cout << "\nResult  : ";
    iter(intArr, 5, printElement<int>);
    std::cout << "\n\n";

    // ---- Test 2: String Array ----
    std::cout << "Test 2: Strings" << std::endl;
    std::string strArr[] = {"C++", "is", "awesome"};
    
    iter(strArr, 3, printElement<std::string>);
    std::cout << "\n\n";

    // ---- Test 3: Const Integer Array ----
    std::cout << "Test 3: Const Integers" << std::endl;
    const int constArr[] = {42, 42, 42};
    
    // Using a function that takes const ref is mandatory for const arrays
    iter(constArr, 3, printElement<int>);
    std::cout << "\n" << std::endl;

    return 0;
}