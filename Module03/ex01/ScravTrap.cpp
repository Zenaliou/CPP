#include "ScravTrap.hpp"

ScravTrap::ScravTrap() : ClapTrap()
{
	this->_hit_points = 100;
	this->_energy_points = 50;
	this->_attack_damage = 20;
	this->_guarding_gate = false;
	std::cout << "Construtor called" << std::endl;
}

ScravTrap::ScravTrap(std::string name) : ClapTrap(name)
{
	this->_hit_points = 100;
	this->_energy_points = 50;
	this->_attack_damage = 20;
	this->_guarding_gate = false;
	std::cout << "Constructor with name called" << std::endl;
}

ScravTrap::ScravTrap(const ScravTrap& other) : ClapTrap(other)
{
	std::cout << "Construtor copy called" << std::endl;
	this->_guarding_gate = other._guarding_gate;
}

ScravTrap &ScravTrap::operator=(const ScravTrap& other)
{
	this->_name = other._name;
	this->_hit_points = other._hit_points;
	this->_energy_points = other._energy_points;
	this->_attack_damage = other._attack_damage;
	this->_guarding_gate = other._guarding_gate;
	std::cout << "Constructor assignement operator called" << std::endl;
}

ScravTrap::~ScravTrap()
{
	std::cout << "Destructor called" << std::endl;
}

void ScravTrap::guardGate()
{

}
