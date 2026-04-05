#include "Span.hpp"

Span::Span() : _size(0)
{
}

Span::Span(const Span& other)
{
    _size = other._size;
    _vector = other._vector;
}

Span::Span(unsigned int n)
{
    _size = n;
}

Span::~Span()
{

}

Span& Span::operator = (const Span& rhs)
{
    if (this != &rhs)
    {
        _vector = rhs._vector;
        _size = rhs._size;
    }
    return *this;
}

void Span::addNumber(int value)
{
    if (_vector.size() < _size)
        _vector.push_back(value);
    else
        throw CapacityExceededException();
}

void Span::addRange(size_t size, int value)
{
    for (size_t i = 0; i < size; i++)
    {
        addNumber(value);
    }
    
}

int Span::shortestSpan()
{
    // if (_vector.size() < 2) 
    //     throw std::runtime_error("Yetersiz eleman!");

    std::vector<int> sorted = _vector;
    std::sort(sorted.begin(), sorted.end());
    int min = sorted[sorted.size()-1];

    for (size_t i = 1; i < sorted.size(); i++)
    {
        min = std::min(min, sorted[i] - sorted[i-1]);
    }
    return min;
    
}

int Span::longestSpan()
{
    // if (_vector.size() < 2) 
    //     throw std::runtime_error("Yetersiz eleman!");

    std::vector<int> sorted = _vector;
    std::sort(sorted.begin(), sorted.end());

    return sorted[sorted.size()-1] - sorted[0];
}

const char* Span::CapacityExceededException::what() const throw()
{
    return "Capacity exceeded!";
}