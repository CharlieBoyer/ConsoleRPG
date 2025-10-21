//
// Created by c.boyer on 21/10/2025.
//

#pragma once

#include "../Character.h"

class Enemy: public Character
{
public:
    Enemy(const std::string &name, const int level, const int expValue, const int baseHP, const int baseStrength, const int baseDefense)
        : Character{name, level, baseHP, baseStrength, baseDefense}, ExpValue(expValue) {}
    ~Enemy() override = default;

    void Display() override;
    void TakeDamage(int damage) override;
    void Attack(Character &target) override;

    const int ExpValue;
};
