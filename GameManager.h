//
// Created by c.boyer on 22/10/2025.
//

#pragma once

#include "Character/Player/Player.h"
#include "EnemyWaves/EnemyWave.h"

class Enemy;

class GameManager
{
public:
    explicit GameManager(int initialWaveCount);
    ~GameManager();

    bool AddWave(const EnemyWave<Enemy>& wave);

    void StartGame();
    void PlayerTurn() const;

    void Attack() const;
    void Skip() const;
    void Flee() const;

    std::shared_ptr<Player> Player;
    std::shared_ptr<EnemyWave<Enemy>> CurrentWave;

private:
    std::vector<EnemyWave<Enemy>> _waves;
    int _waveIndex = 0;
};
