#include "Span.hpp"

int main()
{
    Span span(10);

    span.addNumber(5);
    span.addNumber(6);
    span.addNumber(7);
    span.addNumber(17);

    std::cout << span.longestSpan() << std::endl;
    std::cout << span.shortestSpan() << std::endl;



}
