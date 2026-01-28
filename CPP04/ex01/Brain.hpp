#ifndef BRAIN_HPP
#define BRAIN_HPP
#include <string>

class Brain
{
public:
    std::string ideas[100];

    // Canonic Form
    Brain();
    ~Brain();
    Brain(const Brain& other);
    Brain& operator = (const Brain& rhs);
};

#endif
