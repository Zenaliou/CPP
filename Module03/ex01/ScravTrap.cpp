#include "ScravTrap.hpp"

ScravTrap::ScravTrap() : ClapTrap()
{
    this->_hit_points = 100;
    this->_energy_points = 50;
    this->_attack_damage = 20;
    this->_guarding_gate = false;
    std::cout << "ScravTrap default constructor called" << std::endl;
}

ScravTrap::ScravTrap(std::string name) : ClapTrap(name)
{
    this->_hit_points = 100;
    this->_energy_points = 50;
    this->_attack_damage = 20;
    this->_guarding_gate = false;
    std::cout << "ScravTrap constructor with name called" << std::endl;
}

ScravTrap::ScravTrap(const ScravTrap& other) : ClapTrap(other)
{
    std::cout << "ScravTrap copy constructor called" << std::endl;
    this->_guarding_gate = other._guarding_gate;
}

ScravTrap &ScravTrap::operator=(const ScravTrap& other)
{
    if (this != &other)
    {
        ClapTrap::operator=(other);
        this->_guarding_gate = other._guarding_gate;
    }
    std::cout << "ScravTrap assignment operator called" << std::endl;
    return *this;
}

ScravTrap::~ScravTrap()
{
    std::cout << "ScravTrap destructor called" << std::endl;
}

void ScravTrap::attack(const std::string& target)
{
    if (this->_energy_points > 0 && this->_hit_points > 0)
    {
        std::cout << "ScravTrap " << this->_name << " attacks " << target << ", causing " << this->_attack_damage << " points of damage!" << std::endl;
        this->_energy_points--;
    }
    else if (this->_energy_points == 0)
    {
        std::cout << "ScravTrap " << this->_name << " cannot attack " << target << ", no energy points left!" << std::endl;
    }
    else
    {
        std::cout << "ScravTrap " << this->_name << " cannot attack " << target << ", no hit points left!" << std::endl;
    }
}

void ScravTrap::guardGate()
{
    if (this->_guarding_gate)
    {
        std::cout << "ScravTrap " << this->_name << " is no longer guarding the gate." << std::endl;
        this->_guarding_gate = false;
    }
    else
    {
        std::cout << "ScravTrap " << this->_name << " is now in Gate keeper mode!" << std::endl;
        this->_guarding_gate = true;
    }
}
