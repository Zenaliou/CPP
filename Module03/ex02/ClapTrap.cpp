#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _name("Default"), _hit_points(10), _energy_points(10), _attack_damage(0)
{
	std::cout << "Default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hit_points(10), _energy_points(10), _attack_damage(0)
{
	std::cout << "Default constructor with name called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other)
{
	std::cout << "Copy construtor called" << std::endl;
	*this = other;
}

ClapTrap &ClapTrap::operator=(const ClapTrap& other)
{
	std::cout << "Copy assignement operator called" << std::endl;
	this->_name = other._name;
	this->_hit_points = other._hit_points;
	this->_energy_points = other._energy_points;
	this->_attack_damage = other._attack_damage;
	return *this;
}

ClapTrap::~ClapTrap()
{
	std::cout << "Destructor called" << std::endl;
}

void ClapTrap::attack(const std::string& target)
{
	if (this->_energy_points > 0 && this->_hit_points > 0)
	{
		std::cout << "ClapTrap " << this->_name << " attack " << target << this->_attack_damage << " damage."<< std::endl;
		this->_energy_points--;
	}
	else if (this->_energy_points == 0)
	{
		std::cout << "ClapTrap " << this->_name << " not able to attack " << target << " no energy point left." << std::endl;
	}
	else
	{
		std::cout << "ClapTrap " << this->_name << " not able to attack " << target << " no hit point left." << std::endl;
	}
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (_hit_points == 0) {
		std::cout << "ClapTrap " << _name << " is already dead and cannot take more damage." << std::endl;
		return;
	}
	if (amount >= _hit_points) {
		std::cout << "ClapTrap " << _name << " takes " << amount << " damage and is now dead." << std::endl;
		_hit_points = 0;
	} else {
		_hit_points -= amount;
		std::cout << "ClapTrap " << _name << " takes " << amount << " damage, new HP: " << _hit_points << "." << std::endl;
	}
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (_hit_points == 0) {
		std::cout << "ClapTrap " << _name << " cannot repair itself, it is dead." << std::endl;
		return;
	}
	if (_energy_points == 0) {
		std::cout << "ClapTrap " << _name << " cannot repair itself, no energy points left." << std::endl;
		return;
	}
	if (_hit_points + amount > 10) {
		std::cout << "ClapTrap " << _name << " cannot have more than 10 hit points." << std::endl;
		return;
	}
	_hit_points += amount;
	_energy_points--;
	std::cout << "ClapTrap " << _name << " repairs itself for " << amount << " hit points, new HP: " << _hit_points << ", energy left: " << _energy_points << "." << std::endl;
}
