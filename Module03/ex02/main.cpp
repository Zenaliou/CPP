#include "ClapTrap.hpp"
#include "FragTrap.hpp"

int main(void)
{
    std::cout << "=== Testing ClapTrap ===" << std::endl;
    ClapTrap a;
    ClapTrap b("Nico");
    ClapTrap c("Bot");

    a.attack("Nico");
    b.takeDamage(3);
    b.beRepaired(2);
    b.attack("Bot");
    c.takeDamage(5);
    c.beRepaired(4);
    c.attack("Default");
    a.takeDamage(10);
    a.beRepaired(1);

    std::cout << "\n=== Testing FragTrap ===" << std::endl;
    FragTrap f1;
    FragTrap f2("Makoon");
    
    f1.attack("Eieong");
    f1.takeDamage(50);
    f1.beRepaired(25);
    f1.highFivesGuys();
    
    f2.attack("Camansou");
    f2.highFivesGuys();
    
    FragTrap f3(f2);
    FragTrap f4;
    f4 = f1;

    return (0);
}