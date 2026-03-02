#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{



    std::cout << "\n=== FORM TESTS ===" << std::endl;
    
    // Valid form
    try
    {
        Form form1("Tax Form", 50, 25);
        std::cout << form1 << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    // Form grade too high
    try
    {
        Form form2("Invalid Form", 0, 50);
    }
    catch(const std::exception& e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    // Form grade too low
    try
    {
        Form form3("Invalid Form", 151, 50);
    }
    catch(const std::exception& e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    std::cout << "\n=== SIGN FORM TESTS ===" << std::endl;
    
    // Successful signing
    try
    {
        Bureaucrat john("John", 30);
        Form contract("Contract", 50, 25);
        std::cout << contract << std::endl;
        john.signForm(contract);
        std::cout << contract << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    // Failed signing - grade too low
    try
    {
        Bureaucrat intern("Intern", 100);
        Form importantDoc("Important Document", 50, 25);
        std::cout << importantDoc << std::endl;
        intern.signForm(importantDoc);
        std::cout << importantDoc << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    // Edge case -  
    try
    {
        Bureaucrat exactGrade("Exact", 75);
        Form edgeForm("Edge Case Form", 75, 50);
        std::cout << edgeForm << std::endl;
        exactGrade.signForm(edgeForm);
        std::cout << edgeForm << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}
