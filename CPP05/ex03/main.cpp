#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main()
{
    try
    {
        // Test ShrubberyCreationForm
        std::cout << "\n=== Testing ShrubberyCreationForm ===" << std::endl;
        Bureaucrat bob("Bob", 100);
        ShrubberyCreationForm shrub("home");
        std::cout << shrub << std::endl;
        bob.signForm(shrub);
        bob.executeForm(shrub);

        // Test RobotomyRequestForm
        std::cout << "\n=== Testing RobotomyRequestForm ===" << std::endl;
        Bureaucrat alice("Alice", 40);
        RobotomyRequestForm robot("Bender");
        std::cout << robot << std::endl;
        alice.signForm(robot);
        alice.executeForm(robot);

        // Test PresidentialPardonForm
        std::cout << "\n=== Testing PresidentialPardonForm ===" << std::endl;
        Bureaucrat charlie("Charlie", 1);
        PresidentialPardonForm pardon("Arthur Dent");
        std::cout << pardon << std::endl;
        charlie.signForm(pardon);
        charlie.executeForm(pardon);

        // Test with low grade bureaucrat
        std::cout << "\n=== Testing with low grade ===" << std::endl;
        Bureaucrat dave("Dave", 150);
        PresidentialPardonForm pardon2("Ford Prefect");
        dave.signForm(pardon2);
        dave.executeForm(pardon2);
    }
    catch (std::exception& e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
