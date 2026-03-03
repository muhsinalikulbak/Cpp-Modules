#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <string>
#include <exception>

class Bureaucrat;

class AForm
{
private:
    const std::string _name;
    bool _isSigned;
    const int _gradeToSign;
    const int _gradeToExecute;
public:
    AForm();
    AForm(const std::string& name, int gradeToSign, int gradeToExecute);
    AForm(const AForm& other);
    AForm& operator=(const AForm& other);
    virtual ~AForm();

    const std::string& getName() const;
    bool getIsSigned() const;
    int getGradeToSign() const;
    int getGradeToExecute() const;
    void beSigned(const Bureaucrat& bureaucrat);

    class GradeTooHighException : public std::exception
    {
        public:
            virtual const char* what() const throw() {
                return "Grade is too high!";
            }
    };

    class GradeTooLowException : public std::exception
    {
        public:
            virtual const char* what() const throw() {
                return "Grade is too low!";
            }
    };
};

std::ostream& operator<<(std::ostream& os, const AForm& rhs);

#endif
