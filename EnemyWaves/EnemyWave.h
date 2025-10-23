#pragma once

#include <iostream>
#include <memory>
#include <queue>

#include "../Character/Player/Player.h"
#include "../Character/Enemy/Enemy.h"

template<typename T>
class EnemyWave
{
public:
    EnemyWave() = default;
;    ~EnemyWave() = default;

    void Status() const
    {
        std::cout << "DEBUG _enemyIndex address: " << &_enemyIndex << std::endl;
        std::cout << "___ Wave [" << (_enemyIndex + 1) << "]" << "___\n";

        for (const std::shared_ptr<T>& enemyPtr : _waveList)
        {
            enemyPtr->Display();
        }
    }
    bool GetNextEnemy() {
        _enemyIndex++;

        if (_waveList.empty())
        {
            OnEmptyWave();
            return false;
        }

        CurrentEnemy = _waveList[_enemyIndex];
        return true;
    }
    bool GroupAttack(const Player& player) const {
        if (_waveList.empty())
            throw std::logic_error("EnemyWave::GroupAttack(): shouldn't be called if wave is empty.");

        for (const T& enemy : _waveList)
        {
            enemy.Attack(player);
        }

        return true;
    }

    void AddEnemyToWave(const T& enemy)
    {
        _waveList.push_back(enemy);
    }

    std::shared_ptr<Enemy> CurrentEnemy;

private:
    void OnEmptyWave() const {
        // TODO
    }

    std::vector<std::shared_ptr<T>> _waveList;
    int _enemyIndex = 0;

    // Illegal → standard container can't store references
    //         → a container of references can't be allocated dynamically.
    // std::unique_ptr<std::queue<Enemy&>> _waveList = std::make_unique<std::queue<Enemy&>>();
};
