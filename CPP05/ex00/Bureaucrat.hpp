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

    class GradeTooHighException : public std::exception
    {
        public:
            virtual const char* what() const throw() {
                return "The bureaucrat's score is very high (cannot be less than 1)!";
            }
    };

    class GradeTooLowException
    {
        public:
            virtual const char* what() const throw(){
                return "The bureaucrat's score is too low (cannot be greater than 150)!";
            }
    };
};

std::ostream & operator<<(std::ostream & os, const Bureaucrat& rhs);


#endif
