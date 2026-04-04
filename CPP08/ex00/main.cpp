#include <iostream>
#include <vector>
#include <list>
#include "easyfind.hpp"

int main() 
{
    // Vector Testi
    std::vector<int> v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(20);


    try 
    {
        std::vector<int>::iterator it = easyfind(v, 20);
        std::cout << "Value is available: " << *it << std::endl;
        
        easyfind(v, 50);
    }
    catch (const std::exception& e) 
    {
        std::cout << "Error: " << e.what() << std::endl;
    }

    return 0;
}