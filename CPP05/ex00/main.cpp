#include "Bureaucrat.hpp"

int main()
{
    // Valid bureaucrat
    try
    {
        Bureaucrat b("Ali", 75);
        std::cout << b << std::endl;
        b.incrementGrade();
        std::cout << b << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    // Grade too high (0)
    try
    {
        Bureaucrat b("Mehmet", 0);
    }
    catch(const std::exception& e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    // Grade too low (151)
    try
    {
        Bureaucrat b("Fatma", 151);
    }
    catch(const std::exception& e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    // Increment exception (grade 1)
    try
    {
        Bureaucrat b("Hasan", 1);
        std::cout << b << std::endl;
        b.incrementGrade();
    }
    catch(const std::exception& e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    // Decrement exception (grade 150)
    try
    {
        Bureaucrat b("Elif", 150);
        std::cout << b << std::endl;
        b.decrementGrade();
    }
    catch(const std::exception& e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}
