#include "ClapTrap.hpp"

int main()
{
    std::cout << "--- Robots Construction ---" << std::endl;
    ClapTrap clap("CLP-4");
    ClapTrap trap("TRP-0");

    std::cout << "\n--- Battle Start ---" << std::endl;
    clap.attack("TRP-0");
    trap.takeDamage(clap.getAttackDamage());

    std::cout << "\n--- Energy Depletion Test ---" << std::endl;
    for (int i = 0; i < 11; i++) {
        clap.beRepaired(1);
    }

    std::cout << "\n--- Death Test ---" << std::endl;
    trap.takeDamage(20);
    trap.attack("CLP-4");
    trap.beRepaired(5);

    std::cout << "\n--- Deconstruction ---" << std::endl;
    return 0;
}
