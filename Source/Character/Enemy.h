#pragma once

#include "Character.h"

class Enemy: public Character
{
public:
	Enemy() = delete;
	Enemy(const std::string &name, int level, int expValue, int baseHP, int baseStrength, int baseDefense);
	Enemy(const Enemy& copy)
		: Character{copy.Name, copy._level, copy._maxHp, copy._strength, copy._defense}, _expValue(copy._expValue) {}
	~Enemy() override = default;

	void Display() const override;
	void TakeDamage(int damage) override;
	void Attack(Character &target) override;

	int GetExpValue() const { return _expValue; }

private:
	int _expValue;
};