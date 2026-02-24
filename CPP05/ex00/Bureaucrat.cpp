#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("")
{
    std::cout << "Called default constructor" << std::endl;
    _grade = 0; 
}

Bureaucrat::~Bureaucrat()
{
    std::cout << "Destructor" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : _name(other._name), _grade(other._grade)
{
    std::cout << "Called copy constructor" << std::endl;
}

Bureaucrat&  Bureaucrat::operator = (Bureaucrat& rhs)
{
    std::cout << "Called copy assignment operator" << std::endl;
    if (this != &rhs)
    {
        _grade = rhs._grade;
    }
}


std::string Bureaucrat::getName() const
{
    return _name;
}

int Bureaucrat::getGrade() const
{
    return _grade;
}

void Bureaucrat::incrementGrade()
{
    _grade--;
}
void Bureaucrat::decrementGrade()
{
    _grade++;
}

std::ostream & operator<<(std::ostream & os, const Bureaucrat& rhs)
{
    
}
