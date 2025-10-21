//
// Created by Charlie on 22/10/2025.
//

#pragma once

#include <memory>
#include <queue>

#include "../Character/Ennemy/Enemy.h"

class EnemyWave
{
public:
    EnemyWave();
    ~EnemyWave();

    std::unique_ptr<Enemy> GetNextEnemy();

    std::queue<std::unique_ptr<Enemy>> _waveList;

    // Illegal → standard container can't store references
    //         → a container of references can't be allocated dynamically.
    // std::unique_ptr<std::queue<Enemy&>> _waveList = std::make_unique<std::queue<Enemy&>>();
};
