#include "DiamondTrap.hpp"

int main()
{
    std::cout << "========== CONSTRUCTION TEST ==========" << std::endl;
    DiamondTrap spark("Spark");
    std::cout << std::endl;

    std::cout << "========== STATS CHECK ==========" << std::endl;
    std::cout << "HP: " << spark.getHitPoints() << " (expected: 100 from FragTrap)" << std::endl;
    std::cout << "EP: " << spark.getEnergyPoints() << " (expected: 50 from ScavTrap)" << std::endl;
    std::cout << "AD: " << spark.getAttackDamage() << " (expected: 30 from FragTrap)" << std::endl;
    std::cout << std::endl;

    std::cout << "========== WHO AM I TEST ==========" << std::endl;
    spark.whoAmI();
    std::cout << std::endl;

    std::cout << "========== ATTACK TEST (ScavTrap version) ==========" << std::endl;
    spark.attack("Enemy");
    std::cout << std::endl;

    std::cout << "========== SPECIAL ABILITIES ==========" << std::endl;
    spark.guardGate();
    spark.highFivesGuys();
    std::cout << std::endl;

    std::cout << "========== COPY CONSTRUCTOR TEST ==========" << std::endl;
    DiamondTrap bolt(spark);
    bolt.whoAmI();
    std::cout << std::endl;

    std::cout << "========== ASSIGNMENT OPERATOR TEST ==========" << std::endl;
    DiamondTrap thunder("Thunder");
    std::cout << "Before assignment:" << std::endl;
    thunder.whoAmI();
    thunder = spark;
    std::cout << "After assignment:" << std::endl;
    thunder.whoAmI();
    std::cout << std::endl;

    std::cout << "========== DESTRUCTION TEST ==========" << std::endl;
    return 0;
}
