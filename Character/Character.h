//
// Created by c.boyer on 21/10/2025.
//

#pragma once

#include <string>
#include <utility>

class Character
{
public:
    virtual void Display() = 0;
    virtual void TakeDamage(int damage) = 0;
    virtual void Attack(Character &target) = 0;

    std::string Name;

protected:
    Character(std::string name, const int level, const int baseHP, const int baseStrength, const int baseDefense)
    {
        Name = std::move(name);
        _level = level;
        _maxHp = baseHP;
        _hp = _maxHp;
        _strength = baseStrength;
        _defense = baseDefense;
    }
    virtual ~Character() = default;

    int _level;
    int _maxHp;
    int _hp;
    int _strength;
    int _defense;
};
