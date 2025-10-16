#include "ClapTrap.hpp"
#include "ScravTrap.hpp"

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

    std::cout << "\n=== Testing ScravTrap ===" << std::endl;
    ScravTrap s1;
    ScravTrap s2("Makoon");
    
    s1.attack("Eieong");
    s1.takeDamage(30);
    s1.beRepaired(20);
    s1.guardGate();
    s1.guardGate();
    
    s2.attack("Camansou");
    s2.guardGate();
    
    std::cout << "\n=== Testing copy and assignment ===" << std::endl;
    ScravTrap s3(s2);
    ScravTrap s4;
    s4 = s1;

    return (0);
}