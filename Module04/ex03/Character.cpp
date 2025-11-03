#include "Character.hpp"
#include <iostream>

Character::Character() : _name("default"), _floorCount(0)
{
    for (int i = 0; i < 4; i++)
        _inventory[i] = NULL;
    for (int i = 0; i < 100; i++)
        _floor[i] = NULL;
}

Character::Character(std::string const & name) : _name(name), _floorCount(0)
{
    for (int i = 0; i < 4; i++)
        _inventory[i] = NULL;
    for (int i = 0; i < 100; i++)
        _floor[i] = NULL;
}

Character::Character(const Character& other) : _name(other._name), _floorCount(0)
{
    for (int i = 0; i < 4; i++)
    {
        if (other._inventory[i])
            _inventory[i] = other._inventory[i]->clone();
        else
            _inventory[i] = NULL;
    }
    for (int i = 0; i < 100; i++)
        _floor[i] = NULL;
}

Character& Character::operator=(const Character& other)
{
    if (this != &other)
    {
        _name = other._name;
        for (int i = 0; i < 4; i++)
        {
            if (_inventory[i])
                delete _inventory[i];
            if (other._inventory[i])
                _inventory[i] = other._inventory[i]->clone();
            else
                _inventory[i] = NULL;
        }
    }
    return *this;
}

Character::~Character()
{
    for (int i = 0; i < 4; i++)
    {
        if (_inventory[i])
            delete _inventory[i];
    }
    for (int i = 0; i < _floorCount; i++)
    {
        if (_floor[i])
            delete _floor[i];
    }
}

std::string const & Character::getName() const
{
    return _name;
}

void Character::equip(AMateria* m)
{
    if (!m)
        return;
    
    for (int i = 0; i < 4; i++)
    {
        if (_inventory[i] == NULL)
        {
            _inventory[i] = m;
            return;
        }
    }
}

void Character::unequip(int idx)
{
    if (idx < 0 || idx >= 4 || !_inventory[idx])
        return;
    
    if (_floorCount < 100)
    {
        _floor[_floorCount] = _inventory[idx];
        _floorCount++;
    }
    _inventory[idx] = NULL;
}

void Character::use(int idx, ICharacter& target)
{
    if (idx >= 0 && idx < 4 && _inventory[idx])
    {
        _inventory[idx]->use(target);
    }
}