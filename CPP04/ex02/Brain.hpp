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

    // Getter and Setter for ideas
    std::string getIdeas(int index) const;
    void setIdeas(int index, const std::string& idea);
};

#endif
