//
// Created by c.boyer on 21/10/2025.
//

#pragma once

#include <string>
#include <cmath>

#include "Character.h"

class Enemy;

class Player: public Character
{

public:
    explicit Player(const std::string &name);
    ~Player() override = default;

    void Display() override;
    void TakeDamage(int damage) override;
    void Attack(Enemy &target) override;

    void GainEXP(int exp);
    void LevelUp();

private:
    int _exp;
    int _nextLevelExp;

    int GetNextLevelExp() const { return static_cast<int>(std::round(100 * std::pow(1.5, _level))); }
};
