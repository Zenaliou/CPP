#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap("Default_clap_name"), FragTrap(), ScravTrap(), _name("Default")
{
    this->_hit_points = FragTrap::_hit_points;
    this->_energy_points = ScravTrap::_energy_points;
    this->_attack_damage = FragTrap::_attack_damage;
    std::cout << MAGENTA << "DiamondTrap default constructor called" << RESET << std::endl;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "clap_name"), FragTrap(name), ScravTrap(name), _name(name)
{
    this->_hit_points = FragTrap::_hit_points;
    this->_energy_points = ScravTrap::_energy_points;
    this->_attack_damage = FragTrap::_attack_damage;
    std::cout << MAGENTA << "DiamondTrap constructor with name called" << RESET << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& other) : ClapTrap(other), FragTrap(other), ScravTrap(other)
{
    std::cout << MAGENTA << "DiamondTrap copy constructor called" << RESET << std::endl;
    this->_name = other._name;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap& other)
{
    if (this != &other)
    {
        ClapTrap::operator=(other);
        FragTrap::operator=(other);
        ScravTrap::operator=(other);
        this->_name = other._name;
    }
    std::cout << MAGENTA << "DiamondTrap assignment operator called" << RESET << std::endl;
    return *this;
}

DiamondTrap::~DiamondTrap()
{
    std::cout << RED << "DiamondTrap destructor called" << RESET << std::endl;
}

void DiamondTrap::attack(const std::string& target)
{
    ScravTrap::attack(target);
}

void DiamondTrap::whoAmI()
{
    std::cout << "I am DiamondTrap " << this->_name << " and my ClapTrap name is " << ClapTrap::_name << std::endl;
}
