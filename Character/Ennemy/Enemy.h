//
// Created by c.boyer on 21/10/2025.
//

#pragma once

#include "../Character.h"

class Enemy: public Character
{

public:
    Enemy(const std::string &name, const int baseHP, const int baseStrength, const int baseDefense)
        : Character{name, baseHP, baseStrength, baseDefense} {}
};
