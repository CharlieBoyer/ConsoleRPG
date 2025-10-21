//
// Created by c.boyer on 21/10/2025.
//

#pragma once

#include <string>
#include <utility>

class Character
{

protected:
    Character(std::string name, const int baseHP, const int baseStrength, const int baseDefense)
    {
        _name = std::move(name);
        _level = 1;
        _hp = baseHP;
        _strength = baseStrength;
        _defense = baseDefense;
    }
    virtual ~Character() = default;

public:
    virtual void Display() = 0;
    virtual void TakeDamage(int damage) = 0;
    virtual void Attack(Character &target) = 0;

protected:
    std::string _name;
    int _level;
    int _hp;
    int _strength;
    int _defense;
};
