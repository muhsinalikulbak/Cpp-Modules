#include "ScavTrap.hpp"

int main() {
    // 1. Test: Construction and Destruction order
    std::cout << "--- Creating ScavTrap ---" << std::endl;
    ScavTrap scav("Scavy");

    std::cout << "\n--- Action Tests ---" << std::endl;
    scav.attack("Target Dummy");
    scav.takeDamage(30);
    scav.beRepaired(20);

    // 2. Test: Special ScavTrap capacity
    std::cout << "\n--- Special Ability Test ---" << std::endl;
    scav.guardGate();

    std::cout << "\n--- End of Program (Watch destruction order) ---" << std::endl;
    return 0;
}
