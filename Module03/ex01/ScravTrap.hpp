#ifndef SCRAVTRAP_HPP
#define SCRAVTRAP_HPP

#include "ClapTrap.hpp"

class ScravTrap : public ClapTrap
{
	private:
		bool	_guarding_gate;

	public:
		ScravTrap();
		ScravTrap(std::string name);
		ScravTrap(const ScravTrap& other);
		~ScravTrap();

		ScravTrap &operator=(const ScravTrap& other);

		void guardGate();
};

#endif