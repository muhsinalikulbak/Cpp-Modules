#include "Array.hpp"


template <typename T>
Array<T>::Array() : _size(0)
{
    _elements = new T[_size](); // Uzunluk 0 mı olmalı ? yoksa default bir değer mi
}

template <typename T>
Array<T>::Array(unsigned int n) : _size(n)
{
    _elements = new T[_size]();
    // C++ de array oluştururken köşeli parantezin yanına koyulan parantez 
    // Dizinin tipine göre tüm elemanları default değer ile doldurur
    // Örneğin int için 0, char için '\0' değeri
}

template <typename T>
Array<T>::Array(const Array<T>& other)
{   
    _size = other.size();
    _elements = new T[_size]();

    for (size_t i = 0; i < _size; i++)
        _elements[i] = other[i];
    
}

template <typename T>
Array<T>::~Array()
{
    if (_elements)
        delete[] _elements;
}

template <typename T>
Array<T>& Array<T>::operator = (const Array<T>& rhs)
{
    if (this != &rhs)
    {
        if (_elements)
            delete[] _elements;

        _size = rhs.size();
        _elements = new T[_size]();

        for (size_t i = 0; i < _size; i++)
            _elements[i] = rhs[i];
    }
    return *this;
}

template <typename T>
T& Array<T>::operator [] (unsigned int index)
{
    if (!_elements || index >= _size)
        throw std::out_of_range("Index out of bounds!");

    return _elements[index];
}

template <typename T>
const T& Array<T>::operator [] (unsigned int index) const
{
    if (!_elements || index >= _size)
        throw std::out_of_range("Index out of bounds!");

    return _elements[index];
}


template <typename T>
unsigned int Array<T>::size() const
{
    return _size;
}
