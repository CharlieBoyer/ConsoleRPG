//
// Created by c.boyer on 21/10/2025.
//

#pragma once

#include "../Character.h"

class Player;

class Enemy: public Character
{
public:
    Enemy(const std::string &name, const int level, const int expValue, const int baseHP, const int baseStrength, const int baseDefense)
        : Character{name, level, baseHP, baseStrength, baseDefense}, _expValue(expValue) {}
    Enemy(const Enemy& copy)
        : Character{copy.Name, copy._level, copy._maxHp, copy._strength, copy._defense}, _expValue(copy._expValue) {}
    ~Enemy() override = default;

    void Display() const override;

    void TakeDamage(int damage) override;
    void Attack(Character& target) const override;

private:
    bool GiveEXP(Player* player) const;

    const int _expValue;
};


