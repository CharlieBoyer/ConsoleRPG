#include <algorithm>
#include <iostream>

#include "Enemy.h"

Enemy::Enemy(const std::string &name, const int level, const int expValue, const int baseHP, const int baseStrength, const int baseDefense) :
	Character{name, level, baseHP, baseStrength, baseDefense}, _expValue(expValue) {}

void Enemy::Display() const
{
	std::cout << "\t" << Name << " Lv. " << _level << " " <<
		"    HP \u2192 " << _hp << " /" << _maxHp << "\n";
}

void Enemy::TakeDamage(const int damage)
{
	const int reducedDamage = std::clamp(damage - _defense, 0, damage);

	_hp = std::clamp(_hp - reducedDamage, 0, _hp);
}

void Enemy::Attack(Character &target)
{
	target.TakeDamage(_strength);
}

