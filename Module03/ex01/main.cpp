#include "ClapTrap.hpp"

int main(void)
{
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

	return (0);
}