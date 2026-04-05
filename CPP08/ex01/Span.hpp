#ifndef SPAN_HPP
#define SPAN_HPP

#include <algorithm>    
#include <vector>
#include <exception>
#include <iostream>
#include <iterator>


class Span
{
private:
    std::vector<int> _vector;
    unsigned int _size;
    
public:
    Span();
    Span(const Span& other);
    Span(unsigned int n);
    ~Span();

    void addNumber(int value); 
    Span& operator = (const Span& rhs);
    
    int shortestSpan(); 
    int longestSpan();

    class NotEnoughSpaceException : public std::exception
    {
        public:
            virtual const char* what() const throw();
    };

    class NotEnoughElementException : public std::exception
    {
        public:
            virtual const char* what() const throw();
    };

    template <typename iterator>
    void addRange(iterator begin, iterator end)
    {
        if (std::distance(begin, end) + _vector.size() > _size)
            throw NotEnoughSpaceException();
        
        _vector.insert(_vector.end(), begin, end);
    }
};




#endif