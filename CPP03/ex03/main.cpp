#include "DiamondTrap.hpp"

int main()
{
    DiamondTrap dia("Aha");
    dia.attack("B");
    std::cout << "kalan : " << dia.getHitPoints()  << std::endl;
}
    