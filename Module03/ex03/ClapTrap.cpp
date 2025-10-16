#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _name("Default"), _hit_points(10), _energy_points(10), _attack_damage(0)
{
    std::cout << GREEN << "ClapTrap default constructor called" << RESET << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hit_points(10), _energy_points(10), _attack_damage(0)
{
    std::cout << GREEN << "ClapTrap constructor with name called" << RESET << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other)
{
    std::cout << GREEN << "ClapTrap copy constructor called" << RESET << std::endl;
    *this = other;
}

ClapTrap &ClapTrap::operator=(const ClapTrap& other)
{
    std::cout << GREEN << "ClapTrap assignment operator called" << RESET << std::endl;
    this->_name = other._name;
    this->_hit_points = other._hit_points;
    this->_energy_points = other._energy_points;
    this->_attack_damage = other._attack_damage;
    return *this;
}

ClapTrap::~ClapTrap()
{
    std::cout << RED << "ClapTrap destructor called" << RESET << std::endl;
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
    if (_energy_points > 0 && _hit_points > 0)
    {
        _hit_points += amount;
        if (_hit_points > 100)
            _hit_points = 100;
        _energy_points--;
        std::cout << "ClapTrap " << _name << " is repaired for " << amount << " points, new HP: " << _hit_points << "." << std::endl;
    }
}
