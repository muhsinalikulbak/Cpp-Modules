#ifndef INTERN_HPP
#define INTERN_HPP

#include <string>
#include <iostream>
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern
{
private:
    static AForm* createRobotomy(const std::string& target);
    static AForm* createPresidential(const std::string& target);
    static AForm* createShrubbery(const std::string& target);

public:
    Intern();
    ~Intern();
    Intern(const Intern& other);
    Intern& operator = (const Intern& rhs);
    AForm* makeForm(const std::string& name, const std::string& target);

};


#endif