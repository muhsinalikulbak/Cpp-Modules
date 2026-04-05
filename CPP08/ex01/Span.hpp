#ifndef SPAN_HPP
#define SPAN_HPP

#include <algorithm>    
#include <vector>
#include <exception>
#include <iostream>


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

    class CapacityExceededException : public std::exception
    {
        public:
            virtual const char* what() const throw();
    };

    void addRange(size_t size, int value);
    int shortestSpan(); 
    int longestSpan();
};




#endif