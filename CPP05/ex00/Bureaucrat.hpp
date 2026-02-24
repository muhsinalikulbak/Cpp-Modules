#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string.h>

class Bureaucrat
{
private:
    const std::string _name;
    int _grade;
public:
    Bureaucrat();
    ~Bureaucrat();
    Bureaucrat(const Bureaucrat& other);
    Bureaucrat&  operator = (Bureaucrat& rhs);

    std::string getName() const;
    int getGrade() const;
    void incrementGrade();
    void decrementGrade();

    
};
std::ostream & operator<<(std::ostream & os, const Bureaucrat& rhs);


#endif