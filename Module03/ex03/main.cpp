#include "DiamondTrap.hpp"

int main() {
    // Création d'un objet DiamondTrap avec le nom "Diamond"
    DiamondTrap diamond("Diamond");

    // Affichage des informations sur le DiamondTrap
    diamond.whoAmI();

    // Appel des fonctions héritées de ClapTrap, FragTrap, et ScavTrap

    std::cout << "\n--- Test attack() ---\n";
    diamond.attack("Enemy");

    std::cout << "\n--- Test takeDamage() ---\n";
    diamond.takeDamage(30);

    std::cout << "\n--- Test beRepaired() ---\n";
    diamond.beRepaired(20);

    std::cout << "\n--- Test HighFiveGuys() ---\n";
    diamond.highFivesGuys();

    std::cout << "\n--- Test guardGate() ---\n";
    diamond.guardGate();

    // Test des effets en affichant à chaque fois l'état de l'objet
    std::cout << "\nDiamondTrap final status:\n";
    diamond.whoAmI();

    return 0;
}
