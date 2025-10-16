#include "HumanA.hpp"
#include "HumanB.hpp"
#include "Weapon.hpp"
#include <iostream>

int main()
{
    std::cout << "=== TEST HUMANA (always has weapon) ===" << std::endl;
    {
        std::cout << "\n--- Test 1: HumanA with initial weapon ---" << std::endl;
        Weapon sword("steel sword");
        HumanA alice("Alice", sword);
        alice.attack();
        
        std::cout << "\n--- Test 2: Changing weapon type for HumanA ---" << std::endl;
        sword.setType("enchanted sword");
        alice.attack();
        
        std::cout << "\n--- Test 3: Another HumanA with different weapon ---" << std::endl;
        Weapon bow("elven bow");
        HumanA legolas("Legolas", bow);
        legolas.attack();
        bow.setType("fire bow");
        legolas.attack();
    }

    std::cout << "\n\n=== TEST HUMANB (can be without weapon) ===" << std::endl;
    {
        std::cout << "\n--- Test 1: HumanB without weapon ---" << std::endl;
        HumanB bob("Bob");
        bob.attack();  // Should display that he has no weapon
        
        std::cout << "\n--- Test 2: Giving a weapon to HumanB ---" << std::endl;
        Weapon club("primitive club");
        bob.setWeapon(club);
        bob.attack();
        
        std::cout << "\n--- Test 3: Changing HumanB's weapon type ---" << std::endl;
        club.setType("spiked club");
        bob.attack();
        
        std::cout << "\n--- Test 4: HumanB changes weapon ---" << std::endl;
        Weapon axe("war axe");
        bob.setWeapon(axe);
        bob.attack();
        
        std::cout << "\n--- Test 5: Modifying old weapon (should not affect Bob) ---" << std::endl;
        club.setType("golden club");
        bob.attack();
        
        std::cout << "\n--- Test 6: New HumanB takes the old weapon ---" << std::endl;
        HumanB charlie("Charlie");
        charlie.attack();  // Without weapon
        charlie.setWeapon(club);  // Takes the club
        charlie.attack();
    }

    std::cout << "\n\n=== MULTIPLE WEAPONS TEST ===" << std::endl;
    {
        std::cout << "\n--- Test: Multiple humans with same weapon ---" << std::endl;
        Weapon sharedWeapon("shared weapon");
        
        HumanA warrior1("Warrior1", sharedWeapon);
        HumanB warrior2("Warrior2");
        warrior2.setWeapon(sharedWeapon);
        
        std::cout << "Before change:" << std::endl;
        warrior1.attack();
        warrior2.attack();
        
        std::cout << "\nAfter changing shared weapon:" << std::endl;
        sharedWeapon.setType("legendary weapon");
        warrior1.attack();
        warrior2.attack();
    }

    std::cout << "\n\n=== VARIOUS WEAPON TYPES TEST ===" << std::endl;
    {
        std::cout << "\n--- Test: Different weapon types ---" << std::endl;
        Weapon weapons[] = {
            Weapon("poisoned dagger"),
            Weapon("magic staff"),
            Weapon("ice lance"),
            Weapon("thunder hammer")
        };
        
        HumanB assassin("Assassin");
        for (int i = 0; i < 4; i++) {
            assassin.setWeapon(weapons[i]);
            assassin.attack();
        }
    }
    return (0);
}