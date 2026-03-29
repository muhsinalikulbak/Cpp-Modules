#ifndef ITER_HPP
#define ITER_HPP
#include <cstdlib>
#include <exception>

template <typename T, typename F, typename S>

void iter (T* array, const S& size, F function)
{
    try
    {
        if (size < 0)
            throw std::out_of_range("Size cannot be negative!");
        if (array == NULL)
            throw std::invalid_argument("Array pointer is null!");
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        return;
    }
    
    size_t s = static_cast<size_t>(size);

    for (size_t i = 0; i < s; i++)
        function(array[i]);
}


#endif