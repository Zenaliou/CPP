#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
    this->_hit_points = 100;
    this->_energy_points = 100;
    this->_attack_damage = 30;
    std::cout << BLUE << "FragTrap default constructor called" << RESET << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
    this->_hit_points = 100;
    this->_energy_points = 100;
    this->_attack_damage = 30;
    std::cout << BLUE << "FragTrap constructor with name called" << RESET << std::endl;
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other)
{
    std::cout << BLUE << "FragTrap copy constructor called" << RESET << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap& other)
{
    if (this != &other)
    {
        ClapTrap::operator=(other);
    }
    std::cout << BLUE << "FragTrap assignment operator called" << RESET << std::endl;
    return *this;
}

FragTrap::~FragTrap()
{
    std::cout << RED << "FragTrap destructor called" << RESET << std::endl;
}

void FragTrap::attack(const std::string& target)
{
    if (this->_energy_points > 0 && this->_hit_points > 0)
    {
        std::cout << "FragTrap " << this->_name << " attacks " << target << ", causing " << this->_attack_damage << " points of damage!" << std::endl;
        this->_energy_points--;
    }
    else if (this->_energy_points == 0)
    {
        std::cout << "FragTrap " << this->_name << " cannot attack " << target << ", no energy points left!" << std::endl;
    }
    else
    {
        std::cout << "FragTrap " << this->_name << " cannot attack " << target << ", no hit points left!" << std::endl;
    }
}

void FragTrap::highFivesGuys(void)
{
    std::cout << "FragTrap " << this->_name << " requests a positive high five!" << std::endl;
}