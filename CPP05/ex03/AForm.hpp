#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <string>
#include <exception>

class Bureaucrat;

class AForm
{
protected:
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
    void execute(Bureaucrat const & executor) const;
    virtual void performAction() const = 0;

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

    class FormNotSignedException : public std::exception
    {
        public:
            virtual const char* what() const throw() {
                return "Form is not signed!";
            }
    };
};

std::ostream& operator<<(std::ostream& os, const AForm& rhs);

#endif
