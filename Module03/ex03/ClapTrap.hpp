#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>
#include <string>

// Définition des couleurs ANSI
#define RESET   "\033[0m"
#define GREEN   "\033[1;32m"
#define BLUE    "\033[1;34m"
#define CYAN    "\033[1;36m"
#define MAGENTA "\033[1;35m"
#define RED     "\033[1;31m"

class ClapTrap

{
    protected:
        std::string		_name;
        unsigned int	_hit_points;
        unsigned int	_energy_points;
        unsigned int	_attack_damage;

    public:
        ClapTrap();
        ClapTrap(const ClapTrap& other);
        ClapTrap(std::string name);
        ~ClapTrap();

        ClapTrap &operator=(const ClapTrap& other);

        void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);
};

#endif