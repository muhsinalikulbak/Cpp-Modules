#include "Span.hpp"

static void printSection(const std::string &title)
{
    std::cout << "\n=== " << title << " ===" << std::endl;
}

int main()
{
    printSection("Basic Test");
    try
    {
        Span span(5);
        span.addNumber(6);
        span.addNumber(3);
        span.addNumber(17);
        span.addNumber(9);
        span.addNumber(11);

        std::cout << "shortestSpan: " << span.shortestSpan() << std::endl;
        std::cout << "longestSpan : " << span.longestSpan() << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << "Error: " << e.what() << std::endl;
    }

    printSection("Capacity Overflow Test");
    try
    {
        Span small(2);
        small.addNumber(10);
        small.addNumber(20);
        small.addNumber(30);
    }
    catch (const std::exception &e)
    {
        std::cout << "Expected error: " << e.what() << std::endl;
    }

    printSection("Insufficient Elements Test");
    try
    {
        Span single(3);
        single.addNumber(42);
        std::cout << "shortestSpan: " << single.shortestSpan() << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << "Expected error: " << e.what() << std::endl;
    }

    printSection("addRange Test");
    try
    {
        Span rangeSpan(7);
        std::vector<int> values;

        values.push_back(100);
        values.push_back(101);
        values.push_back(102);
        values.push_back(130);

        rangeSpan.addRange(values.begin(), values.end());
        rangeSpan.addNumber(200);
        rangeSpan.addNumber(250);
        rangeSpan.addNumber(205);

        std::cout << "shortestSpan: " << rangeSpan.shortestSpan() << std::endl;
        std::cout << "longestSpan : " << rangeSpan.longestSpan() << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << "Error: " << e.what() << std::endl;
    }

    return 0;
}
