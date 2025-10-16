#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScravTrap.hpp"
#include "DiamondTrap.hpp"

int main(void)
{
    std::cout << "\n=== Testing DiamondTrap ===" << std::endl;
    DiamondTrap d1;
    DiamondTrap d2("Diamond");
    
    d1.attack("target1");
    d1.takeDamage(50);
    d1.beRepaired(25);
    d1.highFivesGuys();
    d1.guardGate();
    d1.whoAmI();
    
    d2.attack("target2");
    d2.whoAmI();
    
    DiamondTrap d3(d2);
    DiamondTrap d4;
    d4 = d1;

    return (0);
}