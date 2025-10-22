//
// Created by c.boyer on 22/10/2025.
//

#include "Enemy.h"

#include <algorithm>

#include "../Player/Player.h"

void Enemy::Display() const {}

void Enemy::TakeDamage(const int damage)
{
    const int reducedDamage = std::clamp(damage - _defense, 0, damage);

    _hp = std::clamp(_hp - reducedDamage, 0, _hp);
}

void Enemy::Attack(Character &target) const
{
    target.TakeDamage(_strength);
}

bool Enemy::GiveEXP(Player* player) const
{
    if (player == nullptr)
        return false;

    player->GainEXP(_expValue);
    return true;
}
