//
// Created by Charlie on 22/10/2025.
//

#include "EnemyWave.h"


EnemyWave::EnemyWave() = default;

EnemyWave::~EnemyWave() = default;

// TODO: return a reference of the next alive enemy in the wave list. Ask for review.
std::unique_ptr<Enemy> EnemyWave::GetNextEnemy()
{
    if (_waveList.empty())
        return nullptr; // TODO: empty queue --> wave end;

    auto nextEnemy = std::move(_waveList.front());
    _waveList.pop();
    return nextEnemy;
}
