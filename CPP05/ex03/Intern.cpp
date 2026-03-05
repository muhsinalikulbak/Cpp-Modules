#include "Intern.hpp"

Intern::Intern()
{

}
Intern::~Intern()
{

}

Intern::Intern(const Intern& other)
{
    (void)other;
}

Intern& Intern::operator = (const Intern& rhs)
{
    (void)rhs;
    return *this;
}


AForm* Intern::createRobotomy(const std::string& target)
{
    return new RobotomyRequestForm(target);   
}
AForm* Intern::createPresidential(const std::string& target)
{
    return new PresidentialPardonForm(target);
}
AForm* Intern::createShrubbery(const std::string& target)
{
    return new ShrubberyCreationForm(target);
}

AForm* Intern::makeForm(const std::string& name, const std::string& target)
{
    std::string names[] = {"presidential pardon", "robotomy request", "shrubbery creation"};    
    AForm* (*func[3]) (const std::string& target);

    func[0] = &createPresidential;
    func[1] = &createRobotomy;
    func[2] = &createShrubbery;


    for (size_t i = 0; i < 3; i++)
    {
        if (names[i] == name)
        {
            std::cout << "Intern creates " << name << std::endl;
            return func[i](target);
        }
    }
    std::cout << name << " is not available." << std::endl;
    return NULL;
}
