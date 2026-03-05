#include "ShrubberyCreationForm.hpp"
#include <iostream>
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm()
    : AForm("ShrubberyCreationForm", 145, 137), _target("default")
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
    : AForm("ShrubberyCreationForm", 145, 137), _target(target)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
    : AForm(other), _target(other._target)
{
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
    if (this != &other)
    {
        AForm::operator=(other);
        _target = other._target;
    }
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

void ShrubberyCreationForm::performAction() const
{
    std::string filename = _target + "_shrubbery";
    std::ofstream file(filename.c_str());
    
    if (!file.is_open())
    {
        std::cerr << "Error: Could not create file " << filename << std::endl;
        return;
    }
    
    file << "       ###\n";
    file << "      #o###\n";
    file << "    #####o###\n";
    file << "   #o#\\#|#/###\n";
    file << "    ###\\|/#o#\n";
    file << "     # }|{  #\n";
    file << "       }|{\n";
    file << "       }|{\n";
    file << "\n";
    file << "       ###\n";
    file << "      #o###\n";
    file << "    #####o###\n";
    file << "   #o#\\#|#/###\n";
    file << "    ###\\|/#o#\n";
    file << "     # }|{  #\n";
    file << "       }|{\n";
    file << "       }|{\n";
    
    file.close();
    std::cout << "Shrubbery created in " << filename << std::endl;
}
