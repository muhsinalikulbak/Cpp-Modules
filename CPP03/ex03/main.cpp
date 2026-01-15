#include "FragTrap.hpp"

int main()
{
    std::cout << "=== CONSTRUCTION PHASE ===" << std::endl;

    FragTrap frag("Fragger");
    std::cout << std::endl;

    std::cout << "=== ATTACK & STATS TEST ===" << std::endl;

    frag.attack("Poor Target");
    frag.takeDamage(50);
    frag.beRepaired(25);
    std::cout << std::endl;

    std::cout << "=== SPECIAL CAPACITY TEST ===" << std::endl;

    frag.highFivesGuys();
    std::cout << std::endl;

    std::cout << "=== DESTRUCTION PHASE ===" << std::endl;

    return 0;
}
