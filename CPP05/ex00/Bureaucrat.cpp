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
	return *this;
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
	if (_grade - 1 < 1)
		throw Bureaucrat::GradeTooHighException();
	_grade--;
}

void Bureaucrat::decrementGrade()
{
	if (_grade + 1 > 150)
		throw Bureaucrat::GradeTooLowException();
	_grade++;
}

std::ostream & operator<<(std::ostream & os, const Bureaucrat& rhs)
{
	os << rhs.getName() << ", bureaucrat grade " << rhs.getGrade();
	return os;
}
