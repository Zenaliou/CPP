#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "FragTrap.hpp"
#include "ScravTrap.hpp"

class DiamondTrap : public FragTrap, public ScravTrap
{
	private:
		std::string _name;

	public:
		DiamondTrap();
		DiamondTrap(std::string name);
		DiamondTrap(const DiamondTrap& other);
		~DiamondTrap();

		DiamondTrap &operator=(const DiamondTrap& other);

		void attack(const std::string& target);
		void whoAmI();
};


#endif