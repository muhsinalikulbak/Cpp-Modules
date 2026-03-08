#include "Bureaucrat.hpp"
#include "Intern.hpp"

int main()
{
    Intern intern;
    Bureaucrat boss("Boss", 1);

    std::cout << "--- valid form names ---" << std::endl;
    AForm* f1 = intern.makeForm("robotomy request", "Bender");
    AForm* f2 = intern.makeForm("presidential pardon", "Arthur Dent");
    AForm* f3 = intern.makeForm("shrubbery creation", "home");

    std::cout << "\n--- Executing forms ---" << std::endl;
    boss.signForm(*f1);
    boss.executeForm(*f1);

    boss.signForm(*f2);
    boss.executeForm(*f2);

    boss.signForm(*f3);
    boss.executeForm(*f3);

    std::cout << "\n--- Invalid form name ---" << std::endl;
    AForm* f4 = intern.makeForm("coffee request", "Bender");

    delete f1;
    delete f2;
    delete f3;
    if (f4)
        delete f4;
    
    return 0;
}
